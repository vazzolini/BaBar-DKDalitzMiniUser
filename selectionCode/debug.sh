#!/bin/sh
line=`ps -wwfu $USER | grep root.exe | grep -v grep | tail -1`
if [ $line == "" ] ; then
  echo "No ROOT session running"
  exit 1
fi
echo "ROOT session running"
set $line
exec gdb $8 $2

