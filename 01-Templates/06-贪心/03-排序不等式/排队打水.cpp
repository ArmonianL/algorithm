//给定每个人的打水时间，安排打水顺序，使所有人的等待时间总和最小
//相当于：最小化前缀和之和
//贡献法：枚举所有不同方案的前缀和之和 -> 枚举贡献者：t总=t[1]*(n-1)+t[2]*(n-2)+...
//贪心：huffman思想，t小往前放，所以最终最小的方案就是从小到大排序
const int N =100010;
int n;
int t[N];
ll ans;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> t[i];
    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++) ans+=t[i]*(n-i);
    cout << ans;

    return 0;
}