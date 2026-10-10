//约数之和：所有(p的0次方+p的一次方+...+p的ai次方)之积，展开来每一项一个约数，从每个（）里面选一个相乘
const int N =105;
const int P=1e9+7;

int main()
{
    cin >> n;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
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
        int prime=i.first,a=i.second;
        ll t=1;//这里一定要开ll
        while(a--) t=(t*prime+1)%P;//这里太妙了
        ans=ans*t%P;
    }
    cout << ans;
    
    return 0;
}