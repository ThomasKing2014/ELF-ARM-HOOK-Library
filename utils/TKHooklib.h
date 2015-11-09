#ifndef _TKHOOKLIB_H
#define _TKHOOKLIB_H

#define SOINFO_NAME_LEN 128

#define HOOK_SUCCESS 0
#define HOOK_FAILED -1

typedef struct _HookStruct{
	char SOName[SOINFO_NAME_LEN];
	char FunctionName[SOINFO_NAME_LEN];
	void *NewFunc;
	void *OldFunc;
	void *occPlace;
}HookStruct;

#ifdef __cplusplus
extern "C" {
#endif

void TK_UnHookExportFunction(HookStruct *pHookStruct);

void TK_UnHookImportFunction(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Hook libfoo.so Import Function: puts
**	HookStruct HookPara;
**  strncpy(HookPara.SOName, "libfoo.so", strlen("libfoo.so"));
**	strncpy(HookPara.FunctionName, "puts", strlen("puts"));
**	HookPara.NewFunc = myputs;
**	TK_HookImportFunction(&HookPara);
*/
int TK_HookImportFunction(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Hook libc.so Export Function: puts
**	HookStruct HookPara;
**  strncpy(HookPara.SOName, "libc.so", strlen("libc.so"));
**	strncpy(HookPara.FunctionName, "puts", strlen("puts"));
**	HookPara.NewFunc = myputs;
**	TK_HookExportFunction(&HookPara);
*/
int TK_HookExportFunction(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Inline Hook libc.so Function: puts
**	void* OldFunc = NULL;
**	TK_InlineHookFunction(puts, myputs, &OldFunc);
**	----------------------------------------------
** 	For the new implementation of HOOK Bridge, I suggest you add some lock to enhance the stability.
**		
**		
		int myputs(const char *string){
			// Do sth before calling ori-function

			pthread_mutex_lock(&hook_mutex);
			puts(string);
			pthread_mutex_unlock(&hook_mutex);
			
			// Do sth after calling ori-function
		}
**	
*/
int TK_InlineHookFunction(void *TargetFunc, void *NewFunc, void** OldFunc);

#ifdef __cplusplus
};
#endif

#endif
