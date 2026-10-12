#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =105;
int n;
int ans;
char s[N];


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;)
    {
        
        if(s[i]!='R')
        {
            i++;
            continue;
        }
        int j=i+1;
        while(j<=n && s[j]=='R') j++;
        ans=max(ans,j-i);
        i=j;
    }
    cout << ans;


    return 0;
}