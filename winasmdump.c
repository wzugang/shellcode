#include <stdio.h>
#include <Windows.h>

int dumphex(unsigned char*buffer)
{
    int begin,end,fill,len;
    goto END ;//略过汇编代码
BEGIN:
    __asm
    {
        //在这里定义任意的合法汇编代码
        jmp esp;
    }
END:
    //确定代码范围
    __asm
    {
        mov eax,BEGIN ;
        mov begin,eax ;
        mov eax,END ;
        mov end,eax ;
    };
    //输出
    len=end-begin;
    memcpy(buffer,(void*)begin,len);
    //四字节对齐
    fill=4-len%4;
    printf("len=%d,fill=%d\n",len,fill);
    while(fill--)buffer[len+fill]=0x90;
    //返回长度
    return ((len+3)/4)*4;
}

int main(int __argc, char* __argv[])
{
    int i,len;
    int cr0 = 5;
    unsigned char buffer[1024]={0};
    void* fun;
    FILE* fp;
    HINSTANCE LibHandle;

    len = dumpCode(buffer);
    printf("%d\n",len);
    
    fp = fopen("hex.txt","wb+");
    for (i = 0; i < len; i++)
    {
        fprintf(fp,"\\x%x",buffer[i]);
    }
    printf("\n");
    fclose(fp);
    
    return 0;
}


    
