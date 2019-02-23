/*
straightforward implementation of union of rects;
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=3e5+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int n;
struct event{
    int f,type,idx;
    event(int f,int type,int idx):f(f),type(type),idx(idx){}
    bool operator<(const event &ev)const{
        return f<ev.f;
    }
};
vector<event > evx,evy;
bool in[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int p1,q1,p2,q2;
        cin>>p1>>q1>>p2>>q2;
        evx.push_back(event(p1,0,i));
        evx.push_back(event(p2,1,i));
        evy.push_back(event(q1,0,i));
        evy.push_back(event(q2,1,i));
    }
    sort(evx.begin(),evx.end());
    sort(evy.begin(),evy.end());
    ll area=0;
    for(int i=0;i<(int)evx.size();i++){
        if(i==0){
            in[evx[i].idx]=1;
            continue;
        }
        int df=evx[i].f-evx[i-1].f,cnt=0,lo;
        for(int j=0;j<(int)evy.size()&&df;j++){
            if(!in[evy[j].idx])continue;
            if(evy[j].type==0){
                if(cnt==0)lo=evy[j].f;
                cnt++;
            }else{
                cnt--;
                if(cnt==0)area+=(evy[j].f-lo)*1LL*df;
            }
        }
        in[evx[i].idx]=evx[i].type==0;
    }
    cout<<area;
    return 0;
}

