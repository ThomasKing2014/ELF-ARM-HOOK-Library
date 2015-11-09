ELF-ARM-HOOK-Library
====================

It's very similar to Substrate. But I give you three methods to do HOOK.

In the utils directory, it includes a TKHooklib.h header file and libTKHooklib.so library.

TK_HookImportFunction: This function is used to hook Import symbol.

TK_HookExportFunction: This function is used to hook Export symbol. It's based on the process of Android linker. So it
just supports Android platform.

TK_InlineHookFunction: This function is used to Inline hook any function. 


If you find any bugs, please send an email to me(ThomaskingNew@hotmail.com). You'd better give the assembly and opcode of
the function which you wanna hook. I'll appreciate it.

---
Firstly, I appreciate that some users send bugs to me. Based on the bugs and some special cases, I provide a new InlineHook Bridge.

Also, I provide the beta version of AARCH64(armv8) Inline hook library. It only supports AARCH_64 instruction. By the way, you should flush the cache by yourself. Except the instructions, the syscall is the same with arm.

Thanks for your bug reports again.

-- Thomas King