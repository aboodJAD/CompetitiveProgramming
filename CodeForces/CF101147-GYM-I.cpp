/*
let's denote the device circle region  as C0 and other circles Ci; 
consider moving C0 in increasing value of x-axis.
if another circle Ci becomes inside C0 then add it to active set(set of circles currently inside C0)
and when Ci goes out of C0 remove it.
each time maximize sum of radiuses of circles in active set.

when to add and when to remove?
    when Ci enters C0 it will be tangent to C0, find center of C0 at this point
    which will be (x,0), so we need just to know x coordinate of center of C0 at this moment
how to do this?
    let R radius of C0,r radius of Ci, (x1,y1) center of Ci
    at this moment R=r+dist((x,0),(x1,y1))
    then x=x(+-)sqrt((x-x1)^2-y^2);
    there are two solution one when Ci enters C0 and another when Ci leaves C0
    so they form two events, add them to a vector to apply line sweep on it.
    the sqrt term should not be negative and r should not be larger than R, otherwise the circle will not be inside C0 at any moment
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
 
int const N=1e6+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

struct event{
    double x;
    int r,type;
    event(double x,int r,int type):x(x),r(r),type(type){}
};
bool cmp(event a,event b){
    if(a.x!=b.x)return a.x<b.x;
    return a.type<b.type;
}
int t,n,R;
vector<event > aa;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        aa.clear();
        cin>>n>>R;
        for(int i=0;i<n;i++){
            int x,y,r;
            cin>>x>>y>>r;
            if(r>R)continue;
            ll d=(R-r)*1LL*(R-r)-y*1LL*y;
            if(d>=0){
                aa.push_back(event(x-sqrt(d*1.0),r,0));
                aa.push_back(event(x+sqrt(d*1.0),r,1));
            }
        }
        sort(aa.begin(),aa.end(),cmp);
        ll sum=0,mx=0;
        for(auto e:aa){
            if(e.type==0)sum+=e.r;
            else sum-=e.r;
            mx=max(mx,sum);
        }
        cout<<mx<<'\n';
    }
    return 0;
}
