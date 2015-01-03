ELF-ARM-HOOK-Library
====================

It's very smali to Substrate. But I give you three methods to do HOOK.

In the utils directory, it includes a TKHooklib.h header file and libTKHooklib.so library.

TK_HookImportFunction: This function is used to hook Import symbol.

TK_HookExportFunction: This function is used to hook Export symbol. It's based on the process of Android linker. So it
just supports Android platform.

TK_InlineHookFunction: This function is used to Inline hook any function. 


If you find any bugs, please send an email to me(ThomakingNew@hotmail.com). You'd better give the assembly and opcode of
the function which you wanna hook. I'll appreciate it.
