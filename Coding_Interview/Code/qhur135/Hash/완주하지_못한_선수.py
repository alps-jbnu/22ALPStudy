def solution(participant, completion):
    answer = ''
    comp_dic = {}
    for comp in completion:
        comp_dic[comp] = 0  # 완주한 선수 딕셔너리에 넣기, 초기화
    for comp in completion:
        comp_dic[comp] += 1  # VALUE값은 해당 이름(KEY)을 갖은 선수의 수
    for part in participant:  # 참가자 순회
        if part in comp_dic.keys():  # 참가자가 완주한 딕셔너리에 있다면
            comp_dic[part] -= 1
            if comp_dic[part] < 0:  # 동일한 이름 처리
                answer = part
                break
        else:
            answer = part
            break
    # print(answer)
    return answer

# part = ['C','C','B','A']
# comp = ['C','C','B']
# solution(part,comp)