// 浮点数三分：O(log((R-L)/eps))
// 通常要求函数具有严格的单峰性（严格单调性）
const int N =14;
const double eps=1e-7;
int n;//n次函数
double l,r;//保证l到r之间单峰
double xishu[N];//从高到低的系数（n次函数有n+1个系数）

double f(double x)
{
    double res=0;
    for(int i=1;i<=n+1;i++)
    {
        res+=xishu[i]*pow(x,n-i+1);
    }    
    return res;
}

int main()
{
    cin >> n >> l >> r;
    for(int i=1;i<=n+1;i++) cin >> xishu[i];

    while(r-l>eps)
    {
        double lmid=l+(r-l)/3;
        double rmid=l+(r-l)/3*2;
        if(f(lmid)<f(rmid)) l=lmid;
        else r=rmid;
    }

    cout << l;

    return 0;
}