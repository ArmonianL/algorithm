//解决：寻找它左边或右边第一个比它大 / 比它小的元素
int stk[N],tt;
int a[N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) 
    {
        while(tt>=1 && stk[tt]>=a[i]) tt--;
        if(tt>=1) cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++tt]=a[i];
    }

    return 0;
}