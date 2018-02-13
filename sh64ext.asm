.section .data
shell:
.string "/bin/sh"
.section .text
.globl _start
_start:
    jmp start
shellcode:
    push    %rbp
    mov     %rsp,%rbp
    sub     $0x10,%rsp
    xor     %rdx,%rdx
    movq    $shell,-0x10(%rbp)
    mov     %rdx,-0x8(%rbp)
    mov     -0x10(%rbp),%rax
    lea     -0x10(%rbp),%rcx
    mov     %rcx,%rsi
    mov     %rax,%rdi
    mov     $0x3b,%eax
    syscall
    leaveq
    retq
start:
    jmp shellcode
