// 一维差分：预处理 O(n)，区间修改 O(1)，还原 O(n)
void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    for(int i=1;i<=n;i++)
    insert(i,i,a[i]);

    while(m--)
    {
        int l,r,c;cin >> l >> r >> c;
        insert(l,r,c);
    }
    //对b求前缀和（把b变成a数组）
    for(int i=1;i<=n;i++)
    b[i]+=b[i-1];
}