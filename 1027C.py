t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    prev = -1
    cnt = 0
    for el in a:
        if ( el - prev > 1 ):
            prev = el
            cnt += 1

    print( cnt )
  
