#! /usr/bin/env python
#import commands
import math
import os
import sys
from string import atof



#totalev=["54000","28000","11000","30000"]
totalev=["54000"]

for i in range(1,3,4,5,6):
    
    file="btdkpi_d0k_kspipi_btdk"+run+"_Bbest_Cut100.dat"
    f=open(file,'r')
    
    ev = len(f.readlines())
    f.close() 

    efi=atof(ev)/atof(totalev[i])
    
    print str(efi)
    
