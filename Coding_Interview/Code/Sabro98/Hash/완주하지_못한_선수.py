def solution(participant, complement):
    participant.sort()
    complement.sort()
    for i in range(len(complement)):
        if participant[i] != complement[i]:
            return participant[i]
    return participant[-1]
