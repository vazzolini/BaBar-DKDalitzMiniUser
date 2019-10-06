#! /usr/bin/env python
import math
import os
import sys
from string import atof,atoi
import linecache

#outfile="debug_d0gamk_kspipi.dat"
outfile="debug_d0gampi_kspipi.dat"
f2=open(outfile,"w")

#file="./debug/btdkpi_d0gamk_kspipi_btdsk_Bbest_Cut112.dat"
file="./debug/btdkpi_d0gampi_kspipi_btdspi_Bbest_Cut112.dat"
f=open(file,'r')


for i in range(1,50000):
    retrieved_line = linecache.getline(file, i)
    f2.write(retrieved_line)


print "end"
