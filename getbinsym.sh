#!/bin/bash

if [ $# != 2 ] ;then
    echo -e "command invalid :"
    echo -e "\ttips: ./getbinsym.sh binary symbol."
    exit 0
fi

binfile=$1
symbol=$2

startflag=0
endflag=0
objdump -d ${binfile} |while read line
do
    if [ "${line/<${symbol}>:/_}" != "${line}" ] ;then
    #newline=`echo "$line"|sed "s/<main>://"`
    #if [ "${newline}" != "${line}" ] ;then
        startflag=1
    fi
    if test $startflag == 1 ;then
        if [ -z "${line}" ] ;then
            endflag=1
        fi
        if test $endflag == 0 ;then
            echo -e "${line}"
        fi
    fi
done
