

$data_file = $ARGV[ 0 ];
open( DAT, $data_file );

while( $line = <DAT> )
{
    $index = ++$index % 10;
    
    $lines[ $index ] = $line;

    if ( $index eq 0 )
    {
	@out = split(" ",$lines[ 9 ]);

	if( $out[ 1 ] eq $ARGV[ 1 ])
	{
	    if ( $lines[ 8 ] =~ 'first' )
	    {
		push ( @decayChain, $lines[ 6 ] );
	    }
	    else
	    {
		push ( @decayChain, $lines[ 7 ] );
	    }
	}
    }
}

close( DAT );


foreach $decay ( @decayChain )
{
    $count{ $decay }++;
}

$tot = 0;
foreach $decay ( sort keys %count )
{
 $tot += $count{$decay};
}

print "$tot   Total \n";

foreach $decay ( sort keys %count )
{
    print "$count{$decay}    $decay \n";
}



#perl bkgCharacterization.pl example.study | ./toLaTeX
