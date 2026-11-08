//O(nlogn)

int a[N],t[N];

void merge_sort(int a[],int l,int r)
{
    if(l>=r) return ;

    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    int i=l,j=mid+1;
    int cnt=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<a[j]) t[++cnt]=a[i++];
        else t[++cnt]=a[j++]; 
    }
    while(i<=mid) t[++cnt]=a[i++];
    while(j<=r) t[++cnt]=a[j++];

    for(int i=l,j=1;i<=r;i++,j++) a[i]=t[j];
}
