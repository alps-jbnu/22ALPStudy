def solution(bridge_length, weight, truck_weights):
    from collections import deque
    w = deque(truck_weights)
    q = deque()
    time = 0
    weight_sum = 0
    while w or q:
        if q and q[0][1] == time:
            curr = q[0][0]
            weight_sum -= curr
            q.popleft()
        if w and weight_sum + w[0] <= weight:
            q.append((w[0], time + bridge_length))
            weight_sum += w[0]
            w.popleft()
        time += 1
    return time
