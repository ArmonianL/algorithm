//O(n!)
//选哪个可以选的
const int N =10;
int n;

int res[N];
bool vis[N];
void calc(int cnt)
{
    if(cnt==n+1)
    {
        for(int i=1;i<=n;i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            res[cnt]=i;
            vis[i]=true;//这里是i不是cnt
            calc(cnt+1);
            vis[i]=false;
        }
    }
}

int main()
{
    cin >> n;
    calc(1);

    return 0;
}