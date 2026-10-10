int q[N],hh,tt=-1;

int main()
{
    while(m--)
    {
        string s;cin >> s;
        if(s=="push")
        {
            int x;cin >> x;
            q[++tt]=x;
        }
        else if(s=="pop")
        {
            hh++;//这里一定是++
        }
        else if(s=="empty")
        {
            if(tt>=hh) cout << "NO\n";
            else cout << "YES\n";
        }
        else if(s=="query")
        {
            cout << q[hh] << '\n';
        }
    }

    return 0;
}