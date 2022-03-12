def solution(genres, plays):
    answer = []
    sum_dict = {}
    hash = {}
    array = []
    N = len(genres)

    for i in range(N):
        genre = genres[i]
        play = plays[i]

        if genre in sum_dict.keys():
            # 장르의 총 실행 횟수 더함
            sum_dict[genre] += play 
        else: # 처음 나오는 장르라면 초기화
            sum_dict[genre] = play
            hash[genre] = []
        
        # 해당하는 장르 해시에 음악의 (실행된 수, 실제 위치)
        hash[genre].append((play, i))

    for key in hash.keys():
        # 실행 횟수 -> 1/실제 위치 를 기준으로 역순으로 정렬
        hash[key].sort(key=lambda x: (x[0], -x[1]), reverse=True)
        array.append((sum_dict[key], key))
    array.sort(reverse=True)

    for _, genre in array:
        answer.append(hash[genre][0][1])
        if len(hash[genre]) >= 2:
            answer.append(hash[genre][1][1])

    return answer
