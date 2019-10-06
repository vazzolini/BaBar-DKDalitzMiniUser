#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof,atoi


def rounded(a):
    return "%.0f" % round(a)


def roundthree(a):
    return "%.3f" % round(a,3)





#ex: python taules.py d0k kspipi btdk 

Bmode= sys.argv[1]
Dmode = sys.argv[2]
signame=sys.argv[3]
#opt = sys.argv[5]
#cut = sys.argv[3]

if signame=="btdk" and Dmode=="kspipi":
    MODES=["btdk","b0b0bar","chb","uds","ccbar"]
    LUMI={'lumibtdk':117608.482,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
elif signame=="btdsk" and Dmode=="kspipi":
    MODES=["btdsk","b0b0bar","chb","uds","ccbar"]
    LUMI={'lumibtdsk':226975.073,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
elif signame=="btdk" and Dmode=="kskk":
    MODES=["btdk","b0b0bar","chb","uds","ccbar"]
    LUMI={'lumibtdk':745152.355,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
elif signame=="btdsk" and Dmode=="kskk":
    MODES=["btdsk","b0b0bar","chb","uds","ccbar"]
    LUMI={'lumibtdsk':1438420.348,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}



#Dstar kspipi
if signame=="btdsk" and Dmode=="kspipi":
    CUTS=["100"]
    cut={'100':'cut costhetathrust'}


lumi0n=425.472

outfile="taula_prova.tex"
fout=open(outfile,"w")

ev=0
bevtot=0
sev=0

fout.write("\\begin{table}[htb!]\n \\begin{center}\n {\\small\n \\begin{tabular}{|c|c|c|c|c|c|c|} \\hline\n Selection cuts  & signal  & $B^0\\bar{B^0}$ & $B^+B^-$ & uds & $c\\bar{c}$ & $S$  \\\ \\hline\\hline \n")

for CUT in CUTS:
    sev=0
    bevtot=0
    a=cut[CUT]
    print a
    fout.write(a)
    
    for MODE in MODES:
        file="./ASCII/btdkpi_"+Bmode+"_"+Dmode+"_"+MODE+"_Bbest_Cut"+CUT+".dat"
        print file
        f=open(file,'r')
        bev = len(f.readlines())
        a=lumi0n/LUMI["lumi"+MODE]
        print "ev "+MODE+"= "+str(bev)
        print "lumi= "+str(a)
        bev=bev*a
        f.close()
        rev=rounded(bev)

        #if MODE!="btdk":
        if MODE!=signame:
            bevtot=bevtot+bev
        else:
            sev=bev

        if MODE=="ccbar":
            fout.write("  &  "+rev+"  &  "+str(roundthree(sev/math.sqrt(sev+bevtot)))+" \\\ \n")
        else:
            fout.write("  &  "+rev)
                

        
  #  print "Number of BKG events rescaled to On lumi("+MODE+")= "+str(bev)
 

    
print "**********************  Total BKG events= "+str(bevtot)+"\n\n"
fout.write("\\hline\n \\end{tabular}\n }\n \\caption{\\small Number of $\\Bm  \\to \\Dz \\Km$, \\kspipi\\ selected events for signal and backgrounds in the range $m_{ES}$$>$5.272, appying the cuts in cascade. The number of events is normalized to 425.5 fb$^{-1}$.}\n \\label{tab:selectiondk_kspipi}\n \\end{center}\n \\end{table}\n\n")
    



    






##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
