#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
string s;
stack<int> num;
stack<char> op;

void cal()//每次只计算一次
{
    auto a=num.top();num.pop();
    auto b=num.top();num.pop();
    auto c=op.top();op.pop();

    int res=0;
    if(c=='+') res=b+a;
    else if(c=='-') res=b-a;
    else if(c=='*') res=b*a;
    else res=b/a;

    num.push(res);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    unordered_map<char,int> p{{'+',1},{'-',1},{'*',2},{'/',2}};

    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(isdigit(c))
        {
            int j=i;
            int t=0;
            while(j<=s.size()-1 && isdigit(s[j]))
            {
                t=t*10+(s[j]-'0');
                j++;
            }
            i=j-1;
            num.push(t);
        }
        else if(c=='(') op.push('(');
        else if(c==')') 
        {
            while(op.top()!='(')
            {
                cal();
            }
            op.pop();
        }
        else 
        {
            while(op.size() && p[op.top()]>=p[c] && op.top()!='(') cal();//这里的非空一定要先判断，不然不能取top，也就是&&的顺序注意一下
            op.push(c);
        }
    }

    while(num.size()>1) cal();

    cout << num.top();



    return 0;
}