def solution(genres, plays):
    answer = []
    music_dic = {} # key: genres, value: (plays, number)
    total_plays = {} # key: genres, value: plays sum per genres
    for i in range(len(genres)):
        try:
            music_dic[genres[i]].append((plays[i],i)) # append value pair
        except:
            music_dic[genres[i]] = [] # 처음에 리스트 만들기
            music_dic[genres[i]].append((plays[i],i))

        try:
            total_plays[genres[i]]+=plays[i]
        except:
            total_plays[genres[i]]=0 # 처음에 0으로 초기화
            total_plays[genres[i]] += plays[i] # plays 장르별로 더하기

    for genre in music_dic.keys():
        music_dic[genre].sort(reverse=True) # plays 높은 순으로 정렬(내림차순)

    total_plays = sorted(total_plays.items(),key=(lambda x:x[1]), reverse=True) # plays합 높은 순으로, value기준으로 정렬
    # 리스트로 반환 -[('pop', 3100), ('classic', 1450)]

    for element in total_plays:
        genre = element[0]
        if len(music_dic[genre])==1: # 장르에 노래 하나만 수록된 경우
            answer.append(music_dic[genre][0][1])
        else:
            if music_dic[genre][0][0]==music_dic[genre][1][0]: # 같은 장르 두 곡의 플레이 횟수가 같은 경우
                if music_dic[genre][0][1]>music_dic[genre][1][1]: # 번호가 작은애 부터 출력
                    answer.append(music_dic[genre][1][1])
                    answer.append(music_dic[genre][0][1])
                else:
                    answer.append(music_dic[genre][0][1])
                    answer.append(music_dic[genre][1][1])
            else:
                for i in range(2): # 2번째까지만 출력
                    answer.append(music_dic[genre][i][1]) # number

    # print(answer)
    return answer
# g = ["classic", "pop", "classic", "classic", "pop"]
# p =[500, 600, 150, 800, 2500]
# solution(g,p)
