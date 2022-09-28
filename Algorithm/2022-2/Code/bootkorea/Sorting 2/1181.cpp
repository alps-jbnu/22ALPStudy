num = int(input())
lists = []

for i in range(num) :
	word = str(input())
	word_cnt = len(word)
	lists.append((word, word_cnt))

	lists = list(set(lists))
	lists.sort(key = lambda word : (word[1], word[0]))

	for word in lists :
print(word[0])