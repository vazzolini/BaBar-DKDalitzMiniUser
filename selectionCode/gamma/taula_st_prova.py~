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





#ex: python taula_st.py kspi kspipi btdkstarc

Bmode= sys.argv[1]
Dmode = sys.argv[2]
signame=sys.argv[3]
#opt = sys.argv[5]
#cut = sys.argv[3]

MODES=["btdkstarc","b0b0bar","chb","uds","ccbar"]
if signame=="btdkstarc" and Dmode=="kspipi":
    LUMI={'lumibtdkstarc':387093.7024,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
    CUTS=["0","101","102","104","105","106","107","108","109","110","111","112","113","114"]
    cut={'0':'pre-selection','101':'$|M_{\\KS}(D^0)-M_{\\KS}(PDG)|<$9 \\mev','102':'$|M_{D^0}-M_{D^0}(PDG)|<$12 \\mev','104': '$P(\chi^2,D^0)>$0.','105':'$\\cos(\\alpha_{\\KS}(D^0))>0.99$', '106':'$P(\chi^2,B)>$0.','107':'$|m_{\\KS}(K^*)-m_{\\KS}(PDG)|<9$~\mev','108':'$\\cos(\\alpha_{\\KS}(K^*))>0.997$~\mev','109':'$|m_{K^*}-m_{K^*}(PDG)|<55$~\mev ','110':'$|\\cos(\\theta_{hel})|>0.35$','111':'Decay Length Sig.$<10$','112':'\\fish >-0.1','113':'$|\Delta E|<$ 30 \\mev','114':'$\m_{ES}>$ 5.272 \\gev'}
elif signame=="btdkstarc" and Dmode=="kskk":
    LUMI={'lumibtdkstarc':2452140.191,'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
    CUTS=["0","101","102","103","104","105","106","107","108","109","110","111","112","113","114"]
    cut={'0':'pre-selection','101':'$|M_{\\KS}(D^0)-M_{\\KS}(PDG)|<$9 \\mev','102':'$|M_{D^0}-M_{D^0}(PDG)|<$12 \\mev','103':'\Dz track Kaon ID','104': '$P(\chi^2,D^0)>$0.','105':'$\\cos(\\alpha_{\\KS}(D^0))>0.99$', '106':'$P(\chi^2,B)>$0.','107':'$|m_{\\KS}(K^*)-m_{\\KS}(PDG)|<9$~\mev','108':'$\\cos(\\alpha_{\\KS}(K^*))>0.997$~\mev','109':'$|m_{K^*}-m_{K^*}(PDG)|<55$~\mev ','110':'$|\\cos(\\theta_{hel})|>0.35$','111':'Decay Length Sig.$<10$','112':'\\fish >-0.1','113':'$|\Delta E|<$ 30 \\mev','114':'$\m_{ES}>$ 5.272 \\gev'}




lumi0n=425.472

outfile="taula_st.tex"
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
        file="./ASCII/btdkstarc_"+Bmode+"_"+Dmode+"_"+MODE+"_Bbest_Cut"+CUT+".dat"
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
