def solution(phone_book):
    phone_book.sort(reverse=True)
    num_hash = {}
    for phone in phone_book:
        try:
            if num_hash[phone]:
                return False
        except:
            for i in range(len(phone)):
                num_hash[phone[:i+1]] = True

    return True
