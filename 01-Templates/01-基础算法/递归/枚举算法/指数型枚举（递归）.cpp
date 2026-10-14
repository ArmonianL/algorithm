//O(2^n)
//选和不选
vector<int> res;
void calc(int x)//当前问题是下一个问题的父问题，也是上一个问题的子问题
{
    //身份是父问题
    if(x==n+1)
    {
        for(auto i:res) cout << i << ' ';
        cout << '\n';
        return;
    }
    calc(x+1);
    
    res.push_back(x);
    calc(x+1);
    res.pop_back();//还原现场，这里的身份是上一个问题的子问题
}

int main()
{
    cin >> n;
    calc(1);

    return 0;
}