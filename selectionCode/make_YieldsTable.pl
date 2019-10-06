#!/usr/bin/perl 

#use strict;

print "file yields \n";
$infile = <STDIN>;
chop $infile;

print "file table \n";
$outfile = <STDIN>;
chop $outfile;



open (OUTFILE,">$outfile") || die "cannot open $outfile: $!\n";


#@bmodes=("DK","Dpi0K","DgammaK","DKspi","DPi","Dpi0Pi","DgammaPi");
#@bmodes=("DK","Dpi0K","DgammaK","DKspi");
@bmodes=("DPi","Dpi0Pi","DgammaPi");
#@sigtypes=("Sig","BB","Cont","Dh");
@sigtypes=("Dh","BB","Cont","Sig");
@d0modes=("KsPiPi","KsKK");

print OUTFILE "            Sig            BB           Cont             Dh ";

    foreach $bmode (@bmodes) {	
	print OUTFILE "\\\\ \n $bmode ";        
	foreach $d0mode (@d0modes) {
	    print OUTFILE "\\\\ \n $d0mode";
	    foreach $sigtype (@sigtypes) {

open (INFILE,$infile) || die "cannot open $infile: $!\n";
while($line1=<INFILE>){

    chop $line1;   
    @conv1 = split(' ',$line1);
    
    $str0 = "n$sigtype\_\{$bmode\;$d0mode\}";
    
#print "$str0 \n";
    
    if ($str0 eq @conv1[0]) {
	$yield=sprintf("%d",@conv1[2]); 
	$err_yield=sprintf("%d",@conv1[4]); 
	print OUTFILE " &   \$$yield\\pm$err_yield\$  ";
    }
    
}
	    }
	}
}
