// 一维前缀和：预处理 O(n)，查询 O(1)
    for(int i=1;i<=n;i++)
    s[i]=s[i-1]+a[i];
