/*
reducing the problem using some math:
SUM(pi*d-a[i])<=k
where pi is the first number such that pi*d>a[i].
d*SUM(pi)<=k+SUM(a[i])
k+SUM(a[i])<=2e11

looping till sqrt(k+SUM(a[i])) then trying two values for d(i and (k+SUM(a[i]))/i) and check if it's valid d.

Complexity O(n*sqrt(k))
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=1e5+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

ll k,kk,aa[101];
int n;
bool check(ll d){
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=((aa[i]+d-1)/d)*d-aa[i];
        if(sum>kk)return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    kk=k;
    for(int i=0;i<n;i++){
        cin>>aa[i];
        k+=aa[i];
    }
    ll mx=0;
    for(ll i=1;i*i<=k;i++){
        if(check(i))mx=max(i,mx);
        if(check(k/i))mx=max(mx,k/i);
    }
    cout<<mx;
    return 0;
}