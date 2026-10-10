//O(nlogn)
const int N =100010;
int a[N];
vector<int> f;//f[i]:长度为i+1的最小结尾值

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++)
    {
        int l=0,r=f.size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(f[mid]>=a[i]) r=mid;//明白了，x只能接在严格小于x的数后面，所以要找>=x的位置
            else l=mid+1;
        }
        if(l==f.size()) f.push_back(a[i]);
        else 
        {
            f[l]=a[i];
        }
    }
    cout << f.size();

    return 0;
}