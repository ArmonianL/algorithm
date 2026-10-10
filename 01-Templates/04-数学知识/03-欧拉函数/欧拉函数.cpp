//分解质因数+公式
/*
1-n中和n互质的个数：n(1-1/p1)(1-1/p2)......
证明：把质因数的倍数都减掉，把重复减的加上，再把重复加的减掉......
*/
const int N =104;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) 
    {
        int a;cin >> a;
        int res=a;
        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                res=res/i*(i-1);//这里变形一下因为不能出现浮点数
                while(a%i==0) a/=i;
            }
        }
        if(a>1) res=res/a*(a-1);
        cout << res << '\n';
    }

    return 0;
}