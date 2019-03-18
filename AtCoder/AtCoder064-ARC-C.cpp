/*
consider the optimal path, it's a roads between circles, imagine circles as nodes then we need to find minimum distance from starting point to distination point. apply dijkestra on the graph
first push into priority_queue all circles with cost equal to distance from starting point.
after finishing dijkestra find minimum distance from each circle to distination point, and this will be the answer.
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

struct circle{
    int x,y,r;
    circle(){};
    circle(int x,int y,int r):x(x),y(y),r(r){}
};

int n;
int a,b,c,d;
circle all[1001];
priority_queue<pair<double,int > > q;
double cost[1001];
bool vis[1001];
double dist(pp a,pp b){
    return sqrt((a.first-b.first)*1LL*(a.first-b.first)+
        (a.second-b.second)*1LL*(a.second-b.second));
}
double distc(int i,int j){
    double dd=dist({all[i].x,all[i].y},{all[j].x,all[j].y});
    dd+=-all[i].r-all[j].r;
    if(dd<0)dd=0;
    return dd;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c>>d;
  cin>>n;
  for(int i=0;i<n;i++){
      cost[i]=OO;
      int x,y,r;
      cin>>x>>y>>r;
      all[i]=circle(x,y,r);
  }
  double mn=dist({a,b},{c,d});
  for(int i=0;i<n;i++){
      double dd=dist({a,b},{all[i].x,all[i].y});
      if(dd<=all[i].r){
          q.push({0,i});
          cost[i]=0;
      }else {
          dd-=all[i].r;
          q.push({-dd,i});
          cost[i]=dd;
      }
  }
  while(!q.empty()){
      auto cur=q.top();q.pop();
      double d=-cur.first;
      int idx=cur.second;
      if(vis[idx])continue;
      vis[idx]=1;
      for(int i=0;i<n;i++){
          if(i==idx)continue;
          double need=distc(idx,i);
          if(!vis[i]&&cost[i]>need+d){
              cost[i]=need+d;
              q.push({-cost[i],i});
          }
      }
  }
  for(int i=0;i<n;i++)mn=min(mn,max(0.0,dist({c,d},{all[i].x,all[i].y})-all[i].r)+cost[i]);
  cout<<fixed<<setprecision(10)<<mn<<'\n';
  return 0;
}
