

if __name__ == "__main__":
    nn, kk = input().split(' ')
    n = int(nn)
    k = int(kk)

    scores = input().split(' ')

    count = 0

    for x in scores:
        if int(x) >= int(scores[k - 1]) and int(x) > 0:
            count += 1

    print(count)


