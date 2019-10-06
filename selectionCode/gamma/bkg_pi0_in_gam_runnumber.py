#! /usr/bin/env python

import sys
import os

file="./ASCII/bkg_MC_d0gamk_kspipi_btdsk_Bbest_Cut114.study"
f = open(file,'r')

file2="./ASCII/bkg_MC_d0pi0k_kspipi_btdsk_Bbest_Cut114.study"
f2 = open(file2,'r')

#cutSigdlKs=sys.argv[1]

#file="nopi0gam.dat"
#f = open(file,'r')

#file2="nopi0.dat"
#f2 = open(file2,'r')



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


linerun="runnumber : 14026911 lowerid : -2051094816 upperid : 712781\n"
line2=chomppy(linerun)
#os.sytem('grep "'+linerun+'" '+file2+'  |wc -l')
#os.sytem('hostname')




#linerun="hola"

p=mygrep(line2)
if p==1:
    print "YEAH!"
print "resultat de mygrep: "+str(p)


#for line in f.readlines():
#    run=line.find("runnumber")
#    if run!=-1:
#        print line
#        n=mygrep(line)


#for line in f.readlines():
#    run=line.find("runnumber")
#    if run!=-1:
#        print line
#        os.sytem('grep "'+line+'" '+file2+'  |wc -l')
#        p = os.popen('grep "'+line+'" '+file2+'  |wc -l')
#        s = p.readline()
#        p.close()
#        print "result= "+s
#        if s=='      1\n':
#            print "siiiii"
#            a=1





f.close()
f2.close()

