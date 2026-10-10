// 1≤n≤20
// 1≤b≤a≤1018
// 1≤p≤105，p：质数（用了费马小定理）

// Lucas 定理：求 C(n,m) mod p，p 为质数
// C(n,m) ≡ C(n%p,m%p) * C(n/p,m/p) (mod p)
const int N =100005;
ll n,a,b,p;//a,b要ll！！！
int fac[N];
int ifac[N];

int qmi(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(ll)res*a%p;
        b >>= 1;
        a=(ll)a*a%p;
    }
    return res;
}

void init(int p)
{
    fac[0]=ifac[0]=1;
    for(int i=1;i<p;i++) fac[i]=(ll)fac[i-1]*i%p;//这里只能预处理到p不然后面就全是0了
    ifac[p-1]=qmi(fac[p-1],p-2,p);
    for(int i=p-1;i>=1;i--) ifac[i-1]=(ll)ifac[i]*i%p;
}

int c(int a,int b,int p)
{
    return (ll)fac[a]*ifac[a-b]%p*ifac[b]%p;
}

ll lucas(ll n,ll m,ll p)
{
    if(m==0) return 1;//递归终止条件
    return c(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> p;
        init(p);
        cout << lucas(a,b,p) << '\n';
    }

    return 0;
}