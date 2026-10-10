#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =300010;
int q,v;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q >> v;

    priority_queue<int> pq;

    while(q--)
    {
        int tt;cin >> tt;
        if(tt==1)
        {
            int t,w;cin >> t >> w;
            pq.push(w-t);
        }
        else 
        {
            int t;cin >> t;
            if(pq.empty()) cout << -1 << '\n';
            else 
            {
                cout << min(pq.top()+t,v) << '\n';
                pq.pop();
            }
        }
    }    


    return 0;
}