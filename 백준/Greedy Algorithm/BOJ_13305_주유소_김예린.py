city = int(input())
km = list(map(int, input().split()))
price = list(map(int, input().split()))

sum = km[0]*price[0]
min = price[0] # version 2

for i in range(1, len(km)):
    # version 1
    # 도로 단위로 price list 만들어서 sort
    # case = sorted(price[0:i+1])
    # sort 했으니까 가장 앞의 원소가 min값
    # sum += km[i]*case[0] 

    #version 2
    if min > price[i]:
        min = price[i]

    sum += km[i] * min

print(sum)
