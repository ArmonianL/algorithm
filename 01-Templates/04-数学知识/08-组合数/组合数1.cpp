// 1≤n≤10000
// 1≤b≤a≤2000
const int N =10005;
const int M=2005;
const int P=1e9+7;
int c[M][M];//c[i][j]=c[i-1][j-1]+c[i-1][j]

void init()
{
    for(int i=0;i<=2000;i++) c[i][0]=1;//c[0][0]=1!!!
    for(int i=1;i<=2000;i++)
    {
        for(int j=1;j<=2000;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
        }
    }
}