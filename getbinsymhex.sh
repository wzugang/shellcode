#!/bin/bash

if [ $# != 2 ] ;then
    echo -e "command invalid :"
    echo -e "\ttips: ./getbinsymhex.sh binary symbol."
    exit 0
fi

binfile=$1
symbol=$2

startflag=0
endflag=0

objdump -d ${binfile} |while read line
do
    if [ "${line/<${symbol}>:/_}" != "${line}" ] ;then
        startflag=1
    else
        if test $startflag == 1 ;then
            if [ -z "${line}" ] ;then
                endflag=1
            fi
            if test $endflag == 0 ;then
                for hex in `echo -e "${line}"|cut -f2`
                do
                    echo -n '\x'$hex
                done
            fi
        fi
    fi
done
echo
