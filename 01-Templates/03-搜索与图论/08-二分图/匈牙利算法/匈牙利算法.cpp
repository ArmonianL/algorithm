//这个算法想象成男生和女生匹配
const int N =505;
const int M=100010;
int n1,n2,m;
int h[N],e[M],ne[M],idx;
bool vis[N];//vis[i]：对当前这个男生而言，i这个女生有没有考虑过
int match[N];//match[i]：第i个女生匹配的男生编号，0代表没有匹配
int ans;

void init()
{
    memset(h,-1,sizeof(h));
}

void add(int a,int b)
{
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}

bool find(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!vis[j])//只看没有考虑过的女生
        {
            vis[j]=true;//考虑这个女生
            if(!match[j] || find(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    }
    return false;//在上面的循环里面不能return false，因为要把所有连线的女生考虑一遍，不能提前return false
}

int main()
{
    cin >> n1 >> n2 >> m;init();
    for(int i=1;i<=m;i++)
    {
        int a,b;cin >> a >> b;
        add(a,b);//虽然是无向边，但是我们只考虑男生
    }

    for(int x=1;x<=n1;x++)
    {
        memset(vis,false,sizeof(vis));
        if(find(x)) ans++;
    }
    cout << ans;

    return 0;
}