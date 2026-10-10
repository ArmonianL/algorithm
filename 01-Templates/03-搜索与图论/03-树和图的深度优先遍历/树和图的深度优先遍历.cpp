int h[N],e[N*2],ne[N*2],idx;
bool st[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    st[u]=true;

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j]) dfs(j);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(h,-1,sizeof(h));


    return 0;
}