bool isprime(int n)
{
    if(n<2) return false;//1不是质数
    for(int i=2;i<=n/i;i++)//优化
    {
        if(n%i==0) return false;
    }
    return true;
}
