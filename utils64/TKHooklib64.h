#ifndef _TKHOOKLIB_H
#define _TKHOOKLIB_H

#define HOOK_SUCCESS 0
#define HOOK_FAILED -1

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Inline Hook libc.so Function: puts
**	void* OldFunc = NULL;
**	TK_InlineHookFunction(puts, myputs, &OldFunc);
**  
** 	Notice: You should flush the cache by yourself.
*/
int TK_InlineHookFunction(void *TargetFunc, void *NewFunc, void** OldFunc);

#ifdef __cplusplus
};
#endif

#endif
