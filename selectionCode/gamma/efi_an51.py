#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof,atoi


#DK kspipi & Kskk  and DPi
ldel=[["999999","54000","156000","83000","252000","333000","198000"],["999999","54000","156000","83000","252000","333000","198000"]]

#DK*   and DPid
#ldel =[["9999999","105000","314000","165000","506000","664000","395000"],["9999999","105000","314000","165000","506000","664000","395000"],["9999999","105000","314000","165000","506000","664000","395000"],["9999999","105000","314000","165000","506000","664000","395000"]]





run=["1","2","3","4","5","6"]

modes=["btdkpi_d0k_kspipi_btdk","btdkpi_d0k_kskk_btdk"]
#modes=["btdkpi_d0pi0k_kspipi_btdsk","btdkpi_d0gamk_kspipi_btdsk","btdkpi_d0pi0k_kskk_btdsk","btdkpi_d0gamk_kskk_btdsk"]


#modes=["btdkpi_d0pi_kspipi_btdpi","btdkpi_d0pi_kskk_btdpi"]
#modes =["btdkpi_d0pi0pi_kspipi_btdspi","btdkpi_d0gampi_kspipi_btdspi","btdkpi_d0pi0pi_kskk_btdspi","btdkpi_d0gampi_kskk_btdspi",]


outfile="efi_rel24_3_6.summary"
f2=open(outfile,"w")


for mode in range(0,2):
#for mode in range(0,4):

    print modes[mode]
    for i in run:
        
        
        file="./ASCII/"+modes[mode]+i+"_Bbest_Cut100.dat"
        f=open(file,'r')
        
        ev = len(f.readlines())
        f.close()
        
        i=atoi(i)

        tot=atof(ldel[mode][i])

      #  if mode==0 or mode==2 :
            #d0pi0
      #     tot=tot*0.619
      #  elif mode==1 or mode==3:
            #d0gam
      #      tot=tot*0.381

            
        efi=atof(ev)/tot*100
            
        f2.write("Mode "+str(modes[mode])+" , Eficiencia, Run"+str(i)+":          "    +str(efi)+"                 ("+str(ev)+","+str(ldel[mode][i])+")\n")
        print "Mode "+str(mode)+" Eficiencia, Run"+str(i)+": ",str(efi),"                 ("+str(ev)+","+str(ldel[mode][i])+")"
            
        f2.write("************************************************************************************\n")  
        
        


    












##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
