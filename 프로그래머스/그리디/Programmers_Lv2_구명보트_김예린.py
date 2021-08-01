# Greedy
def solution(people, limit):
    answer = 0
    # people 몸무게 순으로 정렬
    people = sorted(people)
    left = 0 # 오름차순
    right = len(people) - 1 # 내림차순
    # L이 R보다 작을 때까지만 loop
    while left < right:
      # people[left]와 people[right]를 합해서 limit 이하면 둘이 탑승 가능
      # 따라서 L과 R 이동
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
        # else면 한 사람만 탑승 가능하니까 (무거운) R만 이동
        else:
            right -= 1
        answer += 1 # 경우의 수 증가

    if left == right:
        answer += 1
    
    return answer
