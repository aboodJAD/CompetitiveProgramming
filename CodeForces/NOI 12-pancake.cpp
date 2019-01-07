/*
i don't have a proof for my solution
all i do is just dp[depth][vector<int >];
depth is number of reverse operations
using trial and error the answer is less than or equal to N+1
and thus AC
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=3e5+10,oo=1e9,M=1e6+2;
ll const OO=1e18;
double const eps=1e-6,PI=acos(-1);
int mod=oo+7;
vector<int > o;
int n;
map<vector<int > ,int > dp[10];
int rec(int dep,vector<int > v){
    if(v==o)return dep;
    if(dep>n)return oo;
    if(dp[dep].find(v)!=dp[dep].end())return dp[dep][v];
    int ret=oo;
    for(int i=0;i<n-1;i++){
        reverse(v.begin()+i,v.end());
        ret=min(ret,rec(dep+1,v));
        reverse(v.begin()+i,v.end());
    }
    return dp[dep][v]=ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int > a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        o=a;
        sort(o.begin(),o.end());
        reverse(o.begin(),o.end());
        cout<<rec(0,a)<<'\n';
    }
    return 0;
}