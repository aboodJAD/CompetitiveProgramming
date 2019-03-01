/*
dp solution:
dp[i][j]=max length of substring of character j formed in string ((a[1]*a[2])...a[i]); 
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

string p[N];
int dp[N][26],n;
void calc(int idx){
    int len=0,pre=-1;
    for(int i=0;i<sz(p[idx]);i++){
        if(pre!=p[idx][i]){
            if(pre!=-1)dp[idx][pre-'a']=max(dp[idx][pre-'a'],len);
            len=1;
            pre=p[idx][i];
        }else len++;
    }
    dp[idx][pre-'a']=max(dp[idx][pre-'a'],len);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>p[i];
    calc(0);
    for(int i=1;i<n;i++){
        if(count(p[i].begin(),p[i].end(),p[i][0])==sz(p[i])){
            for(int j=0;j<26;j++)if(j!=p[i][0]-'a')dp[i][j]=dp[i-1][j]>0;
            dp[i][p[i][0]-'a']=dp[i-1][p[i][0]-'a']+(dp[i-1][p[i][0]-'a']+1)*sz(p[i]);
        }else{
            calc(i);
            int f=p[i][0]-'a',e=p[i].back()-'a';
            int cntf=0,cnte=0;
            for(int j=0;j<sz(p[i])&&p[i][j]-'a'==f;j++)cntf++;
            for(int j=sz(p[i])-1;j>-1&&p[i][j]-'a'==e;j--)cnte++;
            dp[i][f]=max(dp[i][f],cntf+(dp[i-1][f]>0));
            dp[i][e]=max(dp[i][e],cnte+(dp[i-1][e]>0));
            if(f==e)dp[i][f]=max(dp[i][f],(cntf+cnte+1)*(dp[i-1][f]>0));
            for(int j=0;j<26;j++)if(dp[i][j]==0)dp[i][j]=dp[i-1][j]>0;
        }
/*        for(int j=0;j<26;j++)cout<<dp[i][j]<<' ';
        cout<<endl;*/
    }
    int mx=0;
    for(int i=0;i<26;i++)mx=max(mx,dp[n-1][i]);
    cout<<mx;
    return 0;
}

