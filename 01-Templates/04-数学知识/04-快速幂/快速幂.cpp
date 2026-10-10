//二进制思想：指数拆成二进制
ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%p;//需要乘上这一位a的2的某次方
        b >>=1;
        a=a*a%p;//每次循环都同步更新a，把a移到下一位就是把a平方一下
    }
    return res;
}