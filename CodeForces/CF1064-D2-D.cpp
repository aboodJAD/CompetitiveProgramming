/*
0/1 BFS:
the hardest part is to conclude that the normal BFS will reach cells with different 
left,right L,R values, so we need to minimize both steps.
we can not use them in the state of BFS(X,Y too large)
the second hardest part is to observe that both values of L,R steps
depend on col positions of starting cell (c1) and explored cell (c2)
R-L = c2-c1 = constant;
remember we need to minimize L,R
from above we can coclude that if we decrease L then we decrease R and vice versa(we can choose R to decrease)
because R=const+L
and thus if we are going to go left then this edge is of cost 1, otherwise it's of cost 0
applying 0/1 BFS..problem is done
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=64;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,m;
int r,c;
int cl,cr;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[2001][2001];
char gg[2001][2005];
bool valid(int r,int c){
    return r>-1&&r<n&&c<m&&c>-1&&gg[r][c]=='.';
}
void bfs(){
   deque<pair<pp,pp > > q;
   q.push_front({{r-1,c-1},{0,0}});
   int an=0;
   while(!q.empty()){
      auto fr=q.front();q.pop_front();
      int r,c,ccl,ccr;
      r=fr.first.first;
      c=fr.first.second;
      ccl=fr.second.first;
      ccr=fr.second.second;
      if(vis[r][c])continue;
      vis[r][c]=1;
      if(ccl<=cl&&ccr<=cr)an++;
      for(int i=0;i<4;i++){
          int nr=r+dy[i],nc=c+dx[i];
          if(!valid(nr,nc)||vis[nr][nc])continue;
          if(dx[i]==-1)q.push_back({{nr,nc},{ccl+1,ccr}});
          else q.push_front({{nr,nc},{ccl,ccr+dx[i]}});
      }
   }
   cout<<an;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>r>>c>>cl>>cr;
    for(int i=0;i<n;i++)cin>>gg[i];
    bfs();
    return 0;
}
