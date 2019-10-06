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

def roundfour(a):
    return "%.4f" % round(a,4)

def roundfive(a):
    return "%.5f" % round(a,5)


KorPi= sys.argv[1]


#ex: python CPtaula.py 




if KorPi=="k":
    entry=['\\btdzk,\\kspipi','\\btdzk,\\kskk','\\btdsk,\\dzpiz,\\kspipi','\\btdsk,\\dzpiz,\\kskk','\\btdsk,\\dzgam,\\kspipi','\\btdsk,\\dzgam,\\kskk','\\btdks,\\kspipi','\\btdks,\\kskk']
    entries={'\\btdzk,\\kspipi': 'DK;KsPiPi', '\\btdzk,\\kskk': 'DK;KsKK', '\\btdsk,\\dzpiz,\\kspipi': 'Dpi0K;KsPiPi','\\btdsk,\\dzpiz,\\kskk':'Dpi0K;KsKK', '\\btdsk,\\dzgam,\\kspipi': 'DgammaK;KsPiPi', '\\btdsk,\\dzgam,\\kskk':'DgammaK;KsKK', '\\btdks,\\kspipi': 'DKspi;KsPiPi', '\\btdks,\\kskk': 'DKspi;KsKK'}
    coordinates=["reM_DK","reM_Dpi0K","reM_DKspi","imM_DK","imM_Dpi0K","imM_DKspi","reP_DK","reP_Dpi0K","reP_DKspi","imP_DK","imP_Dpi0K","imP_DKspi"]
    samples=["nSig","asymSig","nBB","nCont","nDh"]
elif KorPi=="pi":
    entry=['\\btdzp,\\kspipi','\\btdzp,\\kskk','\\btdsp,\\dzpiz,\\kspipi','\\btdsp,\dzpiz,\kskk','\\btdsp,\dzgam,\kspipi','\\btdsp,\dzgam,\kskk']
    entries={'\\btdzp,\\kspipi': 'DPi;KsPiPi', '\\btdzp,\\kskk' : 'DPi;KsKK', '\\btdsp,\\dzpiz,\\kspipi': 'Dpi0Pi;KsPiPi','\\btdsp,\\dzpiz,\\kskk':'Dpi0Pi;KsKK', '\\btdsp,\\dzgam,\\kspipi': 'DgammaPi;KsPiPi', '\\btdsp,\\dzgam,\\kskk':'DgammaPi;KsKK'}
    coordinates=["reMDh_DPi","reMDh_Dpi0Pi","imMDh_DPi","imMDh_Dpi0Pi","rePDh_DPi","rePDh_Dpi0Pi","imPDh_DPi","imPDh_Dpi0Pi"]
    samples=["nDh","asymDh","nBB","nCont","nSig"]



outfile="CPtaula_dpi_good.tex"
fout=open(outfile,"w")

file="d0pi_Dalitz.results2"
#file="d0k_Dalitz-Run15.results2"
#file="d0k_Dalitz-bl.results2"
#file="d0pi_KsKK-Dalitz.results"
#file="d0k_KsPiPi-Dalitz-bl.results"
#file="d0k_KsKK-Dalitz-bl.results"
#file="d0k_KsPiPi-Dalitz-Run15.results"
#file="d0k_KsKK-Dalitz-Run15.results"



fout.write("\\begin{table}[htb]]\n \\begin{center}\n {\small\n \\begin{tabular}{l|c|c|c|c|c} \\hline\n Decay modes & $N_\\sig$   & $A_\\sig$  & $N_\\bb$   & $N_\\cont$       &     $N_\\dh$ $(N_{DK})$ \\\ \n \\hline \\hline\n")



print file
f=open(file,'r')
lines = f.readlines()
b=0

for entr in entry:
    b=entries[entr]
    print b
    fout.write(entr)
    
    for sample in samples:
        for line in lines:
            a=line.find(entries[entr])
            if a!=-1:
                b=line.find(sample)
                if b!=-1:
                    lineVect=line.split(' ');
                    print lineVect[3]
                    c=lineVect[3]
                    if sample=="asymDh":
                        if c =="+/-":
                            fout.write("  &  "+str(roundthree(float(lineVect[2])))+"$\pm$ "+str(roundthree(float(lineVect[4])))+" ")                        
                        else:
                            fout.write("  &  "+str(roundthree(float(lineVect[3])))+"$\pm$ "+str(roundthree(float(lineVect[5])))+" ")
                    else:
                        if c =="+/-":
                            fout.write("  &  "+str(int(float(lineVect[2])))+"$\pm$ "+str(int(float(lineVect[4])))+" ")                        
                        else:
                            fout.write("  &  "+str(int(float(lineVect[3])))+"$\pm$ "+str(int(float(lineVect[5])))+" ")



    fout.write("\\\ \n")
                          
                    

    
fout.write("\n \\hline\n \\end{tabular}\n } \\caption{\\small \\btdp yields as obtained from the control \\CP fit using Run1-Run5 data sample.} \n \\label{tab:yieldsCP_DPi}\n \\end{center} \n \\end{table} \n\n")

fout.write("--------------------------------------------------------------------------------------------------\n\n\n\n")





fout.write("\\begin{table}[htb!]\n \\begin{center}\n \\begin{tabular}{c|c|c|c} \n \\hline \n Observable & \\btdzk  & \\btdsk  & \\btdks    \\\ \n \\hline \\hline & \\multicolumn{3}{|c}{\\kspipi and \\kskk combined fit} \\\ \n")




print "CP coor!"


for coor in coordinates:
    for line in lines:
        b=line.find(coor)
        if b!=-1:
           # fout.write("$x_-$")
            lineVect=line.split(' ')
            c=lineVect[3]
            print lineVect[3]

            if KorPi=="k":
                x=coor.find("DKspi")
                if x!=-1:
                    if c =="+/-":
                        fout.write("  &  "+roundfive(float(lineVect[2]))+"$\pm$ "+roundfive(float(lineVect[4]))+" \\\ \n")
                        break
                    else:
                        fout.write("  &  "+roundfive(float(lineVect[3]))+"$\pm$ "+roundfive(float(lineVect[5]))+" \\\ \n")
                        break
                else:
                    if c =="+/-":
                        fout.write("  &  "+roundfive(float(lineVect[2]))+"$\pm$ "+roundfive(float(lineVect[4]))+" ")
                        break
                    else:
                        fout.write("  &  "+roundfive(float(lineVect[3]))+"$\pm$ "+roundfive(float(lineVect[5]))+" ")
                        break
            elif KorPi=="pi":
                x=coor.find("Dpi0Pi")
                if x!=-1:
                    if c =="+/-":
                        fout.write("  &  "+roundfive(float(lineVect[2]))+"$\pm$ "+roundfive(float(lineVect[4]))+" \\\ \n")
                        break
                    else:
                        fout.write("  &  "+roundfive(float(lineVect[3]))+"$\pm$ "+roundfive(float(lineVect[5]))+" \\\ \n")
                        break
                else:
                    if c =="+/-":
                        fout.write("  &  "+roundfive(float(lineVect[2]))+"$\pm$ "+roundfive(float(lineVect[4]))+" ")
                        break
                    else:
                        fout.write("  &  "+roundfive(float(lineVect[3]))+"$\pm$ "+roundfive(float(lineVect[5]))+" ")
                        break
                        




fout.write("\n \\hline \n \\end{tabular} \n \\end{center}\n \\caption{\\small Unblind fit results for $x^{(*)}_\\mp$, $y^{(*)}_\\mp$, $x_{s\\mp}$ and $y_{s\\mp}$ as obtained from the nominal \\CP fit using the Run1-Run5 data sample, for the \\btdzk, \\btdsk and \\btdks decay modes.\n \\label{tab:cartesian_results_DK_unblind}}\n \\end{table}\n")

f.close()
                




##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
