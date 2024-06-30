/* * * * * * * *\
	MAIN.C -
		Copyright © 2024 Brady McDermott
	DESCRIPTION -
		User32 UserApiHook testing program.
	LICENSE INFORMATION -
		MIT License, see LICENSE.txt in the root folder
\* * * * * * * */

/* Includes */
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "usrapihk.h"
#include "main.h"

/* * * *\
	DllMain -
		NT Style Hook's entry point
\* * * */
BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// Call InstallUserHook
		InstallUserHook();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

/* * * *\
	InstallUserHook -
		Load the User32 API hook.
\* * * */
__declspec(dllexport) BOOL CALLBACK InstallUserHook()
{
	USERAPIHOOKINFO uah;

	MessageBox(NULL, L"InstallUserHook called", L"Cascades", MB_OK);

	uah.m_funname1 = L"InitUserHook";
	uah.m_dllname1 = L"ApiHook.dll";
	uah.m_funname2 = L"InitUserHook";
	uah.m_dllname2 = L"ApiHook.dll";

	return RegisterUserApiHookDelay(&uah);
}

/* * * *\
	RegisterUserApiHookDelay -
		Run the User32 API hook.
\* * * */
BOOL WINAPI RegisterUserApiHookDelay(PUSERAPIHOOKINFO ApiHookInfo)
{
	HMODULE hLib = LoadLibrary(L"user32.dll");
	BOOL bRet = 0;

	if (hLib)
	{
		FARPROC fLib = GetProcAddress(hLib, "RegisterUserApiHookDelay");

		bRet = (BOOL)fLib(ApiHookInfo);

		FreeLibrary(hLib);

		return bRet;
	}

	return FALSE;
}

/* * * *\
	UnregisterUserApiHookDelay -
		Unregisters a DLL from User32.
	RETURNS -
		TRUE if successful.
\* * * */
BOOL WINAPI UnregisterUserApiHookDelay(VOID)
{
	HMODULE hLib = LoadLibrary(L"user32.dll");
	BOOL bRet = 0;

	if (hLib)
	{
		FARPROC fLib = GetProcAddress(hLib, "UnregisterUserApiHook");

		bRet = (BOOL)fLib();

		FreeLibrary(hLib);

		return bRet;
	}

	return FALSE;
}
