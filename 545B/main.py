#!/bin/python3

# distances between strings
# strings are only 0 and 1

# hamming distance, equal-length strings, the distance is the amount of 
# different characters at each index

# you are giving strings s and t with hamming distance h
# find p that has the same hamming distance to s, as it does to t

s = input()
t = input()

def hamming_distance(a, b):
    n = len(a)
    distance = 0

    for i in range(n):
        if a[i] != b[i]:
            distance += 1

    return distance


d = hamming_distance(s, t)

if d % 2 != 0:
    print("impossible")
else:
    r = ""

    do_s = False

    for i in range(len(s)):
        if s[i] == t[i]:
            r += s[i]
        elif do_s:
            r += s[i]
            do_s = False
        else:
            r += t[i]
            do_s = True

    print(r)

