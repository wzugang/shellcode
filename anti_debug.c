#include <stdio.h>
#include <string.h>
#include "windows.h"
bool IsDebuggerPresent() 
{ 
    HMODULE hKernelBaseDll = ::LoadLibrary(TEXT("kernelBase.dll")); 
    if (NULL != hKernelBaseDll) 
    { 
        // 不要使用kernel32，kernel32中IsDebuggerPresent第一条指令并非x64 
        FARPROC pIsDebuggerPresent = ::GetProcAddress(hKernelBaseDll, "IsDebuggerPresent"); 
        if (!pIsDebuggerPresent) 
        { 
            ::FreeLibrary(hKernelBaseDll); 
            return false; 
        } 
        if ((*(BYTE *)pIsDebuggerPresent == 0xCC) 
            ||(*(BYTE *)pIsDebuggerPresent != 0x64) 
            || pIsDebuggerPresent() 
            ) 
        { 
            ::FreeLibrary(hKernelBaseDll); 
            return true; 
        } 
        else 
        { 
            ::FreeLibrary(hKernelBaseDll); 
            return false; 
        } 
    } 
    return false; 
} 
int main()
{
    if (IsDebuggerPresent())
    {
        printf("警报！警报！有调试器！\n");
        return 1;
    }
    printf("你不是调试器，可以通过~\n");
    while(1)
    {
        if (IsDebuggerPresent())
        {
            printf("警报！警报！有调试器！\n");
            return 1;
        }
        _sleep(1);
    }
    return 0;
}
