import sys

input = sys.stdin.readline

dwarfs = [int(input()) for _ in range(9)]

fakes = sum(dwarfs) - 100

find = False
for i in range(8):
    if find:
        break
    for j in range(i + 1, 9):
        if dwarfs[i] + dwarfs[j] == fakes:
            dwarfs.pop(j)
            dwarfs.pop(i)
            find = True
            break

print('\n'.join(map(str, dwarfs)))
