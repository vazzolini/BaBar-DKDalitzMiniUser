#!/usr/bin/perl 

print "Running mode: batch/interactive ";
$run_mode = <STDIN>;
chop $run_mode;
if ($run_mode eq "") {$run_mode = "batch";}
print "$run_mode \n";

if ($run_mode eq "batch"){
    if ($ENV{BFSITE} eq "slac"){
	print "You are running at SLAC \n";
	print "Queue name: xlong, medium, kanga, long ";
	$queue = <STDIN>;
	chop $queue;
	if ($queue eq "") {$queue = "xlong";}
	print "$queue \n";
	print "Privileges: \n";
	$privileges = <STDIN>;
	chop $privileges; 
    } else {
	die "Can only run at SLAC $!\n";
    }
}

#@sigtypes=("btdk","btdsk","btdpi","btdspi","chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar","on","off");
#@sigtypes=("btdk","btdsk","btdpi","btdspi");
#@sigtypes=("chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar");
@samples=(#"on1",
	  # "on2",
	  # "on3",
	   "on4",
	  # "on5",
	 #  "on6",
	 #  "on7"
#,"off"
);
#@sigtypes=("btdk","chb","chbk","chbpi","b0b0bar","ccbar","uds","bbbar","udsccbar","on");
#@sigtypes=("btdk","chb","chbk","chbpi","b0b0bar","ccbar","uds","on");
#@d0modes=("kspipi","kskk");
#@d0modes=("kspipi");
@d0modes=("kskk");

#@dtypes=("Dstar0","D0");
@dtypes=("Dstar0");

#@dstar0modes=("d0pi0","d0gam","d0");
#@dstar0modes=("d0");




foreach $dtype (@dtypes) {
    foreach $sample (@samples) {
	foreach $d0mode (@d0modes) {
	    $jobname="vali\_${d0mode}\_${sample}\_${dtype}\_vali_new";
	    $file_outrun="log/${jobname}.C";
	    $file_outbatch="log/${jobname}.csh";
	    $file_outlog="log/${jobname}.log";
	    
	    open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	    print OUTRUN "{ \n";
	    print OUTRUN " gROOT->ProcessLine(\".L vali1.C+\"); \n";
	    print OUTRUN " gROOT->Reset(); \n";
	    print OUTRUN " vali1 t(\"${d0mode}\",\"${dtype}\",\"${sample}\"); \n";
	    print OUTRUN " t.Loop(); \n";
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
    
}





