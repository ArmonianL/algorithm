int stk[N],tt;

int main()
{
    while(m--)
    {
        string s;cin >> s;
        if(s=="push")
        {
            int x;cin >> x;
            stk[++tt]=x;
        }
        else if(s=="pop")
        {
            tt--;
        }
        else if(s=="empty")
        {
            if(tt>=1) cout << "NO\n";
            else cout << "YES\n";
        }
        else if(s=="query")//栈顶
        {
            cout << stk[tt] << '\n';
        }
    }

    return 0;
}