def factorial(n):
    if n == 0: return 1
    return n * factorial(n-1)

# n = 5
# print(factorial(n))

### 1 ###
def fibonacci(n):
    if n == 1: return 1
    elif n == 2: return 1
    else: return fibonacci(n-1) + fibonacci(n-2)

# n = 3
# print(fibonacci(n))

### 2 ###
def palindromo(s):
    if len(s) <= 1: return True
    if (s[len(s)-1] == s[0]):
        return palindromo(s[1:len(s)-1])
    else: return False
    
s = "maioualoolauoiam"
print(palindromo(s))

