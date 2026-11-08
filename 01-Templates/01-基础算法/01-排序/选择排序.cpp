//O(n^2)

void select_sort(int a[],int l,int r)
{
    int n=r-l+1;
    for(int i=0;i<n;i++)
    {
        int t=1+i;
        for(int j=1+i;j<=r;j++)
        {
            if(a[j]<a[t]) t=j;
        }
        swap(a[t],a[1+i]);
    }
}
