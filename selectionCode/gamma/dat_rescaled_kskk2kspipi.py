#! /usr/bin/env python
import math
import os
import sys
from string import atof,atoi
import linecache



#python dat_rescaled_kskk2kspipi.py btdk k
#python dat_rescaled_kskk2kspipi.py btdkstarc kspi
#python dat_rescaled_kskk2kspipi.py btdpi gampi



sigtype=sys.argv[1]
KorPi=sys.argv[2]

tot=0

infile="ASCII/btdkpi_d0"+KorPi+"_kskk_"+sigtype+"_Bbest_Cut114_matchedB_NEW_DALITZ_VARS_reweighted_rb0.125-gamma70-delta180_rec.dat"
#infile="ASCII/btdkstarc_"+KorPi+"_kskk_"+sigtype+"_Bbest_Cut114_matchedB_NEW_DALITZ_VARS_reweighted_rb0.125-gamma70-delta180_rec.dat"
f=open(infile,'r')

tot=len(f.readlines())
print "tot= "+str(tot)

outfile="ASCII/btdkpi_d0"+KorPi+"_kskk_"+sigtype+"_Bbest_Cut114_matchedB_NEW_DALITZ_VARS_reweighted_rb0.125-gamma70-delta180_rescaledtokspipi_rec.dat"
#outfile="ASCII/btdkstarc_"+KorPi+"_kskk_"+sigtype+"_Bbest_Cut114_matchedB_NEW_DALITZ_VARS_reweighted_rb0.125-gamma70-delta180_rescaledtokspipi_rec.dat"
f2=open(outfile,"w")

r=0
a=0
#k
#lumipipi=117608.482
lumipipi=226975.073 #Dst
#lumipipi=387093.7024 #Kst

#pi
#lumipipi=9767.7880
#lumipipi=18192.746


#if KorPi=="k":
#lumi = 745152.355 
lumi=1438420.348 #Dst
#lumi=2452140.191 #Kst

#elif KorPi=="pi":
#lumi = 115246.420 #Dstar
#lumi=61878.199 #DK
    

r=lumipipi/lumi
print "r= "+str(r)
a=tot*r
a=int(a)
print tot
print "a= "+str(a)


for i in range(1,a+1):
    retrieved_line = linecache.getline(infile, i)
    f2.write(retrieved_line)


print "end"
