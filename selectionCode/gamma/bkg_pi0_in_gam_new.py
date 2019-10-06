#! /usr/bin/env python

import sys
import os

#bsub -q kanga -J nopi0 -o ASCII/nopi0_kskk_fotons.log python bkg_pi0_in_gam_new.py


#file="./ASCII/bkg_MC_d0gamk_kspipi_btdsk_Bbest_Cut114.study"
#f = open(file,'r')

#file2="./ASCII/bkg_MC_d0pi0k_kspipi_btdsk_Bbest_Cut114.study"
#f2 = open(file2,'r')


file="./ASCII/bkg_MC_d0gamk_kskk_btdsk_Bbest_Cut114.study"
f = open(file,'r')

file2="./ASCII/bkg_MC_d0pi0k_kskk_btdsk_Bbest_Cut114.study"
f2 = open(file2,'r')


#file="nopi0gam.dat"
#f = open(file,'r')

#file2="nopi0.dat"
#f2 = open(file2,'r')


#antipi01="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+   K_S0 -> pi+ pi- gamma"
#antipi02="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+ gamma   K_S0 -> pi+ pi-"
#antipi03="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+ gamma gamma   K_S0 -> pi+ pi-"
#antipi04="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+ gamma gamma   K_S0 -> pi+ pi- gamma"


#antipi0="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+   K_S0 -> pi+ pi-"
#pi0="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+   K_S0 -> pi+ pi-"

#pi01="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+   K_S0 -> pi+ pi- gamma"
#pi02="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+ gamma   K_S0 -> pi+ pi-"
#pi03="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+ gamma gamma   K_S0 -> pi+ pi-"
#pi04="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+ gamma gamma   K_S0 -> pi+ pi- gamma"


antipi0="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K- K+ K_S0   K_S0 -> pi+ pi-"
antipi01="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K- K+ K_S0   K_S0 -> pi+ pi- gamma"
antipi02="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K- K+ K_S0 gamma   K_S0 -> pi+ pi-"
antipi03="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K- K+ K_S0 gamma gamma   K_S0 -> pi+ pi-"
antipi04="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K- K+ K_S0 gamma gamma   K_S0 -> pi+ pi- gamma"

pi0="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0   K_S0 -> pi+ pi-"
pi01="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0   K_S0 -> pi+ pi- gamma"
pi02="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0 gamma   K_S0 -> pi+ pi-"
pi03="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0 gamma gamma   K_S0 -> pi+ pi-"
pi04="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0   K_S0 -> pi+ pi-"
pi05="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K- K+ K_S0 gamma gamma   K_S0 -> pi+ pi- gamma"


def chomppy(k):
    if k=="": return ""
    if k=="\n" or k=="\r\n" or k=="\r": return ""
    if len(k)==1: return k #depends on above case being not true
    if len(k)==2 and (k[-1]=='\n' or k[-1]=='\r'): return k[0]
    #done with weird cases, now deal with average case
    lastend=k[-2:] #get last two pieces
    if lastend=='\r\n':
        outstr=k[:-2]
        return outstr
    elif (lastend[1]=="\n" or lastend[1]=="\r"):
        outstr=k[:-1]
        return outstr
    return k



def mygrep(thislinerun):
    print thislinerun
    p = os.popen('grep "'+thislinerun+'" '+file2+'  |wc -l')
    s = p.readline()
    p.close()
    print "result= "+str(s)
    if s=='      1\n':
        print "siiiii"
        a=1
        return a 

    else:
        return -999
    
w=-1
neg=-99
nega=-99
contf=0
conts=0
cont=0
contf1=0
conts1=0
cont1=0

for line in f.readlines():
    run=line.find("runnumber")
    if run!=-1:
        linerun=line


    if w==1 :
        winsec=line.find("Win second")
        winfir=line.find("Win first")

        if winsec!=-1 and neg==1:
            w=-1
            myline=chomppy(linerun)
            n=mygrep(myline)
            contf1=contf1+1
            if n==1:
                contf=contf+1
                print "there is one pi0 also in piodat: "+linerun+"\n"

        elif winfir!=-1 and neg==-1:
            w=-1
            myline=chomppy(linerun)
            m=mygrep(myline)
            conts1=conts1+1
            if m==1:
                conts=conts+1
                print "there is one pi0 also in piodat:"+linerun+"\n"

    a=line.find(pi0)
    b=line.find(antipi0)    
    c=line.find(pi01)
    d=line.find(antipi01)    
    e=line.find(pi02)
    ff=line.find(antipi02)    
    g=line.find(pi03)
    h=line.find(antipi03)    
    i=line.find(pi04)
    j=line.find(antipi04)    
  

    if a!= -1 or b!= -1 or c!= -1 or d!= -1 or e!= -1 or ff!= -1 or g!= -1or h!= -1 or i!= -1 or j!= -1:    
        nega=line.find("-----------")
        if nega!= -1 : 
            neg=1
        else:
            neg=-1
            
        #print line
        w=1
      #  print neg
      #  print w
                
#
#   
 #    break

cont1=contf1+conts1
cont=contf+conts
print contf
print conts
print "Number of pi0 in gamma and common to both samples: "+str(cont)
print "Number of pi0 in gamma: "+str(cont1)

f.close()
f2.close()
