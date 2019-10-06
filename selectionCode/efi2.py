#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof,atoi


#an-50  per Run              DK  kspipi                                        DK kskk                                              D*Kspipi
#ldel=[["999999","54000","9999999","28000","11000","30000"],["999999","54000","9999999","28000","11000","30000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"],["999999","54000","9999999","28000","11000","30000"],["999999","54000","9999999","28000","11000","30000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"],["999999","105000","9999999","56000","23000","60000"]]
#                       D*K kskk



#an-32 per Run
ldel=[["999999","54000","99999999","83000","252000","333000"],["999999","54000","99999999","83000","252000","333000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"],["999999","54000","999999","83000","252000","335000"],["999999","54000","999999","83000","252000","333000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"],["9999999","105000","999999","165000","506000","664000"]]



run=["1","3","4","5"]



###########          0 d0kpp              1 d0kskk           2 d0pi0k_kspp                    3 d0gamk_kpp            4d0pi0k_kskk                 5d0gamK_kskk
#modes=["btdkpi_d0k_kspipi_btdk","btdkpi_d0k_kskk_btdk","btdkpi_d0pi0k_kspipi_btdsk","btdkpi_d0gamk_kspipi_btdsk","btdkpi_d0pi0k_kskk_btdsk","btdkpi_d0gamk_kskk_btdsk",
 #      "btdkpi_d0pi_kspipi_btdpi","btdkpi_d0pi_kskk_btdpi","btdkpi_d0pi0pi_kspipi_btdspi","btdkpi_d0gampi_kspipi_btdspi","btdkpi_d0pi0pi_kskk_btdspi","btdkpi_d0gampi_kskk_btdspi",]#              6                      7                         8                           9                                 10                          11


modes=["btdkpi_d0k_kspipi_btdk1345","btdkpi_d0k_kskk_btdk1345","btdkpi_d0pi0k_kspipi_btdsk1345","btdkpi_d0gamk_kspipi_btdsk1345","btdkpi_d0pi0k_kskk_btdsk1345","btdkpi_d0gamk_kskk_btdsk1345",
       "btdkpi_d0pi_kspipi_btdpi1345","btdkpi_d0pi_kskk_btdpi1345","btdkpi_d0pi0pi_kspipi_btdspi1345","btdkpi_d0gampi_kspipi_btdspi1345","btdkpi_d0pi0pi_kskk_btdspi1345","btdkpi_d0gampi_kskk_btdspi1345",]#
 


outfile="efi_perRun_an32.summary"
#outfile="efi_perRun_an50.summary"
f2=open(outfile,"w")

f2.write("************** \n")
f2.write(" 0 d0kpp   1 d0kskk    2 d0pi0k_kspp\n 3 d0gamk_kpp   4d0pi0k_kskk  5d0gamK_kskk\n")
f2.write("************** \n\n\n")

for mode in range(0,12):

    print mode
    for i in run:
        
        
        #       file="./an50/"+modes[mode]+i+"_Bbest_Cut100.dat"
        file="./an32/"+modes[mode]+i+"_Bbest_Cut100.dat"
        f=open(file,'r')
        
        #print file
        
        ev = len(f.readlines())
        f.close()
        
        i=atoi(i)

        tot=atof(ldel[mode][i])
        
        if mode==2 or mode==4 or mode==8 or mode==10:
            #d0pi0
            tot=tot*0.619
        elif mode==3 or mode==5 or mode==9 or mode==11:
            #d0gam
            tot=tot*0.381
            
            
        efi=atof(ev)/tot*100
        
        f2.write("Mode "+str(mode)+" Eficiencia, Run"+str(i)+":          "    +str(efi)+"                 ("+str(ev)+","+str(ldel[mode][i])+")\n")
        print "Mode "+str(mode)+" Eficiencia, Run"+str(i)+": ",str(efi),"                 ("+str(ev)+","+str(ldel[mode][i])+")"

    f2.write("************************************************************************************\n")  
        
        


    












##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
