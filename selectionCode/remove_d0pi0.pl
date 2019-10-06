#!/usr/bin/perl 

#use strict;

# define here the input data files to compare
$infile_dpi0= "dat/btdkpi_d0pi0k_kspipi_on_Bbest_Cut100.dat"; 
$infile_dgamma= "dat/btdkpi_d0gamk_kspipi_on_Bbest_Cut100.dat"; 


#define here the output data file
$outfile_dgamma= "dat/dgamma_nopi0.dat";

print " file dpi0 = $infile_dpi0 \n";
print " file dgamma= $infile_dgamma \n";


open (INFILE1,$infile_dgamma) || die "cannot open $infile_dgamma: $!\n";
open (OUTFILE1,">$outfile_dgamma") || die "cannot open $outfile_dgamma: $!\n";

$count1=0;
$count2=0;
$count=0;
while($line1=<INFILE1>){
    #define is common variable here
    $iscommon=false;
    $count1++;
    chop $line1;   
    @conv1 = split(' ',$line1);
#    print "@conv1[16] \n";
    $check1= @conv1[16];
    if (@conv1[14]==0) {
	print "@conv1[14] \n";
    }
    $count2=0;
    open (INFILE2,$infile_dpi0) || die "cannot open $infile_dpi0: $!\n";
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
		#if found a common event on the file2 assing true value
		$iscommon=true;
	    }
	    
	}
    }
    # print only if we have not found any common event
    if ($iscommon eq false) {print OUTFILE1 "$line1 \n";}
}


$perc1 = $count/$count1;
$perc2 = $count/$count2;
#print the number of common events and the relative percentages
print "\n";
print "########################################## \n";
print "Evt =  $count line1 = $count1 line2 = $count2 \n";
print "% file1 =  $perc1  % file2 $perc2 \n";
