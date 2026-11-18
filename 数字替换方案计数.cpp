#include <bits/stdc++.h>
using namespace std;
int k;
string n;
long long ans=1;
signed main()
{
    vector<pair<int,int> >a;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        a.push_back({temp1,temp2});
    }
int gz[10];
    for(int i=0;i<k;i++)
    {
        gz[a[i].first]++;
    }
    for(int i=0;i<n.length();i++)
    {
        if(gz[n[i]]!=0)ans*=gz[n[i]];  // BUG(未修): n[i] 是 char，当下标会越界/取错，应为 gz[n[i]-'0']
    }
    cout<<ans<<endl;
    return 0;
}
