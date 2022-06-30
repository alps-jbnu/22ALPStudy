def solution(phone_book):
    answer = True
    phone_book.sort() # 정렬 -> 접두어와 붙어있게됨 ["119", "1195524421", "97674223"]
    for head_idx in range(len(phone_book)-1): # 맨마지막 요소를 제외한 요소들 idx - 맨마지막 요소가 접두어일 수는 없음(확인필요없음)
        head_num = phone_book[head_idx] # 접두어 후보
        size = len(head_num) # 접두어 길이
        for search_idx in range(head_idx+1,len(phone_book)): # head_num 뒤 요소부터 끝까지 탐색
            search_num = phone_book[search_idx] # 탐색할 요소
            if head_num == search_num[:size]: # 탐색할 요소를 접두어랑 같은 크기로 자름 -> 이후 비교
                answer = False # 같으면
                # print(answer)
                return answer
            elif head_num < search_num[:size]: # 탐색할 요소가 접두어보다 큰 수라면 해당 접두어를 가지는 문자열을 이후에도 없을 것
                # 그러므로 반복문 종료하고 새로운 접두어로 다시 탐색하기 위해 break
                break
    # print(answer)
    return answer

# num = ["88", "1234", "67", "678"]
# solution(num)

# ["119", "97674223", "1195524421"] -> sort후 ["119", "1195524421", "97674223"] -> false
# ["88", "1234", "67", "567"] -> sort후 ["1234", "567", "67", "88"] -> true
