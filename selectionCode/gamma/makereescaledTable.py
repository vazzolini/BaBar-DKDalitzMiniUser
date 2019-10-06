#! /usr/bin/env python
import math
import os
import sys
from string import atof,atoi
import linecache

#python makereescaledTable.py dk

sigtype=sys.argv[1]

def rounded(a):
    return "%.0f" % round(a)

def roundtwo(a):
    return "%.2f" % round(a,2)


outfile="rescaled"+sigtype+".tex"
fout=open(outfile,"w")


if sigtype=="dk":
    p=7
    sig_old=["609","131","156","35","114","15","109"]
    sig_new=["958","174","269","57","194","22","155"]

    err_old=["33","14","17","6","16","6","14"]

    dh_old=["221","34","62","12","16","1","0"]
    dh_new=["157","10","10","19","0","0","0"]
    
    BB_old=["1355","2","251","14","713","68","852"]
    BB_new=["2296","49","412","13","1062","96","951","68"]
    
    Cont_old=["26085","2508","2119","221","6433","524","8367"]
    Cont_new=["34388","2957","2819","263","7880","586","8277","637"]

elif sigtype=="dpi":   
    p=6
    sig_old=["8262","1402","2227","350","1446","236"]
    sig_new=["12260","2226","3582","557","2259","435"]

    err_old=["105","41","55","20","53","20"]

    dh_old=["153","34","83","15","74","14"]
    dh_new=["215","43","47","16","23","5"]
    
    BB_old=["8262","506","1521","165","4371","497"]
    BB_new=["8297","404","2312","257","6415","674"]
    
    Cont_old=["4262","4122","3492","373","10824","891"]
    Cont_new=["46767","4056","3884","332","10778","782"]

    
lumi_old=350.6
lumi_new=425.5
oerr=0
f=lumi_new/lumi_old

Sold=0
Snew=0

fout.write("\\begin{table}[htb!]\n \\begin{center}\n {\\small\n \\begin{tabular}{|c|c|c|c|c|} \\hline\n  & Run1-5 reescaled  & $Gain$ & $S_{Run15}$ & S_{Run16}   \\\ \\hline\\hline \n")


for i in range(0,p):


    o=atoi(sig_old[i])
    oerr=atoi(err_old[i])
    n=atoi(sig_new[i])

   #print a
    r1=o*f
    r2=rounded(o*f)
    
    print "Reescaled R15: "+str(r2)+"\pm "+str(oerr)

    g=rounded(r1/n*100)

    print "Gain: "+g+"%"

    Sold=roundtwo(atof(sig_old[i])/math.sqrt(atof(sig_old[i])+atof(BB_old[i])+atof(Cont_old[i])+atof(dh_old[i])))
    Snew=roundtwo(atof(sig_new[i])/math.sqrt(atof(sig_new[i])+atof(BB_new[i])+atof(Cont_new[i])+atof(dh_new[i])))
           
    print "Significancia old= "+str(Sold)
    print "Significancia new= "+str(Snew)

#for latex

    fout.write("& $"+str(r2)+" \pm "+str(oerr)+" $ & "+g+" \%  &  "+str(Sold)+"  &  "+str(Snew)+" \\\ \n")


fout.write("\\hline\n \\end{tabular}\n }\n \\caption{\\small table}")

print "end"
