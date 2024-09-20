word = input()
word = word.lower()

vocals = ["a", "i", "u", "e", "o", "y"]

for i in word:
    found = vocals.count(i)
    if found == 0:
        print("." + i, end="")
    else:
        pass