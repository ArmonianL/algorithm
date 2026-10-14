//O(Cnm)
const int N =20;
int n,m;

vector<int> res;
void calc(int x)
{
    //选的超过m了或者选的加上剩下的所有都达不到m
    if(res.size()>m || res.size()+(n-x+1)<m) return;//剪枝   

    if(x==n+1)
    {
        for(auto i:res) cout << i << ' ';
        cout << '\n';
        return;
    }

    calc(x+1);

    res.push_back(x);
    calc(x+1);
    res.pop_back();
}

int main()
{
    cin >> n >> m;
    calc(1);

    return 0;
}