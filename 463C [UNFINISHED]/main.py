

n = int(input())

rows = []

for i in range(0, n):
    x = input()
    x = x.split(' ')

    rows.append(x)

store = []

for i in range(0, n):
    # walk:

    # start at 0, i
    # walk right n - (i + 1) times
    # walk down n - (i + 1) times

    # save then step

    x = i
    y = n - 1

    l = []

    for j in range(0, i):
        l.append(0)

    for j in range(0, (n - i + 1)):
        l.append(rows[x][y])
        y -= 1

    for j in range(0, (n - i + 1)):
        l.append(rows[x][y])
        x += 1

    store.append(l)

# find max column in store
column_totals = []

for i in range(0, (n + n - 1)):
    total = 0
    for j in range(0, n)
        total += store[j][i]
    column_totals.append(total)

maxVal = 0
maxInd = 0

for i in range(0, (n + n - 1)):
    if (column_totals[i] > maxVal):
        maxVal = column_totals[i]
        maxInd = i

for i in range(0, n):
    store[i][maxInd] = 0

# find max row
row_totals = []

for i in range(0, n):
    total = 0

    for x in store[i]
        total += x

    row_totals.append(total)

rowVal = 0
rowInd = 0

for i in range(0, n):
    if (row_totals[i] > rowVal):
        rowVal = row_totals[i]
        rowInd = i

for i in range(0, n + n - 1):
    store[rowInd][i] = 0

# convert rowInd and maxInd to x, y
    x = rowInd
    y = n - 1

    for i in range(0, maxInd - 1):

