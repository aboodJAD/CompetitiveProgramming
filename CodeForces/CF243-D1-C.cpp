/*
compress the grid, then mark movements(lines) as 1 in a binary grid.
do dfs from cell (0,0) and mark all reachable cells.
now all unreachable cells using dfs are the ones we care about, 
for each unvisited cell calculate it's actual area and add it to answer.
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=2005,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

struct segment{
    int xf,yf,xt,yt;
    segment(int xf,int yf ,int xt,int yt):xf(xf),yf(yf),xt(xt),yt(yt){}
};
int n;
map<int,int> mapx,mapy;
vector<segment > seg;
vector<int > inx,iny;
int gg[N][N];
bool vis[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool  valid(int r,int c){
    return r>-1&&c>-1&&r<N&&c<N;
}
void dfs(int r,int c){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dy[i],nc=c+dx[i];
        if(valid(nr,nc)&&!vis[nr][nc]&&gg[nr][nc]==0)dfs(nr,nc);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        char d;
        int r;
        cin>>d>>r;
        int px=x,py=y;
        if(d=='U')y-=r;
        else if(d=='D')y+=r;
        else if(d=='L')x-=r;
        else x+=r;
        seg.push_back(segment(px,py,x,y));
        inx.push_back(x);
        inx.push_back(px);
        iny.push_back(y);
        iny.push_back(py);
        inx.push_back(x+1);
        inx.push_back(px+1);
        iny.push_back(y+1);
        iny.push_back(py+1);
    }
    sort(inx.begin(),inx.end());
    sort(iny.begin(),iny.end());
    inx.resize(unique(inx.begin(),inx.end())-inx.begin());
    iny.resize(unique(iny.begin(),iny.end())-iny.begin());
    int j=1;
    for(auto v:inx)mapx[j]=v,j++;
    j=1;
    for(auto v:iny)mapy[j]=v,j++;
    for(int i=0;i<n;i++){
        int nx=seg[i].xt,ny=seg[i].yt,npx=seg[i].xf,npy=seg[i].yf;
        nx=lower_bound(inx.begin(),inx.end(),seg[i].xt)-inx.begin();
        nx++;
        npx=lower_bound(inx.begin(),inx.end(),seg[i].xf)-inx.begin();
        npx++;
        ny=lower_bound(iny.begin(),iny.end(),seg[i].yt)-iny.begin();
        ny++;
        npy=lower_bound(iny.begin(),iny.end(),seg[i].yf)-iny.begin();
        npy++;
        mapx[nx]=seg[i].xt;
        mapx[npx]=seg[i].xf;
        mapy[ny]=seg[i].yt;
        mapy[npy]=seg[i].yf;
        if(nx==npx)for(int j=min(npy,ny);j<=max(ny,npy);j++)gg[j][nx]=1;
        else for(int j=min(npx,nx);j<=max(nx,npx);j++)gg[ny][j]=1;
        
    }
    dfs(0,0);
    ll an=0;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1;j++){
        	if(vis[i][j])continue;
        	an+=(mapy[i+1]-mapy[i])*1LL*(mapx[j+1]-mapx[j]);
        }
    }
    cout<<an<<'\n';
    return 0;
}
