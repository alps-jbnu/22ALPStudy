토론해볼만한 문제

## [왕위 계승](https://www.acmicpc.net/problem/5021)
왕의 피가 얼마나 섞였는지 묻는 문제  

**문제점**  
입력이 (offspring, parent1, parent2) 여러쌍이 주어진다.
주어지는 입력을 차례대로 해결한다면 너무 좋겠지만... 역시나 문제점이 있다.   

아래와 같이 주어질 때는 상관이 없다 (a가 b,c의 자식, 이후 입력에 a를 부모로 사용)
```
a b c
d a e
```

다음과 같은 입력은 문제가 된다 (a가 d의 부모이지만, 이후 입력에서 a가 자식인 경우가 존재)
```
d a e
a b c
```

이를 해결하기 위해 다음과 같이 해결했다.
1. 입력을 전부 받는다
2. 존재하는 모든 이름 name 에 대해 name이 offspring일 때, name이 이전 입력에서 parent로 쓰인적이 있는지 검토
3. 있다면 해당 입력을 parent로 쓰인 입력 바로 뒤로 이동시킴

```python3
for i in range(N):
    child = family[i][0]
    for j in range(i):
        p1, p2 = family[j][1:]
        if child == p1 or child == p2:
            f = family[j]
            family.pop(j)
            family.insert(i, f)
```

## [문자열 지옥에 빠진 호석](https://www.acmicpc.net/problem/20166)
대충 보면 BFS인줄 알았지만 전혀 아니였던 문제  
Size가 크지 않으므로 모든 경우의 수를 계산해본다.  
최대 문자열 길이 5, 가로 세로 각각 10, 문자열 개수 1000 이므로  
8^5 * 10 * 10 * 1000 = (약) 32억  

하지만, 매 방문마다 모든 process를 진행할 필요는 없기 때문에 dp로 해결  
dp[x][y][string] = 좌표가 x, y이고 현재 가진 문자열이 string일 때 값  
string을 저장하기 힘들기 때문에 hash를 사용
