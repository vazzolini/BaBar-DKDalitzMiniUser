#!/usr/bin/perl 

#use strict;


$sigma_bbbar=1.1e6; #in fb
$sigma_ccbar=1.3e6; #in fb
$sigma_uds=2.09e6; #in fb
#calculate d0k luminosity
$nevt_d0k=675e03;
#$BR_d0k=7.61518275000000069e-06; #kspipi
$BR_d0k=1.31384225e-06;    # kskk
$lumi_d0k=$nevt_d0k/($BR_d0k*$sigma_bbbar);
#$lumi_d0k=sprintf("%.0f",$nevt_d0k/($BR_d0k*$sigma_bbbar));
#print "lumi d0k = $lumi_d0k \n";

#calculate d0sk luminosity
$nevt_d0sk=1349e03;
#$BR_d0sk=7.409367e-06; #kspipi
$BR_d0sk=1.278333e-06; #kskk
$lumi_d0sk=$nevt_d0sk/($BR_d0sk*$sigma_bbbar);
#$lumi_d0sk=sprintf("%.0f",$nevt_d0sk/($BR_d0sk*$sigma_bbbar));
#print "lumi d0sk = $lumi_d0sk \n";

#calculate d0ks luminosity
$nevt_d0ks=719e03;
#$BR_d0ks=2.166064e-06; #kspipi
$BR_d0ks=2.16606425e-06; #kskk
$lumi_d0ks=$nevt_d0ks/($BR_d0ks*$sigma_bbbar);
#$lumi_d0ks=sprintf("%.0f",$nevt_d0ks/($BR_d0ks*$sigma_bbbar));
#print "lumi d0ks = $lumi_d0ks \n";

#lumi generic MC
$lumi_b0b0bar=866;
$lumi_chb=825;
$lumi_uds=165;
$lumi_ccbar=356;
$lumi_on=288.5;


@sigtypes=("btdk","btdsk","chb","b0b0bar","ccbar","uds","on");
#@d0modes=("kspipi","kskk");
#@d0modes=("kspipi");
$d0mode=("kskk");
#@dstar0modes=("d0pi0","d0gam","d0");
$dstar0mode= "d0gam";
@KorPis=("k");
#@cutcodes=("1000","1001","1002","1003","1004","1005","1006","1007","1008","1009","1010");
@cutcodes=("1010");
if ($dstar0mode eq "d0pi0") {$dm_cut=2.5;}
else {$dm_cut=10;}

if ($dstar0mode eq "d0pi0" || $dstar0mode eq "d0gam"){$lumi_sig=$lumi_d0sk}
if ($dstar0mode eq "d0" ){$lumi_sig=$lumi_d0k}


#    foreach $d0mode (@d0modes) {
#        foreach $dstar0mode (@dstar0modes) {
            foreach $cutcode (@cutcodes) {
		foreach $sigtype (@sigtypes) {


$string=`wc btdkpi\_$dstar0mode@KorPis\_$d0mode\_$sigtype\_Bbest\_Cut$cutcode.dat ` ;
#print "$string \n";
@evt= split(' ', $string);

if (($sigtype eq "btdk") && ($dstar0mode eq "d0" )) {$evt_sig=$evt[0];}
if ($sigtype eq "btdsk" && ($dstar0mode eq "d0pi0" || $dstar0mode eq "d0gam" ) ) {$evt_sig=$evt[0];}
if ($sigtype eq "b0b0bar") {$evt_b0b0bar=$evt[0];}
if ($sigtype eq "chb") {$evt_chb=$evt[0];}
if ($sigtype eq "ccbar") {$evt_ccbar=$evt[0];}
if ($sigtype eq "uds") {$evt_uds=$evt[0];}
#print " $evt_sig $evt_b0b0bar $evt_chb $evt_ccbar $evt_uds \n";
 
}

if ($cutcode == 1000) {print "\$|cos\\theta_{thr}|<\$0.8   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar \\\\  \n"};
if ($cutcode == 1001) {print "\$|M_{\\KS}(D^0)-M_{\\KS}(PDG)|<\$9 \\mev   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar \\\\ \n"};
if ($cutcode == 1002) {print "\$|M_{D^0}-M_{D^0}(PDG)|<\$12 \\mev   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar \\\\ \n"};
if ($cutcode == 1003 && $d0mode eq "kskk" ) {print "\\Dz track Kaon ID   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1004) {print "\$\\cos(\\alpha_{\\KS}(D^0))>\$0.99   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1005) {print "\$P(\\chi^2,D^0)>\$0.  & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar \\\\ \n"};
if ($cutcode == 1006) {print "\$P(\\chi^2,B)>\$0.  & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1007 && ($dstar0mode eq "d0pi0" ||  $dstar0mode eq "d0gam")) 
{print "\$\\Delta M<$dm_cut\$ \\mev   & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1008) {print "Kaon ID bachelor track     & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1009) {print "\$|\\Delta E|<\$ 30 \\mev  & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \n"};
if ($cutcode == 1010) {
    $evt_sigNorm=sprintf("%.0f",($evt_sig*($lumi_on/$lumi_sig)));
    $evt_b0b0barNorm=sprintf("%.0f",($evt_b0b0bar*($lumi_on/$lumi_b0b0bar)));
    $evt_chbNorm=sprintf("%.0f",($evt_chb*($lumi_on/$lumi_chb)));
    $evt_udsNorm=sprintf("%.0f",($evt_uds*($lumi_on/$lumi_uds)));
    $evt_ccbarNorm=sprintf("%.0f",($evt_ccbar*($lumi_on/$lumi_ccbar)));

    print "\$\\m_{ES}>\$ 5.272 \\gev  & $evt_sig &  $evt_b0b0bar &  $evt_chb & $evt_uds &  $evt_ccbar  \\\\ \\hline \\hline \n";
    print "\$\\m_{ES}>\$ 5.272 \\gev  norm to data & $evt_sigNorm &  $evt_b0b0barNorm &  $evt_chbNorm & $evt_udsNorm &  $evt_ccbarNorm  \\\\ \\hline \n";


    };


	    }
#}
#}
