//给定 a, b，求组合数 C(a,b) = a! / (b!(a-b)!) 的完整值，结果可能超出 long long。

//C(a,b) = a! / (b!(a-b)!)
//把组合数分解成质因数 → 算出每个质数出现多少次 → 用高精度乘法把答案乘出来
int a,b;
int primes[N],cnt;
bool vis[N];
int sum[N];//每个质数的个数

//线性筛
void getprimes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) primes[++cnt]=i;
        for(int j=1;primes[j]<=n/i;j++)
        {
            vis[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}

/*
    求 n! 中质因子 p 的个数：
    n/p 统计至少贡献 1 个 p 的数，
    n/p^2 统计还能额外贡献 1 个 p 的数，
    n/p^3、n/p^4... 同理。
    因此：n! 中 p 的个数 = n/p + n/p^2 + n/p^3 + ...

    例如求 10! 中 2 的个数：
    10/2 = 5：2、4、6、8、10 各至少贡献 1 个 2
    10/4 = 2：4、8 还能再额外贡献 1 个 2
    10/8 = 1：8 还能再额外贡献 1 个 2
    所以一共：5 + 2 + 1 = 8 个 2
*/
int get(int n,int p)
{
    int res=0;
    int t=p;
    while(p<=n)
    {
        res+=n/p;
        p*=t;
    }
    return res;
}

//高精度乘法
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{
    cin >> a >> b;
    getprimes(a);

    for(int i=1;i<=cnt;i++)
    {
        int p=primes[i];
        sum[i]=get(a,p)-get(a-b,p)-get(b,p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 1; i <= cnt; i ++ )
        for (int j = 1; j <= sum[i]; j ++ )
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i -- ) cout << res[i];

    return 0;
}