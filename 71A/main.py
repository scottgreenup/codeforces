
if __name__ == "__main__":
    n = int(input())

    for x in range(0, n):
        word = input()

        if len(word) > 10:
            print(word[0] + str(len(word) - 2) + word[-1])
        else:
            print(word)
