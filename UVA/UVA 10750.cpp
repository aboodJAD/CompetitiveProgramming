//simple idea, just find midpoint between closest pair

#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=3e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;


int t,n;
int dist(pp a,pp b){
    return (a.first-b.first)*(a.first-b.first)+
    (a.second-b.second)*(a.second-b.second);
}
pair<double ,double > getMid(pp a,pp b){
    return {(a.first+b.first)/2.0,(a.second+b.second)/2.0};
}
void solve(){
    scanf("%d",&n);
    vector<pp > po(n);
    for(int i=0;i<n;i++)scanf("%d%d",&po[i].first,&po[i].second);
    sort(po.begin(),po.end());
    set<pp > win;
    win.insert({po[0].second,po[0].first});
    int mx=oo;
    pair<double,double > an;
    for(int i=1;i<n;i++){
        int x=po[i].first,y=po[i].second;
        vector<pp > del;
        for(auto c:win)if(x-c.second>sqrt(mx*1.0))del.push_back(c);
        for(auto c:del)win.erase(c);
        auto lf=win.lower_bound({y-sqrt(mx*1.0),-oo});
        auto rg=win.upper_bound({y+sqrt(mx*1.0),oo});
        while(lf!=rg){
            int d=dist(make_pair(lf->second,lf->first),po[i]);
            if(d<mx){
                an=getMid(make_pair(lf->second,lf->first),po[i]);
                mx=d;
            }
            lf++;
        }
        win.insert({y,x});
    }
    printf("%.3f %.3f\n",an.first,an.second);
}
int main(){
/*    ios::sync_with_stdio(0);
    cin.tie(0);*/
    scanf("%d",&t);
    while(t--){
        solve();
        if(t)puts("");
    }
    return 0;
}
