//O(n^2)
int a[N];
int f[N];//f[i]:以下标i结尾的所有上升子序列的最大值
int g[N];//g[i]:保存当前的下标i是由哪个下标转移过来的

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        g[i]=0;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                if(f[i]<f[j]+1)
                {
                    f[i]=f[j]+1;
                    g[i]=j;
                }
            }
        }
    }

    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(f[k]<f[i]) k=i;
    }
    cout << f[k] << '\n';
    //逆序打印这个最长上升子序列
    for(int i=1,len=f[k];i<=len;i++)
    {
        cout << a[k] << ' ';
        k=g[k];
    }

    return 0;
}