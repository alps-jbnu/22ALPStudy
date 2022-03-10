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
            sum_dict[genre] += play
        else:
            sum_dict[genre] = play
            hash[genre] = []

        hash[genre].append((play, N - i, i))

    for key in hash.keys():
        hash[key].sort(reverse=True)
        array.append((sum_dict[key], key))
    array.sort(reverse=True)

