import operator
import math

word_dict = {}
with open("count_1w.txt") as ins:
    for line in ins:
        arr = line.strip().split()
        word_dict[arr[0]] = int(arr[1])

phrase_dict = {}
with open("count_2w.txt") as ins:
    for line in ins:
        arr = line.strip().split()
        count = arr[2]
        fir = arr[0]
        sec = arr[1]
        phrase_dict[fir.lower() + " " + sec.lower()] = int(count)

sentence = input("enter your sentence: ")
sent_arr = sentence.strip().split()
sent_len = len(sent_arr)
sent_log_prob = 0
# sent_prob = 1
for i in range(sent_len - 1):
    phr_count = float(phrase_dict[sent_arr[i].lower() + " " + sent_arr[i + 1].lower()])
    wrd_count = float(word_dict[sent_arr[i].lower()])
    prob = phr_count / wrd_count
    # sent_prob *= prob
    sent_log_prob += math.log2(prob)
print(sent_log_prob)
# print(sent_prob)
