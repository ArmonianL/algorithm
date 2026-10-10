int lowbit(int x)//返回x的二进制最后一个1
{
    return x&-x;
}
