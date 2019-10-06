#!/usr/bin/perl 

#use strict;

#########################################################################
# Author: Nicola Neri INFN-Pisa email:nicola.neri@pi.infn.it
# Perl script to produce two ASCII files with common events 
# based on the RunNumber and the TimeStamp informations (where available)
#########################################################################


print "Signal sample: d0k, d0pi0k, d0gamk, d0kst, d0pi, d0pi0pi, d0gampi, d0a1 \n";
$sig_sample = <STDIN>;
chop $sig_sample;
if ($sig_sample eq "") {$sig_sample = "d0k";}
print "$sig_sample \n";

if ($sig_sample eq "d0k"){
$infile_dk_04= "input/summer04/D0K-on-Fernando-CM2-BlackDiamond.ascii";
$infile_dk_06= "input/summer06/btdkpi_d0k_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0k_CommonEvents04.dat";
$outfile_dk_06= "d0k_CommonEvents06.dat";
} elsif ($sig_sample eq "d0pi0k"){
$infile_dk_04= "input/summer04/btdsk_d0pi0_kspipi_on_rescaled_Bbest-BlackDiamond.dat";
$infile_dk_06= "input/summer06/btdkpi_d0pi0k_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0pi0k_CommonEvents04.dat";
$outfile_dk_06= "d0pi0k_CommonEvents06.dat";
} elsif ($sig_sample eq "d0gamk"){
$infile_dk_04= "input/summer04/btdsk_d0gam_kspipi_on_rescaled_Bbest-BlackDiamond.dat";
$infile_dk_06= "input/summer06/btdkpi_d0gamk_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0gamk_CommonEvents04.dat";
$outfile_dk_06= "d0gamk_CommonEvents06.dat";
}elsif ($sig_sample eq "d0kst"){
$infile_dk_04= "input/summer05/btdkstar_kspi_kspipi_On1234_rescaled_Bbest_Cut112.dat";
$infile_dk_06= "input/summer06/btdkstarc_kspi_kspipi_On_Bbest_Cut112.dat";
$outfile_dk_04= "d0kst_CommonEvents04.dat";
$outfile_dk_06= "d0kst_CommonEvents06.dat";
}elsif ($sig_sample eq "d0pi"){
$infile_dk_04= "input/summer04/D0Pi-on-Fernando-kidl.eq.0-CM2-BlackDiamond.ascii";
$infile_dk_06= "input/summer06/btdkpi_d0pi_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0pi_CommonEvents04.dat";
$outfile_dk_06= "d0pi_CommonEvents06.dat";
}elsif ($sig_sample eq "d0pi0pi"){
$infile_dk_04= "input/summer04/btdsp_d0pi0_kspipi_on_rescaled_Bbest-BlackDiamond.dat";
$infile_dk_06= "input/summer06/btdkpi_d0pi0pi_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0pi0pi_CommonEvents04.dat";
$outfile_dk_06= "d0pi0pi_CommonEvents06.dat";
}elsif ($sig_sample eq "d0gampi"){
$infile_dk_04= "input/summer04/btdsp_d0gam_kspipi_on_rescaled_Bbest-BlackDiamond.dat";
$infile_dk_06= "input/summer06/btdkpi_d0gampi_kspipi_on_Bbest_Cut112.dat";
$outfile_dk_04= "d0gampi_CommonEvents04.dat";
$outfile_dk_06= "d0gampi_CommonEvents06.dat";
}



print "file dk_04 = $infile_dk_04 \n";
print "file dk_06 = $infile_dk_06 \n";


open (INFILE1,$infile_dk_04) || die "cannot open $infile_dk_04: $!\n";
open (OUTFILE1,">$outfile_dk_04") || die "cannot open $outfile_dk_04: $!\n";
open (OUTFILE2,">$outfile_dk_06") || die "cannot open $outfile_dk_06: $!\n";

$count1=0;
$count2=0;
$count=0;
while($line1=<INFILE1>){
    $count1++;
    chop $line1;   
    @conv1 = split(' ',$line1);
#    print "@conv1[16] \n";
    $check1= @conv1[16];
    if (@conv1[14]==0) {
	print "@conv1[14] \n";
    }
    $count2=0;
    open (INFILE2,$infile_dk_06) || die "cannot open $infile_dk_06: $!\n";
    while($line2=<INFILE2>){
	$count2++;
	chop $line2; 
	@conv2 = split(' ',$line2);
	$check2= @conv2[16];
	if ($check1 == $check2 ) {
#	    if (@conv1[17] == @conv2[17] && @conv1[18] == @conv2[18] ) {

# check the lowerID number if the sample is not d0kst
# that is because the upperID number is broken for d0k sample 
# and there is no lowerID and upperID for the d0kst sample summer05
	    
	    if ( (@conv1[17] == @conv2[17]) || ($sig_sample eq "d0kst") ) {
		
		print OUTFILE1 "$line1 \n";
 		print OUTFILE2 "$line2 \n";
#		print "runnumber @conv1[16] @conv2[16] \n";
#		print "lowerID = @conv1[17] @conv2[17]  upperID = @conv1[18] @conv2[18] \n";
#		print "Fisher @conv1[15] @conv2[15] \n";
#		print "line1= $count1 line2= $count2 \n";
		$count++;
	    }
	    
	}
    }

}

$perc1 = $count/$count1;
$perc2 = $count/$count2;

print "\n";
print "########################################## \n";
print "Evt =  $count line1 = $count1 line2 = $count2 \n";
print "% file1 =  $perc1  % file2 $perc2 \n";
