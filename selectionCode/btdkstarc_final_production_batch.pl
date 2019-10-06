#!/usr/bin/perl 

print "Running mode: interactive/batch ";
$run_mode = <STDIN>;
chop $run_mode;
if ($run_mode eq "") {$run_mode = "interactive";}
print "$run_mode \n";


if ($run_mode eq "batch"){
    if ($ENV{BFSITE} eq "slac"){
	print "You are running at SLAC \n";
	print "Queue name: long, medium, kanga, xlong ";
	$queue = <STDIN>;
	chop $queue;
	if ($queue eq "") {$queue = "long";}
	print "$queue \n";
	print "Privileges: \n";
	$privileges = <STDIN>;
	chop $privileges; 
	print "Any flagstring?: \n";
	$flagstring = <STDIN>;
	chop $flagstring;
    } else {
	die "Can only run at SLAC $!\n";
    }
}

#@sigtypes=("btdkstarc","chb","b0b0bar","uds","ccbar","On","chbR");
#@sigtypes=("ccbar","bbbar","uds");
#@sigtypes=("btdkstarc","btda1");
#@sigtypes=("chb","chbR","chbNR","b0b0bar","ccbar","uds");
#@sigtypes=("chb","chbR","chbNR","b0b0bar");
#@sigtypes=("ccbar","uds");
#@sigtypes=("bbbar","udsccbar");
#@sigtypes=("On","Off");
#@sigtypes=("ccbar");
@sigtypes=("btdkstarc");
@d0modes=("kspipi");
#@cutcodes=("0","1","2","112","100");
@cutcodes=("1");
#@isCSs=("kFALSE","kTRUE");
@isCSs=("kFALSE");



foreach $sigtype (@sigtypes) {
    foreach $d0mode (@d0modes) {
	foreach $isCS (@isCSs) {
	    
	    $jobname="btdkstarc";
	    $kstarcdecay="kspi";
	    if ($isCS eq "kTRUE") {
		$jobname="btda1";
		$kstarcdecay="rho0pi";
	    }
	    if ( (($sigtype eq "btdkstarc")and($isCS eq "kTRUE")) or (($sigtype eq "btda1")and($isCS eq "kFALSE")) ) {
		#do nothing
		} else { 
		    
		    if($flagstring eq ""){$jobname=$jobname . "\_${kstarcdecay}\_${d0mode}\_${sigtype}";}
		    else{$jobname=$jobname . "\_${kstarcdecay}\_${d0mode}\_${sigtype}\_${flagstring}";}
		    $file_outrun="log/${jobname}.C";
		    $file_outbatch="log/${jobname}.csh";
		    $file_outlog="log/${jobname}.log";
		    
		    open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
		    print OUTRUN "{ \n";
		    print OUTRUN " gROOT->ProcessLine(\".L btdkstarc\_final.C+\"); \n";
		    
		    foreach $cutcode (@cutcodes) {
			#print OUTRUN " gROOT->Reset(); \n";
			print OUTRUN " btdkstarc\_final t(\"${kstarcdecay}\",\"${d0mode}\",\"${sigtype}\",\"analysis-30\",$isCS); \n";
			print OUTRUN " t.LoopBest($cutcode); \n";
			#print OUTRUN " t.Loop($cutcode); \n";
			#print OUTRUN " t.Fits($cutcode); \n";
		    }
		    
		    print OUTRUN "} \n";
		    close OUTRUN;
		    
		    if ($run_mode eq "batch"){
			if ($ENV{BFSITE} eq "slac"){
			    open(BATCHSCRIPT,">$file_outbatch");
			    print BATCHSCRIPT "#! /bin/csh \n";
			    print BATCHSCRIPT "#BSUB -q $queue \n";
			    print BATCHSCRIPT "#BSUB -J $jobname \n";
			    print BATCHSCRIPT "#BSUB -o $file_outlog \n";
			    if ($privileges ne "") {print BATCHSCRIPT "#BSUB -G $privileges \n";}
			    print BATCHSCRIPT "root -l -b -q $file_outrun \n";
			    close(BATCHSCRIPT);
			    $command = "bsub < $file_outbatch ";
			    print " $command  \n";
			    system($command);
			}
		    } else {
			$command = "root -l -b -q $file_outrun > $file_outlog";
			print " $command  \n";
			system($command);
		    }
		    
		}
	}
    }
}







