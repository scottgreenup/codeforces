import re
import sys
import math

def toA(cell):
    """ BC25 -> RXCY """

    re_numbers = re.compile('\d+')
    re_letters = re.compile('[A-Z]+')

    letters = re_letters.findall(cell);
    numbers = re_numbers.findall(cell);

    flip = letters[0][::-1]

    value = 0

    for i in range(0, len(flip)):
        v = ord(flip[i]) - 64
        value += v * int(math.pow(26, i))

    return "R" + numbers[0] + "C" + str(value)

def toB(cell):
    """ RXCY -> BC25 """
    
    re_numbers = re.compile('\d+')

    numbers = re_numbers.findall(cell)

    row = numbers[0]
    val = int(numbers[1])
    col = ""

    while val > 0:
        if val <= 26:
            col += chr( val + 64 )
            val = 0
        else:
            mod = val % 26

            if (mod == 0):
                col += "Z"
                val = int(val / 26.0) - 1
            else :
                col += chr( int((val % 26.0) + 64) )
                val = int(val / 26.0)
    
    return col[::-1] + str(row)


if __name__ == "__main__":

    p = re.compile('^R(\\d)+C(\\d)+$')

    num = input()

    for x in range(0, int(num)):
        cell = input()

        if p.match(cell) != None:
            print(toB(cell))
        else:
            print(toA(cell))
