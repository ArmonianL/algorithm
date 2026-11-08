//O(n^2)

void maopao(int a[],int l,int r)
{
    for(int i=r;i>=l+1;i--)//每次最大的跑到最右边
    {
        for(int j=1;j<=r-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
