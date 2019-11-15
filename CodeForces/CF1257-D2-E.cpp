#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 3e5;
int n,k[3],at[N],dp[N][3];
int rec(int idx,int p){
    int &ret=dp[idx][p];
    if(ret!=-1)return ret;
    if(idx==n)return ret=0;
    ret=100000000;
    if(p==2)return ret=rec(idx+1,p)+(at[idx]!=p);
    if(p==0)ret=rec(idx+1,p+2)+(at[idx]!=p);
    return ret=min(ret,min(rec(idx+1,p+1),rec(idx+1,p))+(at[idx]!=p));
}
int main() {
    for(int i=0;i<3;i++){
        cin>>k[i];
        n+=k[i];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<k[i];j++){
            int a;
            cin>>a;
            at[a-1]=i;
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<min(rec(0,0),min(rec(0,2),rec(0,1)));
    return 0;
}