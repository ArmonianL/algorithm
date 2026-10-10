#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =300010;
int n;
vector<int> v;
ll ans;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;cin >> x;
        v.push_back(x);
    }
    v.push_back(0);
    sort(v.begin(),v.end());

    int l=0,r=v.size()-1;
    while(l<r)
    {
        int mid=(l+r) >> 1;
        if(v[mid]>=0) r=mid;
        else l=mid+1;
    }

    int i=l;
    
    int a,b;
    if(i==0)
    {
        a=-1;
        b=1;
    }
    else if(i==v.size()-1)
    {
        a=i-1;
        b=i+1;
    }
    else 
    {
        a=i-1;
        b=i+1;
    }


   for(int cnt=1;cnt<=n;cnt++)
   {
    if(b>n)
        {
            ans+=v[i]-v[a];
            i=a;
            a--;
        }
        else if(a<0)
        {
            ans+=v[b]-v[i];
            i=b;
            b++;
        }
        else if(v[i]-v[a]<=v[b]-v[i])
        {
            ans+=v[i]-v[a];
            i=a;
            a--;
        }
        else 
        {
            ans+=v[b]-v[i];
            i=b;
            b++;
        }
   }

    cout << ans;
  



    return 0;
}