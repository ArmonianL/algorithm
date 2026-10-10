# C - Inc, Dec, Xor

## 题目链接

https://atcoder.jp/contests/abc470/tasks/abc470_c

## 我的思路

## 正确思路

1. 一般地，如果数组中的某个元素从旧值变成新值，都可以这样更新：

$$ans⊕=旧值⊕新值$$

2. 第二类操作不要每次都当场遍历，还是维护一个集合保存>=1的下标

## 实现注意

- range-for遍历时不要删除元素。不然会破坏迭代器
  
  不用set，也可用vector
  
  ```cpp
  vector<int> next;

            for(int i:idx)

            {

                ans=ans^a[i]^(--a[i]);

                if(a[i]!=0) next.push_back(i);

            }

            idx.swap(next);//交换两个vector
  ```
