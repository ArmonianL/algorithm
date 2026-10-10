#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
int n,m,x;
int a[N],b[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int i=0,j=m-1;
    while(i<=n&&j>=0)
    {
        int sum=a[i]+b[j];
        if(sum==x)
        {
            cout << i << ' ' << j;
            break;
        }
        else if(sum>x) j--;
        else i++;
    }    
    


    return 0;
}