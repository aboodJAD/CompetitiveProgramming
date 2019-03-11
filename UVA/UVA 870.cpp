/*
compress rectangles then flood fill from first rectangle 
and for each cell calculate it's area.
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=400,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

struct rect{
  int r1,c1,r2,c2;
  rect(int r1,int c1,int r2,int c2):r1(r1),c1(c1),r2(r2),c2(c2){}
};
int t,n,gg[N][N],vis[N][N];
vector<rect > all;
vector<int > xx,yy;
map<int,int > ax,ay;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
ll res;
bool valid(int r,int c){
  return r>-1&&r<N&&c>-1&&c<N;
}
void dfs(int r,int c){
  vis[r][c]=1;
//  res++;
  res+=(ay[r+1]-ay[r])*1LL*(ax[c+1]-ax[c]);
  for(int i=0;i<4;i++){
    int nr=r+dy[i],nc=c+dx[i];
    if(valid(nr,nc)&&!vis[nr][nc]&&gg[nr][nc])dfs(nr,nc);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  bool bl=0;
  while(t--){
    xx.clear();
    ay.clear();
    yy.clear();
    ay.clear();
    all.clear();                
    if(bl)cout<<'\n';
    bl=1;
    cin>>n;
    for(int i=0;i<n;i++){
      int r1,c1,r2,c2;
      cin>>r1>>c1>>r2>>c2;
      assert(!(r1==r2&&c1==c2));
      r2--,c2--;
      all.push_back(rect(r1,c1,r2,c2));
      yy.push_back(r1);
      yy.push_back(r2);
      xx.push_back(c1);
      xx.push_back(c2);
      r1++,c1++,r2++,c2++;
      yy.push_back(r1);
      yy.push_back(r2);
      xx.push_back(c1);
      xx.push_back(c2);      
    }
    sort(yy.begin(),yy.end());
    sort(xx.begin(),xx.end());
    yy.resize(unique(yy.begin(),yy.end())-yy.begin());
    xx.resize(unique(xx.begin(),xx.end())-xx.begin());
    for(int i=0;i<sz(xx);i++)ax[i]=xx[i];
    for(int i=0;i<sz(yy);i++)ay[i]=yy[i];
    memset(gg,0,sizeof gg);
    memset(vis,0,sizeof vis);   
    for(int c=0;c<n;c++){
      all[c].r1=lower_bound(yy.begin(),yy.end(),all[c].r1)-yy.begin();
      all[c].r2=lower_bound(yy.begin(),yy.end(),all[c].r2)-yy.begin();
      all[c].c1=lower_bound(xx.begin(),xx.end(),all[c].c1)-xx.begin();
      all[c].c2=lower_bound(xx.begin(),xx.end(),all[c].c2)-xx.begin();
      for(int i=min(all[c].r1,all[c].r2);i<=max(all[c].r1,all[c].r2);i++){
        for(int j=min(all[c].c1,all[c].c2);j<=max(all[c].c1,all[c].c2);j++)gg[i][j]=1;
      }
    }
    dfs(all[0].r1,all[0].c1);
    cout<<res<<'\n';
    res=0;
  }
  return 0;
}


