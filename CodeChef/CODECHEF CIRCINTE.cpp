/*
easy binary search problem with some greedy..
bs answer..then the check method goes like this..imagine the sequence is not cyclic then it's allway better 
to choose the first element from the first interval then trying to keep the chosen elements at least as far as 
the searched answer..
if we do this first then find the dist between the last elemnt from last interval to the first element from first interval
if it's less then ans then we need shift the first element by the difference if it's possible then repeate the greedy solution 
for the acyclic sequence..
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 5e5 + 10,M=1e6+1, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

ll m;
int n;
pair<ll,ll > aa[N];
bool can(ll r){
    ll at=aa[0].first;
    int i=1;
    while(i<n){
        ll nxt=at+r;
        if(nxt>aa[i].second)return 0;
        if(nxt<aa[i].first)at=aa[i].first;
        else at=nxt;
        i++;
    }
    if(aa[0].first+m-at>=r)return 1;
    ll need=r-(aa[0].first+m-at);
    at=need+aa[0].first;
    ll sc=at;
    if(at>aa[0].second)return 0;
    i=1;
    while(i<n){
        ll nxt=at+r;
        if(nxt>aa[i].second)return 0;
        if(nxt<aa[i].first)at=aa[i].first;
        else at=nxt;
        i++;
    }
    if(sc+m-at>=r)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<n;i++)cin>>aa[i].first>>aa[i].second;
    sort(aa,aa+n);
    ll l=1,r=m,mid,res=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(can(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res;
    return 0;
}

