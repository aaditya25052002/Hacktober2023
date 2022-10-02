# cook your dish here
t = int(input())

for i in range(t):
    s, st = map(int, input().split())
    
    if st > s:
        print(st - s)
    else:
        print("0")
