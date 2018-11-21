/*
simple dp problem
dp[r][c][rem][msk];
at row r,col c,how many cheerleaders to put,mask of 4 bits for the sides that are covered by at least one..
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;
int const N=2e7+10,oo=1e9,M=5e6+10;
ll const OO=1e18;
int mod=1000007;
double const eps=5e-6;

int t,n,m,k,dp[22][22][501][16];
int getc(int r,int c){
    int ret=0;
    if(r==1)ret+=1;
    if(c==m)ret+=2;
    if(r==n)ret+=4;
    if(c==1)ret+=8;
    return ret;
}
int rec(int r,int c,int rem,int msk){
    int &ret=dp[r][c][rem][msk];
    if(ret!=-1)return ret;    
    if(rem==0)return ret=(msk==15);
    if(r==n&&c==m+1)return ret=0;
    if(c==m+1)return ret=rec(r+1,1,rem,msk);
    ret=rec(r,c+1,rem,msk);
    int ro=getc(r,c);
    ret+=rec(r,c+1,rem-1,msk|ro);
    ret%=mod;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    int y=1;
    while(t--){
        cin>>n>>m>>k;
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<y<<": "<<rec(1,1,k,0)<<'\n';
        y++;
    }
    return 0;
}



