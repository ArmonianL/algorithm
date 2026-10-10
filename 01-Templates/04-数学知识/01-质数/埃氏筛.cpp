int primes[N],cnt;
bool vis[N];//true表示是合数（筛掉的数）

void getprimes()
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            primes[cnt]=i;
            //只要筛质数就行了，合数跳过，因为合数前面的质数全都筛过了，合数是质数的乘积，比合数小的所有质因数的倍数都筛过了，没必要再筛这个合数的倍数了
            for(int j=i;j<=n;j+=i) vis[j]=true;
        }    
    }
}
