/*
count number of white cells. first fix x(X) coodrinate then for each get minimum y(Yl) and maximum 
y(Yr) for each circle that can cover all cells (X,[Yl..Yr]) add this Yl and Yr to a vector, then do line sweep 
on this vector to get number of covered cells for fixed x.
O(W*N*log(N));
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

int n,w,h;
struct ci{
    int x,y,r;
    ci(int x,int y,int r):x(x),y(y),r(r){}
};
vector<ci > v; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h>>n;
    for(int i=0;i<n;i++){
        int x,y,r;
        cin>>x>>y>>r;
        v.push_back(ci(x,y,r));
    }
    int an=w*h;
    for(int c=0;c<w;c++){
        vector<pp > ev;
        for(int i=0;i<n;i++){
            ll d=v[i].r*1LL*v[i].r-(v[i].x-c)*1LL*(v[i].x-c);
            if(d<0)continue;
            double dd=sqrt(d*1.0);
            double yl=v[i].y-dd,yr=v[i].y+dd;
            yl-=1e-9;
            yr+=1e-9;
            ev.push_back({(int)ceil(yl),0});
            ev.push_back({(int)yr,1});
        }
        sort(ev.begin(),ev.end());
        int lo=-oo,cnt=0,ex=0;
        for(auto e:ev){
            if(e.second==0){
                if(cnt==0)lo=e.first;
                cnt++;
            }else{
                cnt--;
                if(cnt==0){
                    ex+=min(h-1,e.first)-max(lo,0)+1;
                }
            }
        }
        an-=ex;
    }
    cout<<an<<'\n';
    return 0;
}

