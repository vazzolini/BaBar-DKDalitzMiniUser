#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof,atoi

#ex: python significance.py d0k kspipi 100 btdk 10cut

Bmode= sys.argv[1]
Dmode = sys.argv[2]
cut = sys.argv[3]
signame=sys.argv[4]
opt = sys.argv[5]
#PID = sys.argv[4]


BKGS=["uds","ccbar","chb","b0b0bar"]
#SIGS=["btdk"]

LUMI={'lumiuds':778.863,'lumiccbar':868.1107,'lumichb':1288.6582,'lumib0b0bar': 1305.4454}
LUMISIG={'lumibtdk':117608.482, 'lumibtdpi':9767.7880}

lumi0n=425.472
outfile="Sig_Effi_"+Bmode+"_"+Dmode+"_"+cut+"_"+opt+".summary"
fout=open(outfile,"w")

##########################efi

#totsigeff=1076000

#d0pi0
#totsigeff=1330231 
#d0gam
totsigeff=818769


#for SIG in SIGS:
file="./ASCII/btdkpi_"+Bmode+"_"+Dmode+"_"+signame+"_Bbest_Cut"+cut+".dat"
f=open(file,'r')
sigeff = len(f.readlines())
f.close()
eff=atof(sigeff)/totsigeff*100
fout.write("Efi, Channel: "+Bmode+" "+Dmode+" Cut"+cut+":" +str(eff)+"\n\n")
print "Efi, Channel: "+Bmode+" "+Dmode+" Cut"+cut+":" +str(eff)+"\n\n"
####################  SIGNIF  ########

ev=0
bevtot=0

#fout.write("PID Selector: "+PID+"   Channel: "+Bmode+" "+Dmode+" Cut"+cut+"\n\n")
fout.write("Sig,   Channel: "+Bmode+" "+Dmode+" Cut"+cut+"\n\n")

for BKG in BKGS: 

    file="./ASCII/btdkpi_"+Bmode+"_"+Dmode+"_"+BKG+"_Bbest_Cut"+cut+".dat"
    f=open(file,'r')
    bev = len(f.readlines())
    a=lumi0n/LUMI["lumi"+BKG]
    print "ev "+BKG+"= "+str(bev)
    print "lumi= "+str(a)
    bev=bev*a
    f.close()
    print "Number of BKG events rescaled to On lumi("+BKG+")= "+str(bev)
    bevtot=bevtot+bev
    fout.write("Number of BKG events rescaled to On lumi("+BKG+")= "+str(bev)+"\n")

    
print "**********************  Total BKG events= "+str(bevtot)+"\n\n"
fout.write("******  Total BKG events rescaled to On lumi = "+str(bevtot)+"\n")
    
#for SIG in SIGS: 

file="./ASCII/btdkpi_"+Bmode+"_"+Dmode+"_"+signame+"_Bbest_Cut"+cut+".dat"
# print file
f=open(file,'r')
sev = len(f.readlines())
a=lumi0n/LUMISIG["lumi"+signame]
print "ev "+signame+"= "+str(sev)
print "lumi= "+str(a)
sev=sev*a
f.close()

print "Number of SIG events rescaled to On lumi("+signame+")= "+str(sev)
fout.write("*****  Total SIG events rescaled to On lumi("+signame+")= "+str(sev)+"\n")
    
S=sev/math.sqrt(sev+bevtot)
print "Significance= "+str(S)
fout.write("Significance= "+str(S)+" \n\n")

    
        


    












##################
##########           README:  les llistes son string i els index de les llistes han de ser enters, pero aixo atoi(i)
###################
