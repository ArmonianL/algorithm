const int N =105;
int n;
int a[N][N];

int gauss()
{
    int c,r;
    for(c=0,r=0;c<n;c++)
    {
        int t=r;
        for(int i=r+1;i<n;i++) if(a[i][c]==1) t=i;
        if(a[t][c]==0) continue;//这个不要忘记判断！！！
        for(int j=0;j<n+1;j++) swap(a[t][j],a[r][j]);
        for(int i=r+1;i<n;i++)
        {
            if(a[i][c]==0) continue;
            for(int j=0;j<n+1;j++) a[i][j]^=a[r][j];
        }
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<n;i++) if(a[i][n]==1) return 0;
        return 2;
    }
    for(int j=n-1;j>=0;j--)
    {
        for(int i=j-1;i>=0;i--)
        {
            if(a[i][j]==0) continue;
            a[i][n]^=a[j][n];
            a[i][j]=0;
        }
    }
    return 1;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++) cin >> a[i][j];
    }

    int t=gauss();
    if(t==0) cout << "No solution";//无解
    else if(t==2) cout << "Multiple sets of solutions";//多解
    else 
    {
        for(int i=0;i<n;i++) cout << a[i][n] << '\n';//唯一解
    }

    return 0;
}