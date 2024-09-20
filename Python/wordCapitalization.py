def capitalNth(s, n):
    return s[:n] + s[n].capitalize() + s[n+1:]

word = input()
word = capitalNth(word, 0)
print(word)