#!/bin/csh -f

bsub -q xlong -J btdk_kspipi    -o ./log/btdk_kspipi.log root -l -b -q "btdkpi_production.cc(1,1,0,30)"
bsub -q xlong -J btdsk_kspipi   -o ./log/btdsk_kspipi.log root -l -b -q "btdkpi_production.cc(2,1,0,30)"
bsub -q xlong -J btdpi_kspipi   -o ./log/btdpi_kspipi.log root -l -b -q "btdkpi_production.cc(3,1,0,30)"
bsub -q xlong -J btdspi_kspipi  -o ./log/btdspi_kspipi.log root -l -b -q "btdkpi_production.cc(4,1,0,30)"


bsub -q xlong -J btdk_kspipi    -o ./log/btdk_kspipi.log root -l -b -q "btdkpi_production.cc(1,1,0,30)"
bsub -q xlong -J btdk_kskk      -o ./log/btdk_kskk.log root -l -b -q "btdkpi_production.cc(1,2,0,30)"

bsub -q xlong -J btdsk_kspipi   -o ./log/btdsk_kspipi.log root -l -b -q "btdkpi_production.cc(2,1,0,30)"
bsub -q xlong -J btdsk_kskk     -o ./log/btdsk_kskk.log root -l -b -q "btdkpi_production.cc(2,2,0,30)"

bsub -q xlong -J btdpi_kspipi   -o ./log/btdpi_kspipi.log root -l -b -q "btdkpi_production.cc(3,1,0,30)"
bsub -q xlong -J btdpi_kskk     -o ./log/btdpi_kskk.log root -l -b -q "btdkpi_production.cc(3,2,0,30)"

bsub -q xlong -J btdspi_kspipi  -o ./log/btdspi_kspipi.log root -l -b -q "btdkpi_production.cc(4,1,0,30)"
bsub -q xlong -J btdspi_kskk    -o ./log/btdspi_kskk.log root -l -b -q "btdkpi_production.cc(4,2,0,30)"

bsub -q xlong -J chb_kspipi     -o ./log/chb_kspipi.log root -l -b -q "btdkpi_production.cc(5,1,0,30)"
bsub -q xlong -J chb_kskk       -o ./log/chb_kskk.log root -l -b -q "btdkpi_production.cc(5,2,0,30)"

bsub -q xlong -J chbk_kspipi    -o ./log/chbk_kspipi.log root -l -b -q "btdkpi_production.cc(6,1,0,30)"
bsub -q xlong -J chbk_kskk      -o ./log/chbk_kskk.log root -l -b -q "btdkpi_production.cc(6,2,0,30)"

bsub -q xlong -J chbpi_kspipi   -o ./log/chbpi_kspipi.log root -l -b -q "btdkpi_production.cc(7,1,0,30)"
bsub -q xlong -J chbpi_kskk     -o ./log/chbpi_kskk.log   root -l -b -q "btdkpi_production.cc(7,2,0,30)"

bsub -q xlong -J b0b0bar_kspipi -o ./log/b0b0bar_kspipi.log root -l -b -q "btdkpi_production.cc(8,1,0,30)"
bsub -q xlong -J b0b0bar_kskk   -o ./log/b0b0bar_kskk.log   root -l -b -q "btdkpi_production.cc(8,2,0,30)"

bsub -q xlong -J ccbar1_kspipi   -o ./log/ccbar1_kspipi.log root -l -b -q "btdkpi_production.cc(9,1,0,30)"
bsub -q xlong -J ccbar1_kskk     -o ./log/ccbar1_kskk.log   root -l -b -q "btdkpi_production.cc(9,2,0,30)"
bsub -q xlong -J ccbar2_kspipi   -o ./log/ccbar2_kspipi.log root -l -b -q "btdkpi_production.cc(10,1,0,30)"
bsub -q xlong -J ccbar2_kskk     -o ./log/ccbar2_kskk.log   root -l -b -q "btdkpi_production.cc(10,2,0,30)"

bsub -q xlong -J ccbar34_kspipi   -o ./log/ccbar34_kspipi.log root -l -b -q "btdkpi_production.cc(11,1,0,30)"
bsub -q xlong -J ccbar34_kskk     -o ./log/ccbar34_kskk.log   root -l -b -q "btdkpi_production.cc(11,2,0,30)"
bsub -q xlong -J ccbar5_kspipi   -o ./log/ccbar5_kspipi.log   root -l -b -q "btdkpi_production.cc(12,1,0,30)"
bsub -q xlong -J ccbar5_kskk     -o ./log/ccbar5_kskk.log     root -l -b -q "btdkpi_production.cc(12,2,0,30)"

bsub -q xlong -J uds12_kspipi     -o ./log/uds12_kspipi.log   root -l -b -q "btdkpi_production.cc(13,1,0,30)"
bsub -q xlong -J uds12_kskk       -o ./log/uds12_kskk.log     root -l -b -q "btdkpi_production.cc(13,2,0,30)"
bsub -q xlong -J uds4_kspipi     -o ./log/uds4_kspipi.log   root -l -b -q "btdkpi_production.cc(14,1,0,30)"
bsub -q xlong -J uds4_kskk       -o ./log/uds4_kskk.log     root -l -b -q "btdkpi_production.cc(14,2,0,30)"
bsub -q xlong -J uds5_kspipi      -o ./log/uds5_kspipi.log    root -l -b -q "btdkpi_production.cc(15,1,0,30)"
bsub -q xlong -J uds5_kskk       -o ./log/uds5_kskk.log       root -l -b -q "btdkpi_production.cc(15,2,0,30)"

bsub -q xlong -J on1_kspipi      -o ./log/on1_kspipi.log root -l -b -q "btdkpi_production.cc(16,1,0,30)"
bsub -q xlong -J on1_kskk        -o ./log/on1_kskk.log   root -l -b -q "btdkpi_production.cc(16,2,0,30)"

bsub -q xlong -J on2_kspipi     -o ./log/on2_kspipi.log root -l -b -q "btdkpi_production.cc(17,1,0,30)"
bsub -q xlong -J on2_kskk       -o ./log/on2_kskk.log   root -l -b -q "btdkpi_production.cc(17,2,0,30)"

bsub -q xlong -J on3_kspipi     -o ./log/on3_kspipi.log root -l -b -q "btdkpi_production.cc(18,1,0,30)"
bsub -q xlong -J on3_kskk       -o ./log/on3_kskk.log   root -l -b -q "btdkpi_production.cc(18,2,0,30)"

bsub -q xlong -J on4_kspipi     -o ./log/on4_kspipi.log root -l -b -q "btdkpi_production.cc(19,1,0,30)"
bsub -q xlong -J on4_kskk       -o ./log/on4_kskk.log   root -l -b -q "btdkpi_production.cc(19,2,0,30)"

bsub -q xlong -J on5_kspipi      -o ./log/on5_kspipi.log root -l -b -q "btdkpi_production.cc(20,1,0,30)"
bsub -q xlong -J on5_kskk        -o ./log/on5_kskk.log   root -l -b -q "btdkpi_production.cc(20,2,0,30)"

bsub -q xlong -J on_kspipi      -o ./log/on_kspipi.log root -l -b -q "btdkpi_production.cc(21,1,0,30)"
bsub -q xlong -J on_kskk        -o ./log/on_kskk.log   root -l -b -q "btdkpi_production.cc(21,2,0,30)"

bsub -q xlong -J off_kspipi     -o ./log/off_kspipi.log root -l -b -q "btdkpi_production.cc(22,1,0,30)"
bsub -q xlong -J off_kskk       -o ./log/off_kskk.log   root -l -b -q "btdkpi_production.cc(22,2,0,30)"

#grep "Successfully " ./log/*log
#grep "Exited "       ./log/*log

#grep "not closed"    ./log/*log
#grep "Zombie"        ./log/ *log
