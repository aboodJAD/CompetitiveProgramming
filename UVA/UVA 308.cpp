/*
compress line segments then find number of holes using dfs.
for compression, keep the line segments spaced s.t each formed rectangle has at least one zero(unvisited cell using dfs) inside it;
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=600,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

struct segment{
    int a,b,c,d;
    segment(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};
int n;
vector<segment > seg;
vector<int > xx,yy;
map<int,int > mpx,mpy;
int gg[N][N],vis[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
bool valid(int y,int x){
    return y>-1&&x>-1&&y<N&&x<N;
}
void dfs1(int r,int c){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dy[i],nc=c+dx[i];
        if(!valid(nr,nc))continue;
        if(!vis[nr][nc])dfs1(nr,nc);
    }
}
void dfs2(int r,int c){
	int y=vis[r][c];
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dy[i],nc=c+dx[i];
        if(!valid(nr,nc))continue;
        if(y==0&&vis[nr][nc]!=1)dfs2(nr,nc);
        else if(y==2&&vis[nr][nc]==0)dfs2(nr,nc);
    }
}
void solve(){
	xx.clear();
	yy.clear();
	seg.clear();
	mpx.clear();
	mpy.clear();
	memset(gg,0,sizeof gg);
	memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        seg.push_back(segment(a,b,c,d));
        xx.push_back(a);
        xx.push_back(c);
        yy.push_back(b);
        yy.push_back(d);
    }
    int mx1=0,mx2=0;;
    sort(xx.begin(),xx.end());
    xx.resize(unique(xx.begin(),xx.end())-xx.begin());
    sort(yy.begin(),yy.end());
    yy.resize(unique(yy.begin(),yy.end())-yy.begin());
    for(int i=0;i<sz(xx);i++)mpx[xx[i]]=(i+1)*2;
    for(int i=0;i<sz(yy);i++)mpy[yy[i]]=(i+1)*2;
    for(int i=0;i<n;i++){
        seg[i].a=mpx[seg[i].a];
        seg[i].c=mpx[seg[i].c];
        seg[i].b=mpy[seg[i].b];
        seg[i].d=mpy[seg[i].d];
        mx1=max(mx1,max(seg[i].a,seg[i].c));
        mx2=max(mx2,max(seg[i].b,seg[i].d));        
        for(int j=min(seg[i].a,seg[i].c);j<=max(seg[i].a,seg[i].c);j++){
            for(int k=min(seg[i].d,seg[i].b);k<=max(seg[i].b,seg[i].d);k++)vis[k][j]=2;
        }
    }
    dfs1(0,0);

    int an=0;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1;j++){
            if(vis[i][j]==2&&vis[i+1][j]==2&&vis[i][j+1]==2&&!vis[i+1][j+1]){
                dfs2(i+1,j+1);
                an++;
            }
        }
    }
    cout<<an<<'\n';	
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n&&n)solve();
    return 0;
}

