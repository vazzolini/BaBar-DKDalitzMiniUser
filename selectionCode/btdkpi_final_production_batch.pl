#!/usr/bin/perl 

print "Running mode: batch/interactive ";
$run_mode = <STDIN>;
chop $run_mode;
if ($run_mode eq "") {$run_mode = "batch";}
print "$run_mode \n";

if ($run_mode eq "batch"){
    if ($ENV{BFSITE} eq "slac"){
	print "You are running at SLAC \n";
	print "Queue name: kanga,long, medium, xlong ";
	$queue = <STDIN>;
	chop $queue;
	if ($queue eq "") {$queue = "kanga";}
	print "$queue \n";
	print "Privileges: \n";
	$privileges = <STDIN>;
	chop $privileges; 
    } else {
	die "Can only run at SLAC $!\n";
    }
}

#*****************************   AN-50  ************************

#@sigtypes=("btdk1","btdk2","btdk3","btdk4","btdk5","btdk6");
#@sigtypes =("btdpi1","btdpi2","btdpi3","btdpi4","btdpi5","btdpi6");
#@sigtypes = ("btdsk1","btdsk2","btdsk3","btdsk4","btdsk5","btdsk6");
#@sigtypes =("btdspi1","btdspi2","btdspi3","btdspi4","btdspi5","btdspi6");

#@sigtypes=("btdk1","btdk2","btdk3","btdk4","btdk5","btdk6");
#,"btdsk1","btdsk2","btdsk3","btdsk4","btdsk5","btdsk6");

#@sigtypes=("btdpi1","btdpi2","btdpi3","btdpi4","btdpi5","btdpi6","btdspi1","btdspi2","btdspi3","btdspi4","btdspi5","btdspi6");


#*******************************************************

@sigtypes=("chb");

#@sigtypes=("btdk","btdsk","btdpi","btdspi","chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar","on","off");
#@sigtypes=("btdk","btdsk","btdpi","btdspi");
#@sigtypes=("chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar");
#@sigtypes=(#"on","off");
#@sigtypes=("btdk","chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar","on");
#@sigtypes=("btdk","chb","chbk","chbpi","b0b0bar","ccbar","uds","on");

#*****************************************************************************

@d0modes=("kspipi","kskk");
#@d0modes=("kspipi");
#@d0modes=("kskk");

#@dtypes=("Dstar0","D0");
@dtypes=("D0");
#@dtypes=("Dstar0");

#@dstar0modes=("d0pi0","d0gam","d0");
#@dstar0modes=("d0pi0","d0gam");
@dstar0modes=("d0");



#@KorPis=("k","pi");
#@KorPis=("pi");
@KorPis=("k");

#@cutcodes=("1","2","112","100");
#@cutcodes=("1","2");
#@cutcodes=("1");
#@cutcodes=("112","100");
@cutcodes=("100");

foreach $sigtype (@sigtypes) {
    foreach $d0mode (@d0modes) {
	$jobname="btdkpi\_${d0mode}\_${sigtype}";
	$file_outrun="log/${jobname}.C";
	$file_outbatch="log/${jobname}.csh";
	$file_outlog="log/${jobname}.log";
	
	open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	print OUTRUN "{ \n";
	print OUTRUN " gROOT->ProcessLine(\".L btdkpi\_final.C+\"); \n";
	
	foreach $dstar0mode (@dstar0modes) {
	    foreach $dtype (@dtypes) {
		if ( (($dtype eq "D0")and($dstar0mode eq "d0")) or (($dtype eq "Dstar0")and($dstar0mode ne "d0")) ) {
		    foreach $KorPi (@KorPis) {
			foreach $cutcode (@cutcodes) {			    
			    print OUTRUN " gROOT->Reset(); \n";
			    print OUTRUN " btdkpi\_final t(\"${dtype}\",\"${dstar0mode}\",\"${d0mode}\",\"${sigtype}\",\"analysis-50\"); \n";
			    print OUTRUN " t.LoopBest(\"${KorPi}\",$cutcode); \n";
			    print OUTRUN " t.Fits(\"${KorPi}\",$cutcode); \n";
			}
		    }
		}
	    }
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
	    $command = "root -l -b -q $file_outrun > $file_outlog ";
	    print " $command  \n";
	    system($command);
	}
    }
}







