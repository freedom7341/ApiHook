/* * * * * * * *\
	MAIN.H -
		Copyright © 2024 Brady McDermott
	DESCRIPTION -
		User32 UserApiHook testing program.
	LICENSE INFORMATION -
		MIT License, see LICENSE.txt in the root folder
\* * * * * * * */

/* Pragmas */
#pragma once

/* Global Variables */
extern USERAPIHOOK g_user32ApiHook;
extern BYTE gabDWPmessages[UAHOWP_MAX_SIZE];
extern BYTE gabMSGPmessages[UAHOWP_MAX_SIZE];
extern BYTE gabDLGPmessages[UAHOWP_MAX_SIZE];
extern BOOL g_bThemeHooksActive;

/* Function Prototypes */
__declspec(dllexport) BOOL CALLBACK InstallUserHook();
__declspec(dllexport) BOOL CALLBACK InitUserHook(UAPIHK State, PUSERAPIHOOK puah);
BOOL WINAPI RegisterUserApiHookDelay(HINSTANCE hInstance, PUSERAPIHOOKINFO ApiHookInfo);
BOOL WINAPI UnregisterUserApiHookDelay(VOID);
