from collections import deque

n = int(input())
case = deque(map(int, input().split()))
card = list(range(1,n+1))
deque1 = deque()

for i in range(len(card)):
    tech = case.pop()
    if tech == 1:
        deque1.appendleft(card[i])
    elif tech == 2:
        deque1.insert(1, card[i])
    elif tech == 3 :
        deque1.append(card[i])

print(*deque1)
