from math import comb
a, b = map(int, input().split())
print(comb(a, b))

"""
a, b = map(int, input().split())

# C(a, b) = a! / (b! * (a-b)!)
# 利用对称性减少循环次数
b = min(b, a - b)

ans = 1
for i in range(1, b + 1):
    ans = ans * (a - i + 1) // i

print(ans)
"""

