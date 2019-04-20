#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=1e6+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t;
int tot[N];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=2;i<N;i++)tot[i]=i;
  for(int i=2;i<N;i++){
      if(tot[i]==i){
          tot[i]=i-1;
          for(int j=i+i;j<N;j+=i)tot[j]=tot[j]-tot[j]/i;
      }
  }
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      cout<<tot[n]*1LL*(n-1)<<'\n';
  }
  return 0;
}