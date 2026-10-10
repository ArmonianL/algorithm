// 1≤n≤10000
// 1≤b≤a≤105
// p：质数（用了费马小定理）
const int N =100005;
const int P=1e9+7;
int fac[N];
int infac[N];

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
//如果p固定，init()和c()都不需要传p
void init()
{
    fac[0]=infac[0]=1;
    for(int i=1;i<N;i++) fac[i]=(ll)fac[i-1]*i%P;//这里i<=N就数组越界了
    infac[N-1]=qmi(fac[N-1],P-2,P);//先把fac求完再快速幂一次就行了
    for(int i=N-1;i>=1;i--) infac[i-1]=(ll)infac[i]*i%P; 
}

int c(int a,int b)
{
    return (ll)fac[a]*infac[a-b]%P*infac[b]%P;
}
