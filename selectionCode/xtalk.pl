#!/usr/bin/perl 

#use strict;

#$infile_dpi= "btdkpi_d0pi_kspipi_on_Bbest_Cut100.dat"; 
#$infile_dpi= "btdkpi_d0pi0pi_kspipi_on_Bbest_Cut100.dat"; 
#$infile_dpi= "btdkpi_d0gampi_kspipi_on_Bbest_Cut100.dat"; 

#$infile_dk= "btdkpi_d0k_kspipi_on_Bbest_Cut100.dat"; 
$infile_dpi= "btdkpi_d0pi0k_kskk_on_Bbest_Cut100.dat"; 
$infile_dk= "btdkpi_d0gamk_kskk_on_Bbest_Cut100.dat"; 





$outfile_dpi= "dk.out";
#$outfile_dk= "btdsk_d0pi0.out";
#$outfile_dpi= "btdsk_d0pi0.out";
$outfile_dk= "btdsk_d0gam.out";

print " file dpi = $infile_dpi \n";
print " file dsk = $infile_dk \n";


open (INFILE1,$infile_dpi) || die "cannot open $infile_dpi: $!\n";
#open (OUTFILE1,">$outfile_dpi") || die "cannot open $outfile_dpi: $!\n";
#open (OUTFILE2,">$outfile_dk") || die "cannot open $outfile_dk: $!\n";

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
    open (INFILE2,$infile_dk) || die "cannot open $infile_dk: $!\n";
    while($line2=<INFILE2>){
	$count2++;
	chop $line2; 
	@conv2 = split(' ',$line2);
	$check2= @conv2[16];
	if ($check1 == $check2 ) {
	    if (@conv1[17] == @conv2[17] && @conv1[18] == @conv2[18] ) {
		print "runnumber @conv1[16] @conv2[16] \n";
		print "lowerID = @conv1[17] @conv2[17]  upperID = @conv1[18] @conv2[18] \n";
#		print "Fisher @conv1[15] @conv2[15] \n";
		print "line1= $count1 line2= $count2 \n";
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
