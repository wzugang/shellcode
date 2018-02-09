
asm to hexcode

as shasm32.asm -o shasm32.o
ld shasm32.o -o shasm32
objdump -d shasm32|grep "[0-9a-f]\+:"|awk -F'\t' '{print $2}'|sed "s/ \+$//g" |xargs|sed "s/ /\\\x/g"|sed "s/^/\\\x/g"

