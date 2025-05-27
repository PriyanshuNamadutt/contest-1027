t = int( input() )
for i in range( 0 , t ) :
    num = int( input() )
    a = int( pow( num , 0.5) )

    if ( a*a != num ) :
        print(-1)
    else:
        print( 0 , a )    
