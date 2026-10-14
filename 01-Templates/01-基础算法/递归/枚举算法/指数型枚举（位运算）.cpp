//O(2^n)
const int N =20;
int n;

int main()
{
    cin >> n;
    for(int i=(1 << n)-1;i>=0;i--)//不要忘记-1
    {
        for(int k=0;k<=n-1;k++)
        {
            if(i >> k & 1) cout << k+1 << ' ';
        }
        cout << '\n';
    }    

    return 0;
}