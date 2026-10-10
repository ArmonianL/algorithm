# chatgpt response

下面给你一份偏 **算法竞赛速查表** 的 STL 时间复杂度总结。默认 `n = 容器元素个数`，`k = 操作涉及的元素数量`。

## 1. 常见容器

| STL | 操作 | 时间复杂度 |
|---|---|---:|
| `vector` | `a[i]` / `at()` | **O(1)** |
| | `front()` / `back()` | **O(1)** |
| | `push_back()` | **均摊 O(1)** |
| | `pop_back()` | **O(1)** |
| | 中间 `insert()` | **O(n)** |
| | 中间 `erase()` | **O(n)** |
| | `size()` / `empty()` | **O(1)** |
| | `clear()` | **O(n)** |
| `deque` | `a[i]` | **O(1)** |
| | `push_back/front()` | **O(1)** |
| | `pop_back/front()` | **O(1)** |
| | 中间插入/删除 | **O(n)** |
| `list` | `push_front/back()` | **O(1)** |
| | 已知迭代器 `insert/erase` | **O(1)** |
| | 随机访问 | **O(n)** |
| | 查找 | **O(n)** |
| `stack` | `push/pop/top` | **O(1)** |
| `queue` | `push/pop/front/back` | **O(1)** |
| `priority_queue` | `top()` | **O(1)** |
| | `push()` | **O(log n)** |
| | `pop()` | **O(log n)** |

竞赛里最常用的可以直接记：

```cpp
vector      // 动态数组
queue       // BFS
stack       // DFS / 单调栈
deque       // 单调队列
priority_queue // 堆
```

---

## 2. `set / map`

底层通常是平衡二叉搜索树（一般红黑树）。

| 操作 | `set / map` |
|---|---:|
| `insert()` | **O(log n)** |
| `erase()` | **O(log n)** |
| `find()` | **O(log n)** |
| `count()` | **O(log n)** |
| `lower_bound()` | **O(log n)** |
| `upper_bound()` | **O(log n)** |
| `begin()` | **O(1)** |
| 遍历整个容器 | **O(n)** |

所以：

```cpp
set<int> s;

s.insert(x);       // O(log n)
s.erase(x);        // O(log n)
s.find(x);         // O(log n)
s.lower_bound(x);  // O(log n)
```

`map` 同理：

```cpp
map<int, int> mp;

mp[x] = y;      // O(log n)
mp.find(x);     // O(log n)
mp.erase(x);    // O(log n)
```

注意：

```cpp
mp[x]
```

如果 `x` 不存在，**会自动插入一个元素**，所以仍然是 `O(log n)`，而且可能修改 `map`。

---

## 3. `unordered_set / unordered_map`

底层是哈希表。

| 操作 | 平均 | 最坏 |
|---|---:|---:|
| `insert()` | **O(1)** | O(n) |
| `erase()` | **O(1)** | O(n) |
| `find()` | **O(1)** | O(n) |
| `count()` | **O(1)** | O(n) |

所以算法题中通常认为：

```cpp
unordered_map<int,int> mp;
mp[x]++;        // 平均 O(1)
mp.find(x);     // 平均 O(1)
```

### `map` 和 `unordered_map`

可以粗略记成：

| | `map` | `unordered_map` |
|---|---:|---:|
| 查找 | O(log n) | 平均 O(1) |
| 插入 | O(log n) | 平均 O(1) |
| 有序 | ✅ | ❌ |
| `lower_bound` | ✅ | ❌ |
| 稳定性 | 较稳定 | 可能被卡哈希 |

竞赛中如果需要：

```text
排序 / 前驱后继 / lower_bound
        ↓
      map/set

只需要判断存在、计数
        ↓
 unordered_map/set
```

不过有些比赛为了防止哈希被构造数据卡到 `O(n²)`，会更倾向于 `map` 或自定义哈希。

---

# 4. `string`

可以大致理解成字符版 `vector<char>`。

| 操作 | 复杂度 |
|---|---:|
| `s[i]` | **O(1)** |
| `size()` / `length()` | **O(1)** |
| `push_back()` | **均摊 O(1)** |
| `pop_back()` | **O(1)** |
| `s += c` | **均摊 O(1)** |
| `s += t` | **O(|t|)** |
| `substr(pos, len)` | **O(len)** |
| 比较两个字符串 | 最坏 **O(n)** |
| `reverse()` | **O(n)** |

非常容易踩坑的是：

```cpp
string t = s.substr(l, len);
```

不是 O(1)，因为它要创建新字符串：

```text
O(len)
```

所以如果写：

```cpp
for (int i = 0; i < n; i++) {
    s.substr(i);
}
```

总复杂度可能是：

```text
O(n²)
```

---

# 5. 排序相关

## `sort`

```cpp
sort(a.begin(), a.end());
```

复杂度：

```text
O(n log n)
```

这是竞赛里最重要的一个。

例如：

```cpp
vector<int> a(n);

sort(a.begin(), a.end());  // O(n log n)
```

---

## `stable_sort`

```cpp
stable_sort(a.begin(), a.end());
```

通常：

```text
O(n log n)
```

特点是：

> 相等元素保持原来的相对顺序。

一般竞赛没特殊需求就用 `sort`。

---

# 6. 二分查找

对于已经排好序的 `vector`：

```cpp
lower_bound(a.begin(), a.end(), x);
upper_bound(a.begin(), a.end(), x);
binary_search(a.begin(), a.end(), x);
```

都是：

```text
O(log n)
```

含义：

```cpp
lower_bound
```

找到：

```text
第一个 >= x
```

```cpp
upper_bound
```

找到：

```text
第一个 > x
```

因此：

```cpp
int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
```

整体：

```text
O(log n)
```

---

# 7. 一个非常经典的坑

对于：

```cpp
set<int> s;
```

应该写：

```cpp
s.lower_bound(x);     // O(log n)
```

而不要写：

```cpp
lower_bound(s.begin(), s.end(), x);
```

虽然 `std::lower_bound` 只需要约 `O(log n)` 次**比较**，但是 `set` 的迭代器不能随机跳跃，移动迭代器可能累计达到：

```text
O(n)
```

所以记住：

```cpp
vector:
lower_bound(a.begin(), a.end(), x); // O(log n)

set/map:
s.lower_bound(x);                    // O(log n)
mp.lower_bound(x);                   // O(log n)
```

这个在算法竞赛里很重要。

---

# 8. 常见 `<algorithm>`

| 函数 | 时间复杂度 |
|---|---:|
| `sort()` | **O(n log n)** |
| `reverse()` | **O(n)** |
| `max_element()` | **O(n)** |
| `min_element()` | **O(n)** |
| `find()` | **O(n)** |
| `count()` | **O(n)** |
| `lower_bound()` | **O(log n)**（随机访问容器） |
| `upper_bound()` | **O(log n)**（随机访问容器） |
| `binary_search()` | **O(log n)** |
| `unique()` | **O(n)** |
| `next_permutation()` | **O(n)** |
| `nth_element()` | **平均 O(n)** |

例如：

```cpp
auto it = max_element(a.begin(), a.end()); // O(n)
```

---

# 9. `unique` 去重

竞赛经典写法：

```cpp
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```

复杂度：

```text
sort     O(n log n)
unique   O(n)
erase    O(n)
----------------
总计     O(n log n)
```

所以：

```cpp
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```

整体就是：

> **O(n log n)**

---

# 10. `priority_queue` / 堆

默认是大根堆：

```cpp
priority_queue<int> q;
```

| 操作 | 复杂度 |
|---|---:|
| `q.top()` | **O(1)** |
| `q.push(x)` | **O(log n)** |
| `q.pop()` | **O(log n)** |
| `q.empty()` | **O(1)** |
| `q.size()` | **O(1)** |

例如 Dijkstra：

```cpp
priority_queue<...> q;
```

每条边可能触发一次堆操作，所以经常得到：

```text
O((V + E) log V)
```

或者粗略写：

```text
O(E log V)
```

---

# 11. 手动堆相关函数

```cpp
make_heap()
push_heap()
pop_heap()
sort_heap()
```

复杂度：

```text
make_heap    O(n)
push_heap    O(log n)
pop_heap     O(log n)
sort_heap    O(n log n)
```

注意一个很容易记错的地方：

> **建堆 `make_heap` 是 O(n)，不是 O(n log n)。**

---

# 12. `multiset / multimap`

和 `set / map` 基本一样：

```text
insert       O(log n)
erase        O(log n)
find         O(log n)
lower_bound  O(log n)
upper_bound  O(log n)
```

区别是允许重复元素。

例如经常维护动态最值：

```cpp
multiset<int> s;

s.insert(x);             // O(log n)
s.erase(s.find(x));      // O(log n)

int mn = *s.begin();     // O(1)
int mx = *s.rbegin();    // O(1)
```

---

# 13. `bitset`

如果：

```cpp
bitset<N> b;
```

单个位置：

```cpp
b[i]
b.set(i)
b.reset(i)
b.flip(i)
```

基本可以认为：

```text
O(1)
```

位运算：

```cpp
a & b
a | b
a ^ b
```

实际上按机器字处理，可以理解为：

```text
O(N / word_size)
```

通常比普通数组逐个操作快很多。

竞赛中经常利用 `bitset` 把：

```text
O(n²)
```

常数优化到类似：

```text
O(n² / 64)
```

---

# 14. `pair`

```cpp
pair<int,int> p;
```

访问：

```cpp
p.first
p.second
```

都是：

```text
O(1)
```

比较：

```cpp
a < b
```

按照字典序比较：

```text
first
↓
如果相等再比较 second
```

普通整数 `pair<int,int>` 可以看作：

```text
O(1)
```

---

# 15. `array`

```cpp
array<int, N> a;
```

类似普通数组：

```text
a[i]        O(1)
size()      O(1)
front()     O(1)
back()      O(1)
```

排序：

```cpp
sort(a.begin(), a.end());
```

还是：

```text
O(n log n)
```

---

# 16. 竞赛最值得背的一张表

直接背这个基本够用了：

| STL / 操作 | 复杂度 |
|---|---:|
| `vector[i]` | **O(1)** |
| `vector.push_back()` | **均摊 O(1)** |
| `vector` 中间插入删除 | **O(n)** |
| `queue push/pop` | **O(1)** |
| `stack push/pop` | **O(1)** |
| `deque` 两端操作 | **O(1)** |
| `priority_queue top` | **O(1)** |
| `priority_queue push/pop` | **O(log n)** |
| `set/map find/insert/erase` | **O(log n)** |
| `set/map lower_bound` | **O(log n)** |
| `unordered_map/set` | **平均 O(1)，最坏 O(n)** |
| `sort` | **O(n log n)** |
| `lower_bound(vector)` | **O(log n)** |
| `reverse` | **O(n)** |
| `max/min_element` | **O(n)** |
| `unique` | **O(n)** |
| `next_permutation` | **O(n)** |
| `make_heap` | **O(n)** |
| `substr(k)` | **O(k)** |

---

## 17. 根据数据量判断复杂度

算法竞赛还建议把 STL 复杂度和数据范围一起记：

| `n` 大小 | 通常可接受复杂度 |
|---:|---|
| `n ≤ 10` | O(n!) |
| `n ≤ 20` | O(2ⁿ) |
| `n ≤ 100` | O(n³) |
| `n ≤ 1000` | O(n²) |
| `n ≤ 10⁵` | **O(n log n)** |
| `n ≤ 10⁶` | **O(n)** / O(n log n) 视常数 |
| `n ≥ 10⁷` | 基本考虑 **O(n)** |

比如：

```text
n = 1e5

sort                    O(n log n)  ✅
map 插入 n 次           O(n log n)  ✅
priority_queue 操作 n 次 O(n log n) ✅
双重循环                O(n²)       ❌
```

### 最核心的记忆规律

```text
连续数组 vector
随机访问            O(1)
中间修改            O(n)

红黑树 set / map
增删查              O(log n)

哈希 unordered_*
增删查              平均 O(1)

堆 priority_queue
看堆顶              O(1)
增删                 O(log n)

排序 sort
                     O(n log n)

普通遍历
                     O(n)

二分
                     O(log n)
```

如果是准备 **ACM / 蓝桥杯 / 洛谷 / Codeforces**，这张表基本覆盖日常 90% 以上的 STL 复杂度判断。