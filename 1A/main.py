
import math

if __name__ == "__main__":
    x = input()
    x = x.split(' ')

    n = float(x[0])
    m = float(x[1])
    a = float(x[2])

    answer = math.ceil(n / a) * math.ceil(m /a)

    print(int(answer));
