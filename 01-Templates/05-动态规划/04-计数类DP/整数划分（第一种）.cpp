//转换成完全背包问题
const int N =1005;
const int P=1e9+7;
int f[N];//省略第一维
//f[i][j]：从前i个整数中选，体积刚好是j的所有方案数
/*
f[i][j]=f[i-1][j]+f[i][j-i];不选+至少选1个
（前i个物品体积为j-i的方案数包括选0个i，1个i等等再+i就是f[i][j],说明至少选1个i）
*/
int main()
{
    cin >> n;

    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)//从i开始！！！
        {
            f[j]=(f[j]+f[j-i])%P;//左边=上一轮数据+更新过的数据
        }
    }
    
    cout << f[n];

    return 0;
}