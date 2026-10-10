const int N =105;
const double eps=1e-8;
int n;
double a[N][N];

int gauss()
{
    int c,r;//c和r相当于是起点，只在循环里面不改变值
    for(c=0,r=0;c<n;c++)
    {
        int t=r;
        for(int i=r+1;i<n;i++) if(fabs(a[i][c])>fabs(a[t][c])) t=i;//每次要选绝对值最大的放上面，如果很小的数，除了之后其他数会变得很大，放大double的误差
        if(fabs(a[t][c])<eps) continue;//这句话非常重要，如果后面有很多0行，那么执行到后面的时候当找最大值时只有0，那么就直接continue，r不会++，所以r就相当于是矩阵的秩
        for(int i=0;i<n+1;i++) swap(a[r][i],a[t][i]);//移到最上面
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];//变成1
        for(int i=r+1;i<n;i++)//把1下面都变成0
        {
            if(fabs(a[i][c])<eps) continue;//这个别忘记
            for(int j=n;j>=c;j--) a[i][j]-=a[i][c]*a[r][j];
        }
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<n;i++)//检查的是下面的0行
        {
            if(fabs(a[i][n])>eps) return 0;
        }
        return 2;
    }
    else 
    {
        for(int j=n-1;j>=0;j--)
        {
            for(int i=j-1;i>=0;i--)
            {
                a[i][n]-=a[i][j]*a[j][n];
                a[i][j]=0;
            }
        }
        return 1;
    }
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
    else if(t==2) cout << "Infinite group solutions";//无数多解
    else 
    {
        for(int i=0;i<n;i++) cout << fixed << setprecision(2) << a[i][n] << '\n';//唯一解
    }

    return 0;
}