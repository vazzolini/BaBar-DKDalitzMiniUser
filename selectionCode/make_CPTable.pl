#!/usr/bin/perl 

#use strict;

print "sample: DPi, DK \n";
$sample = <STDIN>;
chop $sample;

print "file yields \n";
$infile = <STDIN>;
chop $infile;

print "file table \n";
$outfile = <STDIN>;
chop $outfile;



open (OUTFILE,">$outfile") || die "cannot open $outfile: $!\n";

if ($sample eq "DPi") {
@bmodes=("DPi","Dpi0Pi");
}elsif ($sample eq "DK") {
    @bmodes=("DK","Dpi0K","DKspi");
}
@signs=("M","P");
@parts=("re","im","rs2");
$d0mode=("KsPiPi");

if ($sample eq "DK"){ 
print OUTFILE "            DK            DstarK           Dkst           ";
}elsif ($sample eq "DPi"){ 
print OUTFILE "            DPi            DstarPi           ";
}

    foreach $sign (@signs) {	
	foreach $part (@parts) {	
	    print OUTFILE "\\\\ \n  $part$sign";        
	    foreach $bmode (@bmodes) {	
	

open (INFILE,$infile) || die "cannot open $infile: $!\n";
while($line1=<INFILE>){

    chop $line1;   
    @conv1 = split(' ',$line1);

if ($sample eq "DK" && !($part eq "rs2")){ 
    $str0 = "$part$sign\_$bmode";
}elsif ($sample eq "DK" && ($part eq "rs2")){ 
    $str0 = "$part\_$bmode";
}elsif ( $sample eq "DPi"){ 
   $str0 = "$part${sign}Dh\_$bmode";
#   print "$str0 \n";
}
    

print "$str0 $conv1[0] \n";
    
    if ($str0 eq @conv1[0]) {
	if ($sample eq "DPi"){ 
	$CPpar=sprintf("%.4f",@conv1[2]); 
	$err_CPpar=sprintf("%.4f",@conv1[4]); 
	} else {
	    $CPpar=sprintf("%.2f",@conv1[2]); 
	$err_CPpar=sprintf("%.2f",@conv1[4]); 
	}
	if (!($part eq "rs2")) {print OUTFILE " &   \$$CPpar\\pm$err_CPpar\$  ";}
	else {print OUTFILE " &    -     &       -        &   \$$CPpar\\pm$err_CPpar\$  ";}
    }
}
	    }
	}
}
