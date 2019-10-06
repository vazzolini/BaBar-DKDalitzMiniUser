#!/usr/bin/perl 

if ($ENV{BFSITE} eq "slac"){
    print "You are running at SLAC \n";
    print "Queue name: kanga, xlong, long, medium ";
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

@samples=(##############   Signal
	  #"btdk1","btdk2","btdk3",
	  #"btdk4","btdk5","btdk6",
	  #"btdsk1","btdsk2","btdsk3","btdsk4","btdsk5","btdsk6",
	  #"btdpi1","btdpi2",
	  #"btdpi3",
          #"btdpi4",
	  #"btdpi5","btdpi6",
	  #"btdspi1","btdspi2","btdspi3","btdspi4","btdspi5","btdspi6",
	                 
	  ##############   BKG
	  #"chb1","chb2","chb3","chb4","chb5","chb6",
	  #"chbk1234","chbk56",
	  #"chbpi1234","chbpi56",
	  #"b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5","b0b0bar6",
	  #"ccbar1","ccbar2","ccbar3","ccbar4","ccbar5","ccbar6",
	  #"uds1","uds2","uds3","uds4","uds5","uds6",
	  #"b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar6",
	  "on1","on2","on3","on4","on5","on6"
	  #"off1","off2","off3","off4","off5","off6"
	  );


@dmodes=(#
	 "kspipi",
	 "kskk"
	 );

foreach $dmode (@dmodes) {
    foreach $sample (@samples) {
	$jobname="btdkpi\_${dmode}\_${sample}";
        $file_outrun="log/${jobname}.C";
        $file_outbatch="log/${jobname}.csh";
        $file_outlog="log/${jobname}.log";

	open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	print OUTRUN "{ \n";
	print OUTRUN " gROOT->ProcessLine(\".L btdkpi.C+\"); \n";
	print OUTRUN " btdkpi t(\"${sample}\",\"${dmode}\",0,\"analysis-51\"); \n";
	print OUTRUN " t.Loop(); \n";
	print OUTRUN "} \n";
	close OUTRUN;

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
	
    }
}






