D0,kspipi

  demk_lo_cut=        -0.03
  demk_hi_cut=         0.030
  costhrust_cut =      0.8
  deltamD0_cut =       0.012
  deltamKs_cut =       0.009
  cosKs_cut =          0.99
  mes_cut =            5.272
  mD0_nom=             1.8645
  mKs_nom=             0.4976
  probChi2D0_cut =     0.
  probChi2ChB_cut=     0.
  chi2ChB_cut=         0.
  pid_cut_k =          536870912
  pid_cut_k_kskk_2k=   16777216
  pid_cut_pi=          16777216


Dstar
  deltamd_nom =        0.14212
d0pi0
  deltadeltamd_cut=    0.0025 
d0gam
  deltadeltamd_cut=    0.0025 





  Cut100, d0k, kspipi:
fabs(massD0-mD0_nom)<deltamD0_cut 
fabs(massKs-mKs_nom)<deltamKs_cut 
cosKs>cosKs_cut 
demk2>=demk_lo_cut 
demk2<=demk_hi_cut 
chi2D0>=0. && probChi2D0>probChi2D0_cut 
mes>mes_cut  
fabs(deltadeltamd)<deltadeltamd_cut  
(int(kaonidpr)&pid_cut_k)==pid_cut_k
