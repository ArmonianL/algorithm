// 时间复杂度：状态总数的线性时间复杂度 O(8!)

// 题目：给定2×4魔板的目标状态，求从初始状态到目标状态的最少操作次数及操作序列。
// 初始状态    A：交换两行    B：循环右移    C：中央四格顺时针旋转
// 1 2 3 4     8 7 6 5       4 1 2 3       1 7 2 4
// 8 7 6 5     1 2 3 4       5 8 7 6       8 6 3 5

// 思路：状态空间 BFS，每个状态用一个长度为 8 的字符串表示。
// 对应字符串：
// 初始状态： "12345678"
// A 操作后： "87654321"
// B 操作后： "41236785"
// C 操作后： "17245368"
string st,ed;

//状态bfs的d和vis一般用unordered_map
unordered_map<string,int> d;//d+vis:<状态,最少步数>
unordered_map<string,pair<char,string>> pre;//<状态,<上一个操作,上一个状态>>

//set和get为三个move函数服务
void set(string s,char g[3][5])//将字符串s放进图g中
{
    for(int i=1;i<=4;i++) g[1][i]=s[i-1];
    for(int i=4;i>=1;i--) g[2][i]=s[8-i];
}

string get(char g[3][5])//将图g转换成字符串
{
    string s;
    for(int i=1;i<=4;i++) s+=g[1][i];
    for(int i=4;i>=1;i--) s+=g[2][i];
    return s;
}

string move0(string s)
{
    char g[3][5];
    ::set(s,g);//使用全局命名空间中自己定义的 set 函数

    for(int i=1;i<=4;i++) swap(g[1][i],g[2][i]);

    return get(g);
}

string move1(string s)
{
    char g[3][5];
    ::set(s,g);

    char a=g[1][4],b=g[2][4];
    for(int i=4;i>=2;i--) 
    {
        g[1][i]=g[1][i-1];
        g[2][i]=g[2][i-1];
    }
    g[1][1]=a;
    g[2][1]=b;
    
    return get(g);
}

string move2(string s)
{
    char g[3][5];
    ::set(s,g);

    char a=g[1][2];
    g[1][2]=g[2][2];
    g[2][2]=g[2][3];
    g[2][3]=g[1][3];
    g[1][3]=a;

    return get(g);
}

//其实这三个操作可以直接打表：
// string get(string t, int op) {
//     string k;
//     if (op == 0) k = {t[4], t[5], t[6], t[7], t[0], t[1], t[2], t[3]};
//     if (op == 1) k = {t[3], t[0], t[1], t[2], t[7], t[4], t[5], t[6]};
//     if (op == 2) k = {t[0], t[5], t[1], t[3], t[4], t[6], t[2], t[7]};
//     return k;
// }

void bfs(string st,string ed)
{
    queue<string> q;

    d[st]=0;
    q.push(st);
    
    while(q.size())
    {
        auto t=q.front();
        q.pop();

        if(t==ed) return;//剪枝

        string m[3];
        m[0]=move0(t);
        m[1]=move1(t);
        m[2]=move2(t);

        for(int i=0;i<3;i++)
        {
            string s=m[i];

            if(d.count(s)!=0) continue;

            d[s]=d[t]+1;
            pre[s]={i+'A',t};
            q.push(s);
        }
    }
}

int main()
{
    for(int i=1;i<=8;i++)
    {
        int x;cin >> x;
        ed+=char(x+'0');
    }

    st="12345678";
    
    bfs(st,ed);

    cout << d[ed] << '\n';

    string ans;//最短路的操作路径（A,B,C组成的字符串）
    while(ed!=st)//这个判断很重要！！！
    {
        ans+=pre[ed].first;
        ed=pre[ed].second;
        if(ed==st) break;
    }

    reverse(ans.begin(),ans.end());

    cout << ans;

    return 0;
}