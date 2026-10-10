//约数个数：(a1+1)(a2+1).....,ai是每个质因子的指数，每个约数在每个质因数都有ai+1种选法
const int N =105;
const int P=1e9+7;

int main()
{
    cin >> n;
    unordered_map<int,int> mp;
    while(n--)
    {
        int x;cin >> x;
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0)
            {
                mp[i]++;
                x/=i;
            }
        }
        if(x>1) mp[x]++;
    }
    ll ans=1;
    for(auto i:mp)
    {
        ans=ans*(i.second+1)%P;//ans*=(i.second+1)%P;是错的，应该先乘再取模
    }
    cout << ans;

    return 0;
}