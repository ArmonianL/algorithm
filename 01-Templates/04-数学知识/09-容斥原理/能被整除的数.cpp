// 容斥原理：|A1∪...∪An| = Σ单个 - Σ两两交集 + Σ三者交集 - ... 
// C(n,1)+...+C(n,n)=2^n-1
// 选 i 个之和等于任意选；每个元素都有“选/不选”两种状态，共 2^n 种，去掉全不选
// 如果每个子集可以在 O(1) 时间内处理，那么总时间复杂度为 O(2^n)
const int N =20;
int p[N];
int ans;

int main()
{
    // 给定整数 n 和 m 个不同的质数 p1,p2,...,pm
    // 求 1~n 中能被这 m 个质数中的至少一个整除的整数个数
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> p[i];

    //每一项表示1-n中能被选的质数的乘积整除的个数，即n/选的质数之积向下取整
    for(int i=1;i< 1<<m ;i++)//二进制状压，至少选一个！！！
    {
        int cnt=0;//统计多少个交集
        int t=1;
        for(int j=0;j<m;j++)
        {
            if(i >> j & 1)
            {
                cnt++;
                if((ll)p[j]*t>n)//质数之积超过n了,注意要用ll！！！
                {
                    t=-1;
                    break;
                }
                t*=p[j];
            }
        }
        if(t!=-1) 
        {
            if(cnt&1) ans+=n/t;
            else ans-=n/t;
        }
    }
    cout << ans;

    return 0;
}