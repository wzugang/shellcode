
asm to hexcode
--
```
as sh32.asm -o sh32.o
ld sh32.o -o sh32
objdump -d sh32|grep "[0-9a-f]\+:"|awk -F'\t' '{print $2}'|sed "s/ \+$//g" |xargs|sed "s/ /\\\x/g"|sed "s/^/\\\x/g"
or
for i in $(objdump -d sh32 |grep "^ " |cut -f2); do echo -n '\x'$i; done;echo
```
