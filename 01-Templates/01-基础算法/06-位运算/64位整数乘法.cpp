//O(log2 b)
const ll N =1e18+5;
ll a,b,p;
//二进制思想
ll mul(ll a,ll b,ll p)
{
    ll res=0;
    while(b)
    {
        if(b&1) res=(res+a)%p;
        b >>= 1;
        a=a*2%p;
    }
    return res;
}

//还有一个O(1)的方法，我没太看懂，不需要掌握。（《算法竞赛进阶指南》P6）


