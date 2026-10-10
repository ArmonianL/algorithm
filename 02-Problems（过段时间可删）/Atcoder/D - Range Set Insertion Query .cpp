// https://atcoder.jp/contests/abc478/tasks/abc478_d
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N=200010;
int n, q;
vector<pair<PII, int>> v, res;
int b[N];

void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        v.push_back({{l, r}, x});
    }

    // 先按 x 排序，再按 l 排序
    sort(v.begin(), v.end(), [](auto &a, auto &b)
    {
        if(a.second != b.second)
            return a.second < b.second;
        if(a.first.first != b.first.first)
            return a.first.first < b.first.first;
        return a.first.second < b.first.second;
    });

    int st = -2e9, ed = -2e9;
    int last_x = -1;
    for(auto &[p, x] : v)
    {
        int l = p.first;
        int r = p.second;

        //x 变了，说明上一组结束
        if(x != last_x)
        {
            if(last_x != -1)
                res.push_back({{st, ed}, last_x});

            st = l;
            ed = r;
            last_x = x;
        }
        else
        {
            //同一个 x，正常合并区间
            if(ed < l)
            {
                res.push_back({{st, ed}, x});
                st = l;
                ed = r;
            }
            else
            {
                ed = max(ed, r);
            }
        }
    }

    // 最后一段
    if(last_x != -1)
        res.push_back({{st, ed}, last_x});

    for(auto &[p, x] : res) insert(p.first,p.second,1);

    for(int i=1;i<=n;i++) b[i]+=b[i-1];

    for(int i=1;i<=n;i++) cout << b[i] << ' ';

    

    return 0;
}