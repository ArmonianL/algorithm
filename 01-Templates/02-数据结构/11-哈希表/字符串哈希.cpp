using ULL=unsigned long long;
const int P=131;

int n,m;
string s;
ULL h[N],p[N];//p也必须是取模意义下的值，用int很快就会溢出

ULL get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    cin >> s;s=" "+s;//这里注意一下
    
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
    }

    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*P+s[i];
    }

    while(m--)
    {
        int a,b,c,d;cin >> a >> b >> c >> d;
        if(get(a,b)==get(c,d)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}