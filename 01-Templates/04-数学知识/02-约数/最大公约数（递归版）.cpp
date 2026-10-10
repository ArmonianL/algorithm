//欧几里得算法：辗转相除法
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
