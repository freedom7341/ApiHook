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

/* Function Prototypes */
__declspec(dllexport) BOOL CALLBACK InstallUserHook();
BOOL WINAPI RegisterUserApiHookDelay(PUSERAPIHOOKINFO ApiHookInfo);
BOOL WINAPI UnregisterUserApiHookDelay(VOID);
