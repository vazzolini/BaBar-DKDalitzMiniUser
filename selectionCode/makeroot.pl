#!/usr/bin/perl 

# execution example
# perl summer05/makeroot.pl 1 10 SP-uds-BFourHHHK-Run4-R14-

$init=shift(@ARGV);
$ntot=shift(@ARGV);
$prefix=shift(@ARGV);

for ($i=$init; $i < ($init+$ntot) ; $i++){
    $command = "h2root ${prefix}${i}.breco.hbook";
    print "$command \n";
    system($command);
}
