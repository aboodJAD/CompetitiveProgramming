/*
just a modification of finding union of rectangles area
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include<cctype>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<time.h>
#include<iterator>
#include <deque>
#include <sstream>
#include<queue>
#include<stdlib.h>
#include<bitset> 
#include <utility>
#include<assert.h>
#include<functional>
#include<limits.h>


using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
int const N=6000+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8;//PI=acos(-1);
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
int solve(){
    ll pri=0;
    memset(in,0,sizeof in);
    for(int i=0;i<(int)evx.size();i++){
        if(i==0){
            in[evx[i].idx]=1;
            continue;
        }
        int df=evx[i].f-evx[i-1].f,cnt=0;
        for(int j=0;j<(int)evy.size()&&df;j++){
            if(!in[evy[j].idx])continue;
            if(evy[j].type==0)cnt++;
            else{
                cnt--;
                if(cnt==0)pri+=df*2;
            }
        }
        in[evx[i].idx]=evx[i].type==0;
    }
    return pri;
}
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
    int an=solve();
    swap(evx,evy);
    an+=solve();
    cout<<an<<'\n';
    return 0;
}

