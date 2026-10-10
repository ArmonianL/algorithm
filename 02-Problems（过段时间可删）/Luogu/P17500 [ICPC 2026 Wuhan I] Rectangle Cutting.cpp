//https://www.luogu.com.cn/problem/P17500
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =5e5+3;
int n,m,q;
set<int> r,c;
multiset<int> rr,cc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    c.insert(0);
    c.insert(n);
    r.insert(0);
    r.insert(m);
    cc.insert(n);
    rr.insert(m);
    while(q--)
    {
        int op,x;cin >> op >> x;
        if(op==1)//纵
        {
            int R=*c.lower_bound(x);
            int L=*prev(c.lower_bound(x));
            cc.erase(cc.find(R-L));//只能删一段！！！
            cc.insert(R-x);
            cc.insert(x-L);
            c.insert(x);
        }
        else    
        {
            int R=*r.lower_bound(x);
            int L=*prev(r.lower_bound(x));
            rr.erase(rr.find(R-L));
            rr.insert(R-x);
            rr.insert(x-L);
            r.insert(x);
        }
        cout << (ll)(*cc.rbegin())*(*rr.rbegin()) << '\n';
    }


    return 0;
}