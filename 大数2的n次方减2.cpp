#include <bits/stdc++.h>
using namespace std;
string result="1";
void doub()
{
    int flag=0;
    for(int i=result.length()-1;i>=0;i--)
    {
        if((int)(result[i]-'0')*2+flag<10)
        {
            result[i]=(int)(result[i]-'0')*2+flag+'0';
            flag=0;
        }
        else
        {
            result[i]=(int)(result[i]-'0')*2+flag-10+'0';
            flag=1;
        }
    }
    if(flag)
    {
        result="1"+result;
    }
}
string js(int n)
{
    while(n--)
    {
        doub();
    }
    for (int i=result.length()-1;i>=0;i--) {
        if(result[i]>='1'){
            result[i]--;
            break;
        }else{
            result[i]='9';
        }
    }
    for(int i=result.length()-1;i>=0;i--)
        {
            if(result[i]>0)
            {
                result[i]--;
                break;
            }
            else
            {
                result[i]='9';
            }
        }
    return result;
}
signed main()
{
    int n;
    cin>>n;
    cout<<js(n)<<endl;
    return 0;
}
