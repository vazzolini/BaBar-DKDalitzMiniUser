#!/bin/csh -f

#signal kspipi
bsub -q xlong -J btdk    -o ./log/final_btdk_kspipi.log     root -l -b -q "btdkpi_final_production.cc(1,1,1,2)"
bsub -q xlong -J btdsk   -o ./log/final_btdsk_kspipi.log    root -l -b -q "btdkpi_final_production.cc(2,2,1,2)"
bsub -q xlong -J btdpi   -o ./log/final_btdpi_kspipi.log    root -l -b -q "btdkpi_final_production.cc(3,3,1,2)"
bsub -q xlong -J btdspi  -o ./log/final_btdspi_kspipi.log   root -l -b -q "btdkpi_final_production.cc(4,4,1,2)"



#run"btdk"
bsub -q xlong -J btdk    -o ./log/final_btdk_kspipi.log     root -l -b -q "btdkpi_final_production.cc(1,1,1,2)"
bsub -q xlong -J btdk    -o ./log/final_btdk_kskk.log     root -l -b -q "btdkpi_final_production.cc(1,1,2,2)"

#run"btdsk"
bsub -q xlong -J btdsk   -o ./log/final_btdsk_kspipi.log    root -l -b -q "btdkpi_final_production.cc(2,2,1,2)"
bsub -q xlong -J btdsk   -o ./log/final_btdsk_kskk.log    root -l -b -q "btdkpi_final_production.cc(2,2,2,2)"

#run"btdpi"
bsub -q xlong -J btdpi   -o ./log/final_btdpi_kspipi.log    root -l -b -q "btdkpi_final_production.cc(3,3,1,2)"
bsub -q xlong -J btdpi   -o ./log/final_btdpi_kskk.log    root -l -b -q "btdkpi_final_production.cc(3,3,2,2)"

#run"btdspi"
bsub -q xlong -J btdspi -o ./log/final_btdspi_kspipi.log   root -l -b -q "btdkpi_final_production.cc(4,4,1,2)"
bsub -q xlong -J btdspi  -o ./log/final_btdspi_kskk.log   root -l -b -q "btdkpi_final_production.cc(4,4,2,2)"

#run"chb"
bsub -q xlong -J chb_kspipi     -o ./log/final_chb_kspipi.log      root -l -b -q "btdkpi_final_production.cc(5,5,1,2)"
bsub -q xlong -J chb_kskk     -o ./log/final_chb_kskk.log      root -l -b -q "btdkpi_final_production.cc(5,5,2,2)"

#run"chbk"
bsub -q xlong -J chbk    -o ./log/final_chbk.log     root -l -b -q "btdkpi_final_production.cc(6,6,1,2)"
bsub -q xlong -J chbk    -o ./log/final_chbk.log     root -l -b -q "btdkpi_final_production.cc(6,6,2,2)"

#run"chbpi"
bsub -q xlong -J chbpi   -o ./log/final_chbpi.log    root -l -b -q "btdkpi_final_production.cc(7,7,1,2)"
bsub -q xlong -J chbpi   -o ./log/final_chbpi.log    root -l -b -q "btdkpi_final_production.cc(7,7,2,2)"

#run"b0b0bar"
bsub -q xlong -J b0b0bar_kspipi -o ./log/final_b0b0bar_kspipi.log  root -l -b -q "btdkpi_final_production.cc(8,8,1,2)"
bsub -q xlong -J b0b0bar_kskk  -o ./log/final_b0b0bar_kskk.log  root -l -b -q "btdkpi_final_production.cc(8,8,2,2)"

#run"bbbar"
bsub -q xlong -J bbbar_kspipi   -o ./log/final_bbbar_kspipi.log root -l -b -q "btdkpi_final_production.cc(9,9,1,2)"
bsub -q xlong -J bbbar_kskk   -o ./log/final_bbbar_kskk.log root -l -b -q "btdkpi_final_production.cc(9,9,2,2)"

#run"bbbark"
bsub -q xlong -J bbbark  -o ./log/final_bbbark.log root -l -b -q "btdkpi_final_production.cc(10,10,1,2)"
bsub -q xlong -J bbbark  -o ./log/final_bbbark.log root -l -b -q "btdkpi_final_production.cc(10,10,1,2)"

#run"bbbarpi"
bsub -q xlong -J bbbarpi -o ./log/final_bbbarpi.log root -l -b -q "btdkpi_final_production.cc(11,11,1,2)"
bsub -q xlong -J bbbarpi -o ./log/final_bbbarpi.log root -l -b -q "btdkpi_final_production.cc(11,11,2,2)"

#run"ccbar"
bsub -q xlong -J ccbar_kspipi   -o ./log/final_ccbar_kspipi.log    root -l -b -q "btdkpi_final_production.cc(12,12,1,2)"
bsub -q xlong -J ccbar_kskk   -o ./log/final_ccbar_kskk.log    root -l -b -q "btdkpi_final_production.cc(12,12,2,2)"

#run"uds"
bsub -q xlong -J uds_kspipi     -o ./log/final_uds_kspipi.log      root -l -b -q "btdkpi_final_production.cc(13,13,1,2)"
bsub -q xlong -J uds_kskk     -o ./log/final_uds_kskk.log      root -l -b -q "btdkpi_final_production.cc(13,13,2,2)"

#run"udsccbar"
bsub -q xlong -J udsccbar_kspipi  -o ./log/final_udsccbar_kspipi.log root -l -b -q "btdkpi_final_production.cc(14,14,1,2)"
bsub -q xlong -J udsccbar_kskk  -o ./log/final_udsccbar_kskk.log root -l -b -q "btdkpi_final_production.cc(14,14,2,2)"

#run"on"
bsub -q xlong -J on_kspipi      -o ./log/final_on_kspipi.log2       root -l -b -q "btdkpi_final_production.cc(15,15,1,2)"
bsub -q xlong -J on_kskk      -o ./log/final_on_kskk.log2       root -l -b -q "btdkpi_final_production.cc(15,15,2,2)"

#run"off"
bsub -q xlong -J off     -o ./log/final_off.log      root -l -b -q "btdkpi_final_production.cc(16,16,1,2)"
bsub -q xlong -J off     -o ./log/final_off.log      root -l -b -q "btdkpi_final_production.cc(16,16,2,2)"
