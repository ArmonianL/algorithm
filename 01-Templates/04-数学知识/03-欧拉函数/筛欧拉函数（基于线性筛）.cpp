//每个数都分解质因数时间复杂度太高了。其实phi[primes*i]是可以由phi[i]很快算出来的。primes*i想到线性筛
const int N =1000010;
ll ans;//求欧拉函数之和
int primes[N],cnt;
bool vis[N];
int phi[N];//欧拉函数

void get_euler()
{
    phi[1]=1;//单独考虑
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            primes[++cnt]=i;
            phi[i]=i-1;//质数
        }
        for(int j=1;primes[j]<=n/i;j++)
        {
            vis[primes[j]*i]=true;
            phi[primes[j]*i]=phi[i]*(primes[j]-1);//pj不是i的质数，phi[pj*i]=pj*phi[i]*(1-1/pj)
            if(i%primes[j]==0)
            {
                //下面这句话一定要放在break前面！！！
                phi[primes[j]*i]=primes[j]*phi[i];//pj是i的最小质数，所以包含进phi[i]了
                break;
            }
        }
    }
}

int main()
{
    cin >> n;    
    get_euler();
    for(int i=1;i<=n;i++) ans+=phi[i];
    cout << ans;

    return 0;
}
