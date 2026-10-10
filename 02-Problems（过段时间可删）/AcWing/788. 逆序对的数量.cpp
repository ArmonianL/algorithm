#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =1e6+2;
int a[N],t[N];
ll merge_sort(int a[],int l,int r)
{
    if(l>=r) return 0;
    int mid=(l+r) >> 1;
    ll res=merge_sort(a,l,mid)+merge_sort(a,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) t[k++]=a[i++];
        else t[k++]=a[j++],res+=mid-i+1;
    }
    while(i<=mid) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(int i=l,j=0;i<=r;i++,j++)
    {
        a[i]=t[j];
    }
    return res;//return不要忘记
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    cin >> a[i];
    cout << merge_sort(a,1,n);


    return 0;
}