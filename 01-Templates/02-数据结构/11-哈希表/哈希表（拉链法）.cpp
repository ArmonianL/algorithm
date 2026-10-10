int h[N],e[N],ne[N],idx;

void insert(int x)
{
    int k=(x%N+N)%N;
    e[idx]=x;ne[idx]=h[k];h[k]=idx++;
}

bool find(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}

int main()
{
    memset(h,-1,sizeof h);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        char c;cin >> c;
        if(c=='I')
        {
            int x;cin >> x;
            insert(x);
        }
        else 
        {
            int x;cin >> x;
            if(find(x)) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}