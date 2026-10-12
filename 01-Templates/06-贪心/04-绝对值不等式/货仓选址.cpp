//给定数轴上若干商店的位置，选择一个货仓位置，使其到所有商店的距离之和最小。
// f(x)=|x1-x|+|x2-x|+...+|xn-x|
// =(|x1-x|+|xn-x|)+(|x2-x|+|x[n-1]-x|)+...（两两分组）
//选两个点之间能让每组最小
const int N =100005;
int n;
int a[N];
int ans;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) ans+=abs(a[i]-a[n/2+1]);
    cout << ans;

    return 0;
}