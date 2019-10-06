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

#@availableCutCodes = ("1","2","100","112");
#@availableCutCodes = ("0","101","102","103","104","105","106","107","108","109","110","111","112","113","114");
#@availableCutCodes = ("108","109","110","111","112","113","114");
#@availableCutCodes = ("112","113","114");
@availableCutCodes = ("1","2");
@ourCutCodes = ();
if ($cutCode eq ""){
    @ourCutCodes = @availableCutCodes;
}else{
    @cutCodesStringSplit = split(/-/,$cutCode);
    $m = scalar @cutCodesStringSplit;
#    print "$m";
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
#	 	 1100,     # 1) B->D0K, D0->kspipi
		 1200,     # 2) B->D0K, D0->kskk
#		 2100,     # 3) B->D0pi, D0->kspipi
		 2200,     # 4) B->D0pi, D0->kskk
	##
#		 3110,     # 5) B->D*0k, D*0->D0pi0, D0->kspipi
#		 3120,     # 6) B->D*0k, D*0->D0gam, D0->kspipi
		 3210,     # 7) B->D*0k, D*0->D0pi0, D0->kskk
		 3220,     # 8) B->D*0k, D*0->D0gam, D0->kskk
	
#		 4110,     # 9) B->D*0pi, D*0->D0pi0, D0->kspipi
#		 4120,     # 10) B->D*0pi, D*0->D0gam, D0->kspipi
		 4210,     # 11) B->D*0pi, D*0->D0pi0, D0->kskk
		 4220,     # 12) B->D*0pi, D*0->D0gam, D0->kskk
#	
#		 5101,    # 13) B->D0k*, k*->kspi, D0->kspipi
#		 5102     # 13) B->D0k*, k*->kspi, D0->kskk
	#	 5103     # 13) B->D0a1
                 #6100     # 14)D*->D0pi, D0->kspipi
		 #6200      # 15)D*->D0pi, D0->kskk
		 #7100,     # 16)D*->D0pi, D0->kspipi mixing
		 #7200      # 17)D*->D0pi, D0->kskk mixing
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
#	@availableChannels=("btdk","btdk1234","btdk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
#	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdk","chb","b0b0bar","ccbar","uds");
	@availableChannelsUsual=("on");
#	@availableChannelsUsual=("ccbar","uds","off");
#	@availableChannelsUsual=("b0b0bar")
#	@availableChannelsUsual=("btdk")
    }
    
# 2) B->D0K, D0->kskk
    
    elsif($channelCode==1200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdk","btdk1234","btdk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdk","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("on");

    }
    
# 3) B->D0pi, D0->kspipi
    
    if($channelCode==2100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdpi","btdpi1234","btdpi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdpi","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdpi");

    }
    
# 4) B->D0pi, D0->kskk
    
    if($channelCode==2200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdpi","btdpi1234","btdpi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdpi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdpi","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdpi");
    }
    
# 5) B->D*0k, D*0->D0pi0, D0->kspipi
    
    if($channelCode==3110){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdsk","btdsk1234","btdsk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdsk","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdsk");
    }
    
# 6) B->D*0k, D*0->D0gam, D0->kspipi
    
    if($channelCode==3120){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
#	@availableChannels=("btdsk","btdsk1234","btdsk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdsk","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdsk");
    }
    
# 7) B->D*0k, D*0->D0pi0, D0->kskk
    
    if($channelCode==3210){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdsk","btdsk1234","btdsk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdsk","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdsk");
    }
    
# 8) B->D*0k, D*0->D0gam, D0->kskk
    
    if($channelCode==3220){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "k";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
#	@availableChannels=("btdsk","btdsk1234","btdsk5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdsk","on","chb","b0b0bar","ccbar","uds","chbpi");
#	@availableChannelsUsual=("btdsk","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("chb");
#	@availableChannelsUsual=("chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdsk");
    }
    
# 9) B->D*0pi, D*0->D0pi0, D0->kspipi
    
    if($channelCode==4110){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdspi","btdspi1234","btdspi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdspi","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdspi");
    }
    
# 10) B->D*0pi, D*0->D0gam, D0->kspipi
    
    if($channelCode==4120){
	$ddecay = "kspipi";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
#	@availableChannels=("btdspi","btdspi1234","btdspi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdspi","chb","b0b0bar","ccbar","uds"); 
#	@availableChannelsUsual=("btdspi"); 
   }
    
# 11) B->D*0pi, D*0->D0pi0, D0->kskk
    
    if($channelCode==4210){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0pi0";
	$macroFile = "btdkpi";
#	@availableChannels=("btdspi","btdspi1234","btdspi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdspi","chb","b0b0bar","ccbar","uds"); 
# 	@availableChannelsUsual=("btdspi"); 
   }
    
# 12) B->D*0pi, D*0->D0gam, D0->kskk
    
    if($channelCode==4220){
	$ddecay = "kskk";
	$dtype = "Dstar0";
	$KorPi = "pi";
	$dstar0mode = "d0gam";
	$macroFile = "btdkpi";
#	@availableChannels=("btdspi","btdspi1234","btdspi5","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk","udsccbar","bbbar");
	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","off","chbpi","chbk");
#	@availableChannelsUsual=("btdspi","on","chb","b0b0bar","ccbar","uds","chbk");
#	@availableChannelsUsual=("btdspi","chb","b0b0bar","ccbar","uds"); 
#	@availableChannelsUsual=("btdspi");
    }
    
# 13) B->D0k*, k*->kspi, D0->kspipi
    
    if($channelCode==5101){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkstarc";
#	@availableChannels=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off","udsccbar","bbbar");
	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off");
#	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds");
#        @availableChannelsUsual=("btdkstarc","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdkstarc");
    }

# 13b) B->D0k*, k*->kspi, D0->kskk
    
    if($channelCode==5102){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btdkstarc";
#	@availableChannels=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off","udsccbar","bbbar");
	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds","Off");
#	@availableChannelsUsual=("btdkstarc","On","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdkstarc","chb","b0b0bar","ccbar","uds");
#	@availableChannelsUsual=("btdkstarc");
    }

#13b) B->D0k*, k*->kspi, D0->kskk
    
    if($channelCode==5103){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "k";
	$dstar0mode = "d0";
	$macroFile = "btda1";
	@availableChannels=("btda1");
	@availableChannelsUsual=("On");
    }

# 14) D*->D0pi,  D0->kspipi
    
    if($channelCode==6100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "inclDstar";
	@availableChannels=("signal","On","signalm","signalp","On5","uds","ccbar","chb","b0b0bar");
	@availableChannelsUsual=("signal","On","signalm","signalp","uds","ccbar","chb","b0b0bar");
    }

# 15) D*->D0pi,  D0->kskk
    
    if($channelCode==6200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "inclDstar";
	@availableChannels=("signal","On","signalm","signalp","On5","uds","ccbar","chb","b0b0bar");
	@availableChannelsUsual=("signal","On","signalm","signalp","uds","ccbar","chb","b0b0bar");
    }
# 16) D*->D0pi,  D0->kspipi mixing
    
    if($channelCode==7100){
	$ddecay = "kspipi";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "d0mixDalitz";
	@availableChannels=("signal","On","signalm","signalp","On5","uds","ccbar","chb","b0b0bar","signalMatch");
	@availableChannelsUsual=("signal","On","signalm","signalp","uds","ccbar","chb","b0b0bar");
    }

# 17) D*->D0pi,  D0->kskk mixing
    
    if($channelCode==7200){
	$ddecay = "kskk";
	$dtype = "D0";
	$KorPi = "pi";
	$dstar0mode = "d0";
	$macroFile = "d0mixDalitz";
	@availableChannels=("signal","On","signalm","signalp","On5","uds","ccbar","chb","b0b0bar");
	@availableChannelsUsual=("signal","On","signalm","signalp","uds","ccbar","chb","b0b0bar");
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
	if($macroFile eq "btda1"){
	    if($flag eq ""){
		$jobname="${macroFile}\_rho0pi\_${ddecay}\_${ourChannel1}";
	    }else{
		$jobname="${macroFile}\_rho0pi\_${ddecay}\_${ourChannel1}\_${flag}";
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
	if($macroFile eq "d0mixDalitz"){	    
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


	print OUTRUN " gROOT->ProcessLine(\".L ${macroFile}\_final\_C.so\"); \n";





	if($macroFile eq "btdkstarc"){
	    print OUTRUN " ${macroFile}\_final t(\"kspi\",\"${ddecay}\",\"${ourChannel1}\",\"analysis-51\",kFALSE); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
	    #foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
	}
	if($macroFile eq "btda1"){
	    print OUTRUN "btdkstarc\_final t(\"rho0pi\",\"${ddecay}\",\"${ourChannel1}\",\"analysis-51\",kTRUE); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
	    #foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
	}
	if($macroFile eq "btdkpi"){
	    print OUTRUN " ${macroFile}\_final t(\"${dtype}\",\"${dstar0mode}\",\"${ddecay}\",\"${ourChannel1}\",\"analysis-51\"); \n";
#	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.Loop(\"${KorPi}\",$cutcode); \n";}
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest(\"${KorPi}\",$cutcode); \n";}
	    #foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits(\"${KorPi}\",$cutcode); \n";}
	}
	if($macroFile eq "inclDstar"){
	    print OUTRUN " ${macroFile}\_final t(\"${ddecay}\",\"${ourChannel1}\"); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
	   # foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
	} 
	if($macroFile eq "d0mixDalitz"){
	    print OUTRUN " ${macroFile}\_final t(\"${ddecay}\",\"${ourChannel1}\"); \n";
	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.LoopBest($cutcode); \n";}
#	    foreach $cutcode(@ourCutCodes){print OUTRUN " t.Fits($cutcode); \n";}
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
	#sleep(5);
    }
}

print "-------------------------------------\n";
print "-------------------------------------\n\n";
print " SUBMITED $k2 JOBS \n\n";
print "-------------------------------------\n";
print "-------------------------------------\n";
