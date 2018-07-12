```

0-63 0-31  0-15   8-15  0-7   使用惯例
%rax %eax  %ax    %ah   %al   保存返回值
%rbx %ebx  %bx    %bh   %bl   被调用者保存
%rcx %ecx  %cx    %ch   %cl   第4个参数
%rdx %edx  %dx    %dh   %dl   第3个参数
%rsi %esi  %si    无    %sil  第2个参数
%rdi %edi  %di    无    %dil  第1个参数
%rbp %ebp  %bp    无    %bpl  被调用者保存
%rsp %esp  %sp    无    %spl  栈指针
%r8  %r8d  %r8w   无    %r8b  第5个参数
%r9  %r9d  %r9w   无    %r9b  第6个参数
%r10 %r10d %r10w  无    %r10b 调用者保存
%r11 %r11d %r11w  无    %r11b 调用者保存
%r12 %r12d %r12w  无    %r12b 被调用者保存
%r13 %r13d %r13w  无    %r13b 被调用者保存
%r14 %r14d %r14w  无    %r14b 被调用者保存
%r15 %r15d %r15w  无    %r15b 被调用者保存

```
