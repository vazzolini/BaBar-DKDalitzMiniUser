

foreach $argnum ( 0 .. $#ARGV )
{
    $data_file=$ARGV[ $argnum ];
    open( DAT, $data_file );

    while( $line = <DAT> )
    {
	$index = ++$index % 10;

	$lines[ $index ] = $line;

	if ( $index eq 0 )
	{
	    if ( $lines[ 9 ] =~ '516' )
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
}

print sort @decayChain;
