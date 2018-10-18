/*
first i think of greedy solution..then i realized it will not work..
then i write this formula: answer=SUM[i=1...n](Ci)+SUM[i=1...n](Ti*Deltai)
where Ti is the time until reaching i'th section..
then i realized that i can use dp to solve this...
if i need Ti to walk a distance to the next section then this Ti will be multiply 
by all remaining sections that are'nt repaired yet..
so the dp[i][j][k] the minimum cost needed to repair sections from 1 to i and from j to n if the last section 
was repaired is either i+1 or j-1;
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 1e5 + 10,M=1e6+1, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

struct dat{
    int x,c,d;
    dat(int x,int c,int d):x(x),c(c),d(d){}
};
int n,v,x,cum[1002];
vector<dat > sec;
double dp[1002][1002][2];
bool comp(dat &a,dat &b){
    return a.x<b.x;
}
double tim(int d,int v){
    return d*1.0/v;
}
double rec(int l,int r,int t){
    double &ret=dp[l][r][t];
    if(ret==ret)return ret;
    if(!l&&r==n+1)return ret=0;
    ret=oo*2;
    if(t){
        if(l)ret=min(ret,tim(sec[r-1].x-sec[l].x,v)*(cum[l]+cum[n]-cum[r-1])+rec(l-1,r,!t));
        if(r<=n)ret=min(ret,tim(sec[r].x-sec[r-1].x,v)*(cum[l]+cum[n]-cum[r-1])+rec(l,r+1,t));
    }else{
        if(l)ret=min(ret,tim(sec[l+1].x-sec[l].x,v)*(cum[l]+cum[n]-cum[r-1])+rec(l-1,r,t));
        if(r<=n)ret=min(ret,tim(sec[r].x-sec[l+1].x,v)*(cum[l]+cum[n]-cum[r-1])+rec(l,r+1,!t));
    }
    return ret;
}
int main() {
    while(scanf("%d%d%d",&n,&v,&x)!=-1){
        if(!n)break;
        memset(dp,-1,sizeof dp);
        memset(cum,0,sizeof cum);
        sec.clear();
        double an=0;
        sec.push_back({-1,0,0});
        for(int i=1;i<=n;i++){
            int x,c,d;
            scanf("%d%d%d",&x,&c,&d);
            sec.push_back(dat(x,c,d));
            an+=c;
        }
        sort(sec.begin(),sec.end(),comp);
        int l=0,r=n+1;
        for(int i=1;i<=n;i++){
            if(sec[i].x<x)l=i;
            else{
                r=i;
                break;
            }
        }
        for(int i=1;i<=n;i++)cum[i]=cum[i-1]+sec[i].d;
        double r1=(l>0)?rec(l-1,r,0):2*oo,r2=(r<=n)?rec(l,r+1,1):2*oo;
        if(l)r1+=tim(x-sec[l].x,v)*cum[n];
        if(r<=n)r2+=tim(sec[r].x-x,v)*cum[n];
        an+=min(r1,r2);
        an+=1e-8;
        an=floor(an);
        printf("%d\n",(int)an);
    }
    return 0;
}




