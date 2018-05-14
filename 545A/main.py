#!/bin/python3

import sys

# n toy cars
# every pair collides
# - no car turns over 
# - 1 car turns over
# - 2 cars turn over

# ith row, jth column

# -1 cars never collided
#  0 if no car turned over
#  1 if i turned over
#  2 if j turned over
#  3 if both cars turned over



# read in n
n = int(input())

scores=[True for x in range(n)]

# read in the matrix A
for i in range(n):
    line = input().split(' ')

    for j in range(len(line)):

        e = line[j]

        if e == "-1":
            continue
        elif e == "0":
            continue
        elif e == "1":
            scores[i] = False;
        elif e == "2":
            scores[j] = False;
        elif e == "3":
            scores[i] = False;
            scores[j] = False;
            
total = 0
for car in scores:
    if car:
        total += 1

print(total)

for i, car in enumerate(scores):
    if car:
        print(i + 1, end=" ")

print()
