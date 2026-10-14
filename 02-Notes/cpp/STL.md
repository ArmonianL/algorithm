# STL

## vector

- 分配空间时，时间与空间大小无关，与申请次数有关
- 支持比较运算：按照字典序  
  ```cpp
  vector<int> a;
  vector<int> b;
  if(a<b)
  ```
- erase()：一般不用，时间复杂度$O(n)$
## pair

- 支持比较运算：按照字典序

## string

- substr(1,2)：2是长度

## queue

## priority_queue

- 默认大根堆
- 小根堆：  
  ```cpp
  priority_queue<int,vector<int>,greater<int>> pq
  ```

## stack

## deque

- 速度超级慢

## set/multiset

- insert()
- find()
- count()
- erase()  
  1. 输入数
  2. 输入迭代器
- lower_bound() 返回$\ge x$的最小的数的迭代器
- upper_bound() 返回$> x$的最小的数的迭代器

## map/multimap

- insert()：参数是pair，用的不多，一般直接`a[xxx]=1;`
- erase()  
  1. 输入pair
  2. 输入迭代器
- find()

## bitset

压位

