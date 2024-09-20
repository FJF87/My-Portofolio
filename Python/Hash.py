import argon2

str = "Hello World"

argonHash = argon2.PasswordHasher(time_cost=20)

hashedStr = argonHash.hash(str)

print("hashed str:", hashedStr)

inputStr = "Hello World"

try:
    argonHash.verify(hashedStr, inputStr)
    print("Str verification success")
except:
    print("Str verification failed")