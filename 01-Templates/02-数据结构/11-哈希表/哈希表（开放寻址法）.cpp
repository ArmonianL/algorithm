const int null=0x3f3f3f3f;

int h[N];

int find(int x)
{
    int k=(x%N+N)%N;
    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}

int main()
{
    memset(h,0x3f,sizeof(h));

    for(int i=1;i<=n;i++)
    {
        char c;cin >> c;
        if(c=='I') 
        {
            int x;cin >> x;
            h[find(x)]=x;
        }
        else 
        {
            int x;cin >> x;
            int k=find(x);
            if(h[k]==null) cout << "No\n";
            else cout << "Yes\n";
        }
    }

    return 0;
}