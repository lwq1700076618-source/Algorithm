#include <bits/stdc++.h>
using namespace std;
signed main()
{
    vector<int>dj1;
    vector<int>dj2;
    int x1,x2,y1,y2,n,mid,ans=0;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    while(n--)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        dj1.push_back((tmp1-x1)*(tmp1-x1)+(tmp2-y1)*(tmp2-y1));
        dj2.push_back((tmp1-x2)*(tmp1-x2)+(tmp2-y2)*(tmp2-y2))  // BUG(未修): 这一行末尾缺分号，编译不过
    }
    sort(dj1.begin(),dj1.end());
    int len=dj1.size();
    mid=1;
    while(mid<=len)
    {
        int max1,max2;
        for(int i=0;i<=mid-1;i++)
        {
            max1=max(max1,dj1[i]);
        }
        for(int i=mid;i<len;i++)
        {
            max2=max(max2,dj2[i]);
        }
        ans=min(ans,max1+max2);
        mid++;
    }
    cout<<ans<<endl;
    return 0;
}