// 卡特兰数：统计 n 个 0 和 n 个 1 的排列中，任意前缀都满足 0 的数量 >= 1 的数量的序列个数。
/*
转换成网格：
走到(6,6)方案数：c(12,6)
穿过对角线的方案数：c(12,5)（点(6,6)关于对角线旁边的一条线对称，得到点(5,7)，即到(5,7)的方案数）
*/
const int N =100005;
const int P=1e9+7;
int fac[2*N+1];//不要开小了！！！
int ifac[2*N+1];

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

void init()
{
    fac[0]=ifac[0]=1;
    for(int i=1;i<=2*N;i++) fac[i]=(ll)fac[i-1]*i%P;
    ifac[2*N]=qmi(fac[2*N],P-2,P);
    for(int i=2*N;i>=1;i--) ifac[i-1]=(ll)ifac[i]*i%P;
}

int c(int a,int b)
{
    return (ll)fac[a]*ifac[a-b]%P*ifac[b]%P;
}

int catalan(int n)//返回方案数
{
    return (c(2*n,n)-c(2*n,n-1)+P)%P;//因为c是返回对P取模的结果，所以这两个相减可能出现负数
}