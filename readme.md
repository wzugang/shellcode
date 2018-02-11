
asm to hexcode
--
```
as sh32.asm -o sh32.o
ld sh32.o -o sh32
objdump -d sh32|grep "[0-9a-f]\+:"|awk -F'\t' '{print $2}'|sed "s/ \+$//g" |xargs|sed "s/ /\\\x/g"|sed "s/^/\\\x/g"
or
for i in $(objdump -d sh32 |grep "^ " |cut -f2); do echo -n '\x'$i; done;echo
```

stack frame
---
|pos|argn|real param|
---
|pos|argn-1|real param|
---
|pos|...|real param|
---
|pos|arg1|real param|
---
|pos|return addr|recover need|
---
|pos|previous frame pointer|recover need|
---
stack frame pointer

|neg|local var1|local|
---
|neg|local var2|local|
---
|neg|...|local|
---
|neg|local varn|local|
---
stack top pointer
