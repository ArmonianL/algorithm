//O(n^2)

void insert_sort(int a[],int l,int r)//依次把每个数插入到前面已经拍好序的序列中
{
    for(int i=l;i<=r;i++)
    {
        int t=a[i];
        int j=i-1;
        while(j>=l && a[j]>t)
        {
            a[j+1]=a[j];//大的往后移动一格
            j--;
        }
        a[j+1]=t;
    }
}
