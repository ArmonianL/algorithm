//时间复杂度非常小
const int N =100000010;
int a,b;

int get(vector<int> num,int l,int r)
{
    int res=0;
    for(int i=l;i<=r;i++)//注意要从l到r
    {
        res=res*10+num[i];
    }
    return res;
}

int count(int n,int x)//返回1-n所有数中x出现的次数
{
    int res=0;
    vector<int> num;
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    n=num.size();
    num.push_back(0);
    reverse(num.begin(),num.end());
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            //0不能当第一位
            if(x!=0)
            {
                if(x==num[1]) res+=get(num,i+1,n)+1;
                else if(x<num[1]) res+=pow(10,n-i);
            }
        }
        else 
        {
            if(x==0)
            {   
                res+=(get(num,1,i-1)-1)*pow(10,n-i);//把001-abc-1的加上
                //前面等于abc时
                if(x==num[i]) res+=get(num,i+1,n)+1;
                else if(x<num[i]) res+=pow(10,n-i);
            }
            else
            {
                res+=get(num,1,i-1)*pow(10,n-i);
                if(x==num[i]) res+=get(num,i+1,n)+1;
                else if(x<num[i]) res+=pow(10,n-i);
            }
        }
    }
    return res;
}

int main()
{
    while(cin >> a >> b,a || b)//不断输入，知道a,b为0,0为止
    {
        if(a>b) swap(a,b);
        for(int i=0;i<=9;i++)
        cout << count(b,i)-count(a-1,i) << ' ';
        cout << '\n';
    }

    return 0;
}