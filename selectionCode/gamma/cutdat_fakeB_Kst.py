#! /usr/bin/env python
import math
import os
import sys
from string import atof,atoi
import linecache


d0mode=sys.argv[1]
fake = sys.argv[2]

#python cutdat_fakeB_Kst.py  kspipi fakeBfakeD

if d0mode=="kspipi":
    lumi_sig=387093.7024;
elif d0mode=="kskk":  
    lumi_sig=2452140.191;


file="./ASCII/btdkstarc_kspi_"+d0mode+"_btdkstarc_Bbest_Cut112_"+fake+".dat"
f=open(file,'r')

print file
tot=len(f.readlines())
print "tot= "+str(tot)



file2="./ASCII_rescaled/btdkstarc_kspi_"+d0mode+"_btdkstarc_Bbest_Cut112_"+fake+"_rescaled2BB.dat"
outfile=file2
f2=open(outfile,"w")

r=0
a=0
lumiBB=1305.4


r=lumiBB/lumi_sig
print "r= "+str(r)
a=tot*r
a=int(a)
print "a= "+str(a)


for i in range(1,a+1):
  #  print "hola"
    retrieved_line = linecache.getline(file, i)
    f2.write(retrieved_line)


print "end"
