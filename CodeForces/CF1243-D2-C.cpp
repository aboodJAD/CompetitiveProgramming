#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

ll n;
void solve(){
	cin>>n;
	ll k=n;
	vector<ll > pr;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			pr.push_back(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)pr.push_back(n);
	if(sz(pr)==1){
		cout<<pr[0]<<'\n';
	}else {
		cout<<1<<'\n';
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	
	return 0;
}