        //右性质左边界
        while(l<r)
        {
            int mid=(l+r) >> 1;//这句话放while里面！
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        //左性质右边界
        while(l<r)
        {
            int mid=(l+r+1) >> 1;
            if(a[mid]<=x) l=mid;
            else r=mid-1;
        }
