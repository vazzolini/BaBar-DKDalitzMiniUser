#!/usr/bin/perl 
#It launch the final production for btdkstarc and btdkpi analysis.
# coment only in the arrays of signals to avoid a complete run


#library managment
print "Clean libraries (no/yes):";
$libRemove = <STDIN>;
chop $libRemove;
if($libRemove eq ""){$libRemove eq "no";}
if($libRemove eq "yes"){
    $removeLibraries = "rm -f *.so";
    system($removeLibraries);
}

#cut code
print "Cut wanted separated by \"-\" or press return for the 4 main cuts:\n";
$cutCode = <STDIN>;
chop $cutCode;

@availableCutCodes = ("1","2","100","112");
@ourCutCodes = ();
if ($cutCode eq ""){
    @ourCutCodes = @availableCutCodes;
}else{
    @cutCodesStringSplit = split(/-/,$cutCode);
    $m = scalar @cutCodesStringSplit;
    print "$m";
    for ( $n = 0 ; $n < $m ; $n++){
	$ourCutCodes[$n] = $cutCodesStringSplit[$n];
    }
}
print "The cut-codes selected are:\n \n";
foreach $ourCutCode (@ourCutCodes){
    print "$ourCutCode \n";
}
print"\n\n"; 

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
		 #1100,     # 1) B->D0K, D0->kspipi
		 #1200,     # 2) B->D0K, D0->kskk
		 #2100,     # 3) B->D0pi, D0->kspipi
		 #2200,     # 4) B->D0pi, D0->kskk
		 #3110,     # 5) B->D*0k, D*0->D0pi0, D0->kspipi
		 #3120,     # 6) B->D*0k, D*0->D0gam, D0->kspipi
		 #3210,     # 7) B->D*0k, D*0->D0pi0, D0->kskk
		 #3220,     # 8) B->D*0k, D*0->D0gam, D0->kskk
		 #4110,     # 9) B->D*0pi, D*0->D0pi0, D0->kspipi
		 #4120,     # 10) B->D*0pi, D*0->D0gam, D0->kspipi
		 #4210,     # 11) B->D*0pi, D*0->D0pi0, D0->kskk
		 #4220,     # 12) B->D*0pi, D*0->D0gam, D0->kskk
		 #5101,     # 13) B->D0k*, k*->kspi, D0->kspipi
		 6100,     # 14)D*->D0pi, D0->kspipi
		 6200      # 15)D*->D0pi, D0->kskk
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
    
    if($channelCode==1100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
	@availableChannels=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 2) B->D0K, D0->kskk
    
    elsif($channelCode==1200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
	@availableChannels=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 3) B->D0pi, D0->kspipi
    
    if($channelCode==2100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
	@availableChannels=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 4) B->D0pi, D0->kskk
    
    if($channelCode==2200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
	@availableChannels=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 5) B->D*0k, D*0->D0pi0, D0->kspipi
    
    if($channelCode==3110){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
	@availableChannels=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 6) B->D*0k, D*0->D0gam, D0->kspipi
    
    if($channelCode==3120){
	$ddecay = "kspipi";
	$dtype = "Dstar0";{
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkstarc";
	@availableChannels=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off","udsccbar","bbbar");
	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off");
    }
	$KorPi = "k";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
	@availableChannels=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 7) B->D*0k, D*0->D0pi0, D0->kskk
    
    if($channelCode==3210){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
	@availableChannels=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 8) B->D*0k, D*0->D0gam, D0->kskk
    
    if($channelCode==3220){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
	@availableChannels=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 9) B->D*0pi, D*0->D0pi0, D0->kspipi
    
    if($channelCode==4110){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
	@availableChannels=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 10) B->D*0pi, D*0->D0gam, D0->kspipi
    
    if($channelCode==4120){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
	@availableChannels=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 11) B->D*0pi, D*0->D0pi0, D0->kskk
    
    if($channelCode==4210){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
	@availableChannels=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 12) B->D*0k, D*0->D0gam, D0->kskk
    
    if($channelCode==4220){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
	@availableChannels=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
    }
    
# 13) B->D0k*, k*->kspi, D0->kspipi
    
    if($channelCode==5101){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkstarc";
	@availableChannels=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off","udsccbar","bbbar");
	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off");
    }

# 14) D*->D0pi,  D0->kspipi
    
    if($channelCode==6100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "inclDstar";
	@availableChannels=("signal","On","signalm","signalp","On5");
	@availableChannelsUsual=("signal","On","signalm","signalp");
    }

# 15) D*->D0pi,  D0->kskk
    
    if($channelCode==6200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "inclDstar";
	@availableChannels=("signal","On","signalm","signalp","On5");
	@availableChannelsUsual=("signal","On","signalm","signalp");
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
	print "dtype      : $dtype \n";
	print "KorPi      : $KorPi \n";
	print "dstar0mode : $dstar0mode \n";
	print "macroFile  : $macroFile \n";


	print "********************************************\n";
   
# Creating main macro
	
	if($macroFile eq "btdkstarc"){
	    if($flag eq ""){
		$jobname="${macroFile}\_kspi\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_kspi\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	if($macroFile eq "btdkpi"){	    
	    if($flag eq ""){
		$jobname="${macroFile}\_${KorPi}\_${ddecay}\_${dstar0mode}\_${dtype}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${KorPi}\_${ddecay}\_${dstar0mode}\_${dtype}\_${ourChannel1}\_${flag}";
	    }
	}
	if($macroFile eq "inclDstar"){	    
	    if($flag eq ""){
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_${ddecay}\_${ourChannel1}\_${flag}";
	    }
	}
	

	$file_outrun="ASCIIlog/${jobname}.C";
	$file_outbatch="ASCIIlog/${jobname}.csh";
	$file_outlog="ASCIIlog/${jobname}.log";
	
	print "$jobname : nombre del job \n"; 

	open (OUTRUN,">$file_outrun") || die "cannot open ${file_outrun} : $!\n";
	print OUTRUN "{ \n";
	print OUTRUN " gROOT->ProcessLine(\".L ${macroFile}\_final.C+\"); \n";
	if($macroFile eq "btdkstarc"){
	    print OUTRUN " ${macroFile}\_final t(\"kspi\",\"${ddecay}\",\"${ourChannel1}\",\"analysis-30\",kFALSE); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
	    #foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
	}
	if($macroFile eq "btdkpi"){
	    print OUTRUN " ${macroFile}\_final t(\"${dtype}\",\"${dstar0mode}\",\"${ddecay}\",\"${ourChannel1}\",\"analysis-32\"); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest(\"${KorPi}\",$cutcode); \n";}
	    #foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits(\"${KorPi}\",$cutcode); \n";}
	}
	if($macroFile eq "inclDstar"){
	    print OUTRUN " ${macroFile}\_final t(\"${ddecay}\",\"${ourChannel1}\"); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
	   # foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
	} 

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
	sleep(5);
    }
}

print "-------------------------------------\n";
print "-------------------------------------\n\n";
print " SUBMITED $k2 JOBS \n\n";
print "-------------------------------------\n";
print "-------------------------------------\n";
