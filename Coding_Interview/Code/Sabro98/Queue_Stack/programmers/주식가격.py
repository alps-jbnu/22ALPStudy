def solution(prices):
    N = len(prices)
    answer = [0 for _ in range(N)]
    st = []
    # price, idx
    for i, p in enumerate(prices):
        while st and st[-1][0] > p:
            idx = st[-1][1]
            st.pop()
            answer[idx] = i - idx
        st.append((p, i))
    while st:
        idx = st[-1][1]
        st.pop()
        answer[idx] = N - idx - 1
    return answer
