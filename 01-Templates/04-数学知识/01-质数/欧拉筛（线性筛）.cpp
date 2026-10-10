int primes[N],cnt;
bool vis[N];
//核心：筛p[j]*i，保证p[j]是p[j]*i的最小质因子，相当于用最小质因子筛
/*
对于每个合数x=p*i。p和i肯定比x先遍历到，所以遍历到合数时它肯定被筛过了
遍历到合数i的时候，i的最小质因子p满足p*p<=i。所以p<=i/p<i，所以遍历到i之前，p先被加入到质数中，然后遍历到i/p的时候i被筛掉
*/
void getprimes()
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) primes[++cnt]=i;
        for(int j=1;primes[j]<=n/i;j++)
        {
            vis[primes[j]*i]=true;
            if(i%primes[j]==0) break;
            /*
            break前pj一定是pj*i的最小质因子，break后pj*i的最小质因子就是i的最小质因子了，不是pj了
            如果去掉这个break也对，但是同一个数会被筛很多次，这句话保证线性筛
            */
        }
    }
}