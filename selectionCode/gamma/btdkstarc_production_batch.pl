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


print "D0a1 control sample (no/yes)? \n";
$CS = <STDIN>;
chop $CS;
if ($CS eq "") {$CS = "no";}
print "$CS \n";


if ($CS eq "no") {

    @samples=(#"btdkstarc","btdkstarc1234","btdkstarc5",
	      "chb1","chb2","chb3","chb4","chb5",
	      "b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5",
	      "ccbar1","ccbar2","ccbar3","ccbar4","ccbar5",
	      "uds1","uds2","uds3","uds4","uds5"
	      #"On1","On2","On3","On4","On5",
	      #"Off1234","Off5"
	      );

} else {

    @samples=(
	      #"btda1",
	      #"On1","On2","On3","On4","On5",
	      "chb1","chb2","chb3","chb4","chb5",
	      "chbR1","chbR2","chbR3","chbR4","chbR5",
	      "chbNR1","chbNR2","chbNR3","chbNR4","chbNR5",
	      "b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5",
	      "ccbar1","ccbar2","ccbar3","ccbar4","ccbar5",
	      "uds1","uds2","uds3","uds4","uds5"
	      #"Off1234","Off5"
	      );


    #@samples=("On1","On2","On3","On4","On5");
    #@samples=("ccbar1","ccbar2","ccbar3","ccbar4","ccbar5");
}
@dmodes=("kspipi");


foreach $dmode (@dmodes) {
    foreach $sample (@samples) {
	if ($CS eq "yes") {
	    $jobname="btda1\_${dmode}\_${sample}";
	} else {
	    $jobname="btdkstarc\_${dmode}\_${sample}";
	}
        $file_outrun="log/${jobname}.C";
        $file_outbatch="log/${jobname}.csh";
        $file_outlog="log/${jobname}.log";

	open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	print OUTRUN "{ \n";
	print OUTRUN " gROOT->ProcessLine(\".L btdkstarc.C+\"); \n";
	if ($CS eq "no") {
	    print OUTRUN " btdkstarc t(\"${sample}\",\"${dmode}\",0,\"analysis-30\"); \n";
	} else {
	    print OUTRUN " btdkstarc t(\"${sample}\",\"${dmode}\",0,\"analysis-30\",kTRUE); \n";
	}
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






