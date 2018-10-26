/*
easy dp problem not too much to talk about..
just some implementation tricks
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 3e5 + 10,M=5e4+5, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

int n,k,aa[1001],dp[1001][1<<9],rev[1001];
vector<int > at[9];
int rec(int idx,int c){
    int &ret=dp[idx][c];
    if(ret!=-1)return ret;
    if(idx==n){
        if(k&&bitset<9>(c).count()!=8)return ret=-oo;
        return ret=0;
    }
    ret=rec(idx+1,c);
    if(((1<<aa[idx])&c)||rev[idx]+k-1>=(int)at[aa[idx]].size())return ret;
    if(k)ret=max(
        rec(at[aa[idx]][rev[idx]+k-1]+1,
        c|(1<<aa[idx]))+k,
        ret);
    if(rev[idx]+k<(int)at[aa[idx]].size())ret=max(ret,rec(at[aa[idx]][rev[idx]+k]+1,c|(1<<aa[idx]))+k+1);
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aa[i];
        rev[i]=at[aa[i]].size();
        at[aa[i]].push_back(i);
    }
    int mx=0;
    for(int i=0;i<=n/8+1;i++){
        k=i;
        memset(dp,-1,sizeof dp);
        mx=max(mx,rec(0,0));
    }
    cout<<mx;
    return 0;
}



