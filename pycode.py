t = int(input())
for _ in range(t):
    n = int(input())
    arr = input().split(" ")
    #print(arr)
    for i in range(n):
        arr[i] = int(arr[i])
    
    num = 0
    mul = 1;
    for i in range(n):
        num = num + arr[i]*mul
        #print("->",num)
        mul = mul*2
    #print(num)
    
    if(num==0):
        print(0)
        continue
    
    
    arr2 = []
    while(num>0):
        arr2.append(num%6)
        num = num//6
    
    for i in range(len(arr2)):
        print(arr2[i],end=" ")
    print()