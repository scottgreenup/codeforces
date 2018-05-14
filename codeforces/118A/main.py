

word = input()
edit = ""

for c in word:
    if c in "aeiouyAEIOUY":
        continue
    
    edit += "."
    edit += c.lower()

print(edit)
