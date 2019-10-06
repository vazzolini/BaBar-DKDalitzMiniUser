
b2dkList=""
b2dkList="$b2dkList root/btdkpi_kspipi_btdk.root"
b2dskList=""
b2dskList="$b2dskList root/btdkpi_kspipi_btdsk.root"

bkgList=""
bkgList="$bkgList root/btdkpi_kspipi_off1234.root"
bkgList="$bkgList:root/btdkpi_kspipi_off5.root"

./FisherVar -S $b2dkList  -B $bkgList -T D0     -V costhrust:legendrep0:legendrep2:cosChBCM
./FisherVar -S $b2dskList -B $bkgList -T Dstar0 -V costhrust:legendrep0:legendrep2:cosChBCM

