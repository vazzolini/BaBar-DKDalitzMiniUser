#! /usr/bin/env python

import sys

#cutSigdlKs=sys.argv[1]

file="./ASCII/bkg_MC_d0gamk_kspipi_btdsk_Bbest_Cut114.study"
f = open(file,'r')

file2="./ASCII/bkg_MC_d0pi0k_kspipi_btdsk_Bbest_Cut114.study"
f2 = open(file2,'r')


#B+ -> anti-D0 K+   anti-D0 -> pi- pi- pi+ pi+ gamma
#B+ -> anti-D0 K+   anti-D0 -> pi- pi- pi+ pi+
#B- -> D0 K-   D0 -> pi- pi- pi+ pi+
#B- -> D0 K-   D0 -> pi- pi- pi+ pi+ gamma
#B- -> D0 K- gamma   D0 -> pi- pi- pi+ pi+
#---------------------------------------------------------------------------------------------------------


#bm="B- -> D0 K-   D0 -> pi- pi- pi+ pi+"
#bp="B+ -> anti-D0 K+   anti-D0 -> pi- pi- pi+ pi+"
#bmg="B- -> D0 K- gamma   D0 -> pi- pi- pi+ pi+"
#bpg="B+ -> anti-D0 K+ gamma   anti-D0 -> pi- pi- pi+ pi+"

pi0="B- -> D*0 K-   D*0 -> D0 pi0   D0 -> K_S0 pi- pi+   K_S0 -> pi+ pi-"
antipi0="B+ -> anti-D*0 K+   anti-D*0 -> anti-D0 pi0   anti-D0 -> K_S0 pi- pi+ gamma gamma   K_S0 -> pi+ pi-"


w=-1
neg=-99
nega=-99
contf=0
conts=0
cont=0


for line in f.readlines():
    run=line.find("runnumber")
    if run!=-1:
        linerun=line
#        print linerun

    if w==1 :
        winsec=line.find("Win second")
        winfir=line.find("Win first")

        if winsec!=-1 and neg==1:
            #print "one good"
            w=-1
            f2 = open(file2,'r')
            for line2 in f2.readlines():
                thereis=line2.find(linerun)
                if thereis!=-1:
                    contf=contf+1
                    print "there is one pi0 also in piodat: "+line2+"\n"
        elif winfir!=-1 and neg==-1:
            w=-1
            f2 = open(file2,'r')
            for line2 in f2.readlines():
                thereis=line2.find(linerun)
                if thereis!=-1:
                    print line2
                    conts=conts+1
                    print "there is one pi0 also in piodat: "+line2+"\n"

    a=line.find(pi0)
    b=line.find(antipi0)    
  

    if a!= -1 or b!= -1:    
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

cont=contf+conts
print contf
print conts
print "Number of pi0: "+str(cont)
f.close()
