def solve( mn , k , n ) :
    it = int( mn/2 ) + 1
    start = n if mn % 2 == 0 else n-1
    for _ in range ( 0 , it ) :
        if ( start == k ):
            return True
        start -= 2    

    return False    

t = int(input())
for _ in range( 0 , t) :
    n, k = map(int, input().split())
    s = input()
    
    cnt = s.count('1')

    if ( solve( min( cnt , n - cnt) , k , n/2 ) == True ):
        print("YES" )
    else :
        print("NO")            
