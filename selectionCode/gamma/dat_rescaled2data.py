#! /usr/bin/env python
import math
import os
import sys
from string import atof,atoi
import linecache



#python dat_rescaled2data.py btdk k



sigtype=sys.argv[1]
KorPi=sys.argv[2]

tot=0

infile="ASCII/btdkpi_d0"+KorPi+"_kspipi_"+sigtype+"_Bbest_Cut112.dat"
f=open(infile,'r')

tot=len(f.readlines())
print "tot= "+str(tot)

outfile="ASCII/btdkpi_d0"+KorPi+"_kspipi_"+sigtype+"_Bbest_Cut112_rescaledtodata.dat"
f2=open(outfile,"w")

r=0
a=0
lumidata=425.5



if KorPi=="k":
    lumi = 117608.482
elif KorPi=="pi":
    lumi =9767.7880
elif sigtype=="chb":
    lumi=1288.65
elif sigtype=="b0b0bar":
    lumi=1305.44
elif sigtype=="ccbar":
    lumi=868.11
elif sigtype=="uds":
    lumi=778.86
elif sigtype=="chbk":
    lumi=1288.65
elif sigtype=="chbpi":
    lumi=1288.65

r=lumidata/lumi
print "r= "+str(r)
a=tot*r
a=int(a)
print tot
print "a= "+str(a)


for i in range(1,a+1):
    retrieved_line = linecache.getline(infile, i)
    f2.write(retrieved_line)


print "end"
