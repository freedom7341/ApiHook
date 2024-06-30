/* * * * * * * *\
	LAUNCH.C -
		Copyright © 2024 Brady McDermott
	DESCRIPTION -
		ApiHook launcher program.
	LICENSE INFORMATION -
		MIT License, see LICENSE.txt in the root folder
\* * * * * * * */

/* Includes */
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* Functions */

/* * * *\
	DllMain -
		The application's entry point
\* * * */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HMODULE hLib = LoadLibrary(L"ApiHook.dll");
	BOOL bRet = 0;

    OutputDebugString(L"Starting ApiHook...\n");

	// Call ApiHook's initialization function
	if (hLib)
	{
		FARPROC fLib = GetProcAddress(hLib, "InstallUserHook");

		bRet = (BOOL)fLib();

		FreeLibrary(hLib);
		FreeConsole();

		return bRet;
	}
	else
	{
		OutputDebugString(L"ApiHook not found!\n");
		FreeConsole();
		return -1;
	}

	FreeConsole();

	return 0;
}