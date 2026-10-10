# P3131 [USACO16JAN] Subsequences Summing to Sevens S

## 题目链接

https://www.luogu.com.cn/problem/P3131

## 我的思路



## 正确思路

要求：

$$
(prefix[r]-prefix[l-1]) \mod 7 = 0
$$

也就是：

$$
prefix[r] \mod 7 = prefix[l-1] \mod 7
$$

### 关键发现：

只要两个前缀和的余数相同，它们之间的区间和一定是 7 的倍数。

## 实现注意

- 注意考虑的是l-1和r的余数是否相同，但l-1是可以取到0的，也就是说$first[0]$应该是下标0，但是0又代表没有第一个下标，所以冲突了，用-1表示没有第一个下标
- 注意溢出

> 2026-08-02

- 用ll
- 是和前一个s的余数相等，所以要考虑$first[0]$相当于给这组数多加一个数0，余数是0
