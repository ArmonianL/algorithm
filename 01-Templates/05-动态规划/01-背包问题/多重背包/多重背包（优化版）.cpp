const int N =1010*2010;//n=1000,s[i]<=2000,至少开1000*log2000这么大
int v[N],w[N],s[N];
int dp[N];

int main()
{
    cin >> n >> m;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;cin >> a >> b >> c;
        
        int k=1;
        while(k<=c)
        {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            c-=k;
            k*=2;
        }

        if(c>0)
        {
            cnt++;
            v[cnt]=a*c;
            w[cnt]=b*c;
        }
    }
    n=cnt;//！！！

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[m];

    return 0;
}