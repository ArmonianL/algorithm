const int N =105;
int v[N][N],w[N][N],s[N];
int f[N];

int main()
{
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        cin >> s[i];//第i组的元素个数
        for(int j=1;j<=s[i];j++)
        {   
            cin >> v[i][j] >> w[i][j];
        }
    }

    for(int i=1;i<=n;i++)//i代表第几组
    {
        for(int j=m;j>=0;j--)//用小的更新大的，小的不能先被更新，应该倒序
        {
            for(int k=1;k<=s[i];k++)
            {
                if(j>=v[i][k]) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);//if不要忘记
            }
        }
    }
    cout << f[m];

    return 0;
}