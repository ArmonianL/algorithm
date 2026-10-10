# C - Cookies and Greedy Takahashi

## 题目链接

https://atcoder.jp/contests/abc471/tasks/abc471_c

## 我的思路

vector然后用erase

## 正确思路

1. set
2. 双指针（不删除元素）

- `vector.erase(iterator)`：通常是 **O(N)**，因为删除后，后面的元素需要整体向前搬。
- `vector.pop_back()`：**O(1)**，因为只删最后一个元素，不需要移动其他元素。
- `set.erase(value)` / `set.erase(iterator)`：
    - 按值删除一般 **O(log N)**
    - 已知迭代器删除，C++ 标准下是**均摊 O(1)**

所以刚才第二种“双指针”方法的关键就在于：**它根本没有真的从 vector 中删除元素。**

## 实现注意
