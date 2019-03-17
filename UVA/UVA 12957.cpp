/*
first sort the points,then fix one point and check all other points with it
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

int n;
pp v[3001];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>n&&!cin.eof()){
      for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
      sort(v,v+n);
      int an=0;
      for(int i=0;i<n;i++){
          int y=v[i].second;
          vector<pp > und,ab;
          for(int j=i+1;j<n;j++){
              if(v[j].second<y)und.push_back(v[j]);
              else ab.push_back(v[j]);
          }
          sort(und.begin(),und.end());
          sort(ab.begin(),ab.end());
          int s=-oo;
          for(int j=0;j<sz(und);j++){
              if(und[j].second>s){
                  s=und[j].second;
                  an++;
              }
          }
          s=oo;
          for(int j=0;j<sz(ab);j++){
              if(ab[j].second<s){
                  s=ab[j].second;
                  an++;
              }
          }
      }
      cout<<an<<'\n';
  }
  return 0;
}
