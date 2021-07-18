def solution(prices):
    answer = []
    
    for i in range(len(prices)):
        count = 0 #가격 떨어지는 기간
        for j in range(i+1,len(prices)):
            if prices[i]<=prices[j]:
                count += 1
            # 3 -> 2 : 떨어지는데 1일이 걸렸다고 판단
            else:
                count += 1
                break
        answer.append(count)
    return answer
