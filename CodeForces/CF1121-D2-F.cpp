#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=5002,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n,a,b,c=31,po[N];
string s;
map<int,int > lst;
int dp[N],can[N],z[N];
void z_calc(string s){
  memset(z,0,sizeof z);
  z[0]=1;
  int n=s.size();
  for(int i=1,r=0,l=0;i<n;i++){
      if(i<=r)z[i]=min(r-i+1,z[i-l]);
      while(i+z[i]<n&&s[z[i]]==s[i+z[i]])++z[i];
      if(i+z[i]>r)l=i,r=i+z[i]-1;
  }
}
int rec(int idx){
    int &ret=dp[idx];
    if(ret!=-1)return ret;
    if(idx==n)return ret=0;
    ret=rec(idx+1)+a;
    for(int j=idx;j<n&&j-idx+1<=idx;j++)
      if(j-idx+1<=can[idx])ret=min(ret,rec(j+1)+b);
    return ret;
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a>>b;
  cin>>s;
  for(int i=1;i<n;i++){
    string sub=s.substr(i,n);
    sub+='@';
    int j=sub.size();
    sub+=s.substr(0,i);
    z_calc(sub);
    for(;j<=n;j++)can[i]=max(can[i],z[j]);
  }
  memset(dp,-1,sizeof dp);
  cout<<rec(0);
  return 0;
}

