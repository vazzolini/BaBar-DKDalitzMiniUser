#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof,atoi


#DK kspipi & Kskk  and DPi
ldel=[["999999","54000","156000","83000","252000","333000","198000"],["999999","54000","156000","83000","252000","333000","198000"]]


modes=["btdkpi_d0k_kspipi_btdk","btdkpi_d0k_kskk_btdk"]

outfile="efi.summary"
f2=open(outfile,"w")


for mode in range(0,2):

    print modes[mode]
        
    file="./ASCII/"+modes[mode]+i+"_Bbest_Cut100.dat"
    f=open(file,'r')
    
    ev = len(f.readlines())
    f.close()
    
    i=atoi(i)
    
    tot=atof(ldel[mode][i])
    efi=atof(ev)/tot*100
    
    f2.write("Mode "+str(modes[mode])+" , Eficiencia, Run"+str(i)+":          "    +str(efi)+"                 ("+str(ev)+","+str(ldel[mode][i])+")\n")
    print "Mode "+str(mode)+" Eficiencia, Run"+str(i)+": ",str(efi),"                 ("+str(ev)+","+str(ldel[mode][i])+")"
    
    f2.write("************************************************************************************\n")  
    
        


    












##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
