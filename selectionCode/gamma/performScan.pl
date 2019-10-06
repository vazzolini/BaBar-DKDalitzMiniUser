#!/usr/bin/perl 
# be sure that you're using bkgCharacterization.pl and toLaTeX



@d0modes = ("kspipi","kskk");
@modes = ("d0","d0pi0","d0gam");
@prompts = ("k","pi");
@samples = ("chb","b0b0bar");
@bkgTypes = (
	     "MES Signal like",
	     "MES Almost signal like",
	     "MES Peaking combinatorial",
	     "MES Generic combinatorial",
	     "DE Signal like",
	     "DE Almost signal like",
	     "DE Peaking combinatorial",
	     "DE Generic combinatorial"
	     );

#$inputFolder = "prod-32-skim18c/ASCII/ASCII-NEW/PLOTS/";
$inputFolder = "ASCII/";
$outputFolder = "SCAN/";
$latexFile = "${outputFolder}bkg_Char.tex";

open(OUTFILE,">$latexFile") || die "cannot open $latexFile \n";

print OUTFILE "\\documentclass\[10pt\]\{article\} \n";
print OUTFILE "\\usepackage\{graphicx\} \n";
print OUTFILE "\\usepackage\{amsmath,amssymb\} \n";
print OUTFILE "\\usepackage\{amsfonts\} \n";

print OUTFILE "\\oddsidemargin  -0.7in \n";
print OUTFILE "\\evensidemargin 0.0in \n";
print OUTFILE "\\textwidth      7.0in \n";
print OUTFILE "\\headheight     0.0in \n";
print OUTFILE "\\topmargin      -0.5in \n";
print OUTFILE "\\textheight     9.0in \n";

print OUTFILE "\\begin\{document\} \n";
print OUTFILE "\\tiny \n";

foreach $prompt(@prompts){
    foreach $mode(@modes){
	foreach $d0mode(@d0modes){
	    foreach $sample(@samples){
		print OUTFILE "\\section\{ ${mode}${prompt}, $d0mode, $sample \}\n ";
		foreach $bkgType(@bkgTypes){
		
		    if($mode eq "d0"){
			if($bkgType eq "MES Signal like"){@codes = ("16641");}
                        elsif($bkgType eq "MES Almost signal like"){@codes = ("257");}
                        elsif($bkgType eq "MES Peaking combinatorial"){@codes = ("2");}
                        elsif($bkgType eq "MES Generic combinatorial"){@codes = ("4","8");}
                        elsif($bkgType eq "DE Signal like"){@codes = ("17153");}
                        elsif($bkgType eq "DE Almost signal like"){@codes = ("769");}
                        elsif($bkgType eq "DE Peaking combinatorial"){@codes = ("514");}
                        elsif($bkgType eq "DE Generic combinatorial"){@codes = ("516");}
#			else die "Never should arrive at this point. \n";
		    }else{
                        if($bkgType eq "MES Signal like"){@codes = ("16769");}
                        elsif($bkgType eq "MES Almost signal like"){@codes = ("16385","1","385");}
                        elsif($bkgType eq "MES Peaking combinatorial"){@codes = ("2","130");}
                        elsif($bkgType eq "MES Generic combinatorial"){@codes = ("4","8");}
                        elsif($bkgType eq "DE Signal like"){@codes = ("17281");}
                        elsif($bkgType eq "DE Almost signal like"){@codes = ("16897","513","897");}
                        elsif($bkgType eq "DE Peaking combinatorial"){@codes = ("514","642");}
                        elsif($bkgType eq "DE Generic combinatorial"){@codes = ("516");}
#			else die "Never should arrive at this point. \n";
		    }

		    foreach $code ( @codes ){
			
			
			print OUTFILE "\\subsection\{ $bkgType, \( code: $code \)\} \n";
			
			print "$d0mode, $prompt, $mode, $sample, $bkgType \( code: $code \) \n\n";
			
			$mainString = "bkg_MC_${mode}${prompt}_${d0mode}_${sample}_Bbest_Cut100";
			$logFile = "${outputFolder}${mainString}_${code}.log";
			$studyFile = "${inputFolder}${mainString}.study";
			
			
			
			$command = "perl bkgCharacterization.pl ${studyFile} ${code} | toLaTeX > ${logFile}";
			system($command);
			
			open(INFILE1,$logFile) || die "cannot open $logFile";
			
			print OUTFILE "\\begin\{center\} \n";
			print OUTFILE "\\begin\{tabular\}\{||c||c||\} \n";
			print OUTFILE "\\hline \\hline \n";
			print OUTFILE "N \& Channel \\cr \n";
			print OUTFILE "\\hline \\hline \n";

			while($line=<INFILE1>){
			    chop $line;
			    $nEv = substr($line,0,5);
			    $channel = substr($line,5);
			    
			    print OUTFILE "$nEv \&  \$ $channel \$  \\cr \n";
			}
			close(INFILE1);

			print OUTFILE "\\hline \\hline \n";
			print OUTFILE "\\end\{tabular\} \n";
			print OUTFILE "\\end\{center\} \n";
			print OUTFILE "\n";
			
			
			
		    }#code
		    }#bkgtype
		    
		    
		}#samples	
	    }#d0modes
	}#modes
    }#prompts
    
    
    print OUTFILE "\\end\{document\} \n";

    close(OUTFILE);
