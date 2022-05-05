import sys
input = sys.stdin.readline

T = int(input().rstrip())
for i in range(T):
    N = int(input().rstrip())
    memo1 = {num for num in map(int, input().split())}
    M = int(input().rstrip())
    for num in map(int, input().split()):
        print(1 if num in memo1 else 0)
