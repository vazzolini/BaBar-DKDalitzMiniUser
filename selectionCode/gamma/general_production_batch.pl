#!/usr/bin/perl 
#It launch the final production for btdkstarc and btdkpi analysis.
# coment only in the arrays of signals to avoid a complete run

#flagstring for log files
print "Any suffix in the log files?: \n";
$flag = <STDIN>;
chop $flag;  


#launching conditions
print "Running mode: batch/interactive (batch for default) \n";
$run_mode = <STDIN>;
chop $run_mode;
if ($run_mode eq "") {$run_mode = "batch";}
print "$run_mode \n";

if ($run_mode eq "batch"){
    
    print "Queue name: long, medium, kanga, xlong (long queue for default)";
    $queue = <STDIN>;
    chop $queue;
    if ($queue eq "") {$queue = "long";}
    print "$queue \n"; 
}
$k2=0;


# Defining conditions for the 13 channels to study
#Modify these conditions under your own risk


@channelCodes = (
	#	 1,     # 1) B->D0K, D0->kspipi
		# 2      # 2) B->D0K, D0->kskk
		 3,   # 3) B->D0K*, D0->kspipi
		 4     #3) B->D0K*, D0->kskk
		 );
foreach $channelCode (@channelCodes){
    print "**************************************************************************\n";
    print "**************************************************************************\n";
    print "**************************************************************************\n";
    print "processing channel ${channelCode}.\n";
    print "**************************************************************************\n";
    print "**************************************************************************\n";
    print "**************************************************************************\n";

# 1) B->D0K, D0->kspipi
    
    if($channelCode==1){
	$ddecay = "kspipi";
	$macroFile = "btdkpi";
	@availableChannels=(#"btdk","btdk1","btdk2","btdk3","btdk4","btdk5","btdk6",
#			    
			    );
	@availableChannelsUsual=(
				 "btdk1","btdk2","btdk3","btdk4","btdk5","btdk6",
				 "btdsk1","btdsk2","btdsk3","btdsk4","btdsk5","btdsk6",
			#	 "btdpi1","btdpi2","btdpi3","btdpi4","btdpi5","btdpi6",
			#	 "btdspi1","btdspi2","btdspi3","btdspi4","btdspi5","btdspi6",
	#			 "on","on1","on2","on3","on4","on5","on6",
	#			 "off1","off2","off3","off4","off5","off6",
			#	 "chb1","chb2","chb3","chb4","chb5","chb6",
				 "chbk1234","chbk56",
			#	 "chbpi1234","chbpi56",
#				 "b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5","b0b0bar6",
				# "uds4_v02","uds4_v03","uds5_v02","uds5_v03"
	#			 "ccbar1","ccbar2","ccbar3","ccbar6",
#				 "ccbar4_1","ccbar5_1","ccbar4_29","ccbar5_29"
				 );
    }
    
# 2) B->D0K, D0->kskk
    
    elsif($channelCode==2){
	$ddecay = "kskk";
	$macroFile = "btdkpi";
	@availableChannels=(
			    );
	@availableChannelsUsual=("btdk6","btdk1","btdk2","btdk3","btdk4","btdk5",
				 "btdsk6","btdsk1","btdsk2","btdsk3","btdsk4","btdsk5",
				 #"btdpi6","btdpi1","btdpi2","btdpi3","btdpi4","btdpi5",
				 #"btdspi6","btdspi1","btdspi2","btdspi3","btdspi4","btdspi5",
				 #	    "on6","on1","on2","on3","on4","on5",
				 #	    "off6","off1","off2","off3","off4","off5",
#			    "chb6","chb1","chb2","chb3","chb4","chb5",
##			    "b0b0bar6","b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4",
#				 "b0b0bar5"
				 #		    "uds6","uds1","uds2","uds3","uds4","uds5",
				 
				 "chbk1234","chbk56",
				# "chbpi1234","chbpi56",
				 # "uds4_v02","uds4_v03","uds5_v02","uds5_v03"
			#	 "ccbar1","ccbar2","ccbar3","ccbar6",
			#	 "ccbar4_1","ccbar5_1","ccbar4_29","ccbar5_29"
				 );
    }
    
 # 3) B->D0K*, D0->kspipi
    
    if($channelCode==3){
	$ddecay = "kspipi";
	$macroFile = "btdkstarc";
	@availableChannels=(
			    );
	@availableChannelsUsual=(
			#	 "btda1",
			#	 "btdkstarc1","btdkstarc2","btdkstarc3","btdkstarc4","btdkstarc5","btdkstarc6",
			#	 "chb1","chb2","chb3","chb4","chb5","chb6",
			#	 "chbR1","chbR2","chbR3","chbR4","chbR5","chbR6",
			#	 "chbNR1","chbNR2","chbNR3","chbNR4","chbNR5","chbNR6",
			#	 "b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5","b0b0bar6",
			#	 "ccbar1","ccbar2","ccbar3","ccbar4","ccbar6",
 			#	 "uds1","uds2","uds3","uds4","uds5","uds6",
				# "On1","On2","On3","On4","On5","On6",		
			#	 "Off1","Off2","Off3","Off4","Off5","Off6"
				# "ccbar5_1","ccbar5_29"
			#	 "On5_24","On5_59"
				 "ccbar6"	
				 );
    }
    
    if($channelCode==4){
	$ddecay = "kskk";
	$macroFile = "btdkstarc";
	@availableChannels=(
			    );
	@availableChannelsUsual=(
			#	 "btdkstarc1","btdkstarc2","btdkstarc3","btdkstarc4","btdkstarc5","btdkstarc6",
			#	 "chb1","chb2","chb3","chb4","chb5","chb6",
			#	 "chbR1","chbR2","chbR3","chbR4","chbR5","chbR6",
			#	 "chbNR1","chbNR2","chbNR3","chbNR4","chbNR5","chbNR6",
			#	 "b0b0bar1","b0b0bar2","b0b0bar3","b0b0bar4","b0b0bar5","b0b0bar6",
			#	 "ccbar1","ccbar2","ccbar3","ccbar4","ccbar6",
			#	 "ccbar5_1",
			#	 "ccbar5_29",
			#	 "uds1","uds2","uds3","uds4","uds5","uds6"
			#	 "On1","On2","On3","On4_1","On4_29","On5_1","On5_29",		
			#	 "Off1","Off2","Off3","Off4","Off5","Off6"
				# "chb2","chbR1","chbR2","chb5","chbNR3","chbNR4","chbNR6","chbNR1"
				# "On5_24","On5_59","On4_24","On4_59"
		#		 "uds5","ccbar1","ccbar2"
				 "b0b0bar5"
				 );
    }
    


    print "Choose your channels for the final production!!\n";
    print "The available channels for this mode are:\n \n";
    $i=0;
    foreach $availableChannel (@availableChannels){
	print "${i} : $availableChannel \n";
	$i++;
    }
    print "\n";
    print "Make a combination of channel with the numbers separated by \"-\" or type \"all\" or return. \n";
#    $channelsString = "";     #comment this line and uncomment the next to lines for lauching just certain kind of sigtype and visceversa
    $channelsString = <STDIN>;
    chop $channelsString;
    @ourChannels = ();
    if (($channelsString eq "all") or $channelsString eq ""){
	@ourChannels=@availableChannelsUsual;
    }else{
	@channelsStringSplits = split(/-/,$channelsString);
	$j = scalar @channelsStringSplits;
	for ( $k = 0 ; $k < $j ; $k++){
	    $ourChannels[$k] = $availableChannels[$channelsStringSplits[$k]];
	}
    }
    print "The signal types selected are:\n \n";
    foreach $ourChannel (@ourChannels){
	print "$ourChannel \n";
    }
    print"\n\n";    
    
    foreach $ourChannel1 (@ourChannels){
	print "********************************************\n";
	print "...processing sigtype ${ourChannel1}.\n";
	print "your job look like \n";
	print "ddecay     : $ddecay \n";
	print "macroFile  : $macroFile \n";


	print "********************************************\n";
   
# Creating main macro
	
	if($macroFile eq "btdkstarc"){
	    if($flag eq ""){
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	if($macroFile eq "btdkpi"){	    
	    if($flag eq ""){
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	if($macroFile eq "inclDstar"){	    
	    if($flag eq ""){
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	if($macroFile eq "d0mixDalitz"){	    
	    if($flag eq ""){
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	

	$file_outrun="therootlog/${jobname}.C";
	$file_outbatch="therootlog/${jobname}.csh";
	$file_outlog="therootlog/${jobname}.log";
	
	print "$jobname : nombre del job \n"; 

	open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	print OUTRUN "{ \n";
	print OUTRUN " gROOT->ProcessLine(\".L ${macroFile}\_C.so\"); \n";

#	if($macroFile eq "btdkpi"){
	print OUTRUN " ${macroFile} t(\"${ourChannel1}\",\"${ddecay}\",0,\"analysis-51\"); \n";
	print OUTRUN " t.Loop(); \n";
	#}

	print OUTRUN "} \n";
	close OUTRUN;

#creating auxiliar files and sending the jobs

	open(BATCHSCRIPT,">$file_outbatch");
	print BATCHSCRIPT "#! /bin/csh \n";
	print BATCHSCRIPT "#BSUB -q $queue \n";
	print BATCHSCRIPT "#BSUB -J $jobname \n";
	print BATCHSCRIPT "#BSUB -o $file_outlog \n";
	print BATCHSCRIPT "root -l -b -q $file_outrun \n";
	close(BATCHSCRIPT);
	$command = "bsub < $file_outbatch ";
	$k2++;
	print " $command  \n";
	system($command);
    }
}

print "-------------------------------------\n";
print "-------------------------------------\n\n";
print " SUBMITED $k2 JOBS \n\n";
print "-------------------------------------\n";
print "-------------------------------------\n";
