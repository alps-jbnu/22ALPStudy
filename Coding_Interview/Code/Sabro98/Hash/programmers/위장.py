def solution(clothes):
    hash = {}
    for name, type in clothes:
        try:
            hash[type] += 1
        except:
            hash[type] = 1
            hash[type] += 1
    result = 1
    for key in hash.keys():
        print(f'{key} {hash[key]}')
        result *= hash[key]
    return result - 1
