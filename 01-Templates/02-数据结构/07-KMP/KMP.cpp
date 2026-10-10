char p[N],s[N];//p模式串，s完整串
int ne[N];

int main()
{
    cin >> n >> p+1 >> m >> s+1;
    //j表示已经匹配的个数
    //构造和匹配的前两步一样，都是为了得到以下两种情况之一：1.和当前i匹配上 2.j=0（一个都不匹配）
    ne[1]=0;
    for(int i=2,j=0;i<=n;i++)
    {
        while(j && p[j+1]!=p[i]) j=ne[j];
        if(p[j+1]==p[i]) j++;
        ne[i]=j;
    }

    for(int i=1,j=0;i<=m;i++)
    {
        while(j && p[j+1]!=s[i])j=ne[j];//如果不匹配了，就一直把模式串跳转，直到下一个匹配或者j=0为止
        if(p[j+1]==s[i]) j++;//if不能省略，while结束后有两种情况，只有匹配上的才能j++
        if(j==n)
        {
            cout << i-j+1-1 << ' ' ;
        }   
    }

    return 0;
}