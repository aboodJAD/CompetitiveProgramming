/*
fix ai then find count of numbers satisfying the equality
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=1e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;
 
int aa[N],cnt[N],mx[N];
 
int po(int p,int k){
	int ret=1;
	while(k){
		if(ret*1LL*p>N)return -1;
		ret*=p;
		k--;
	}
	return ret;
}
void solve(){
	for(int i=2;i<N;i++){
		if(mx[i])continue;
		for(int j=i;j<N;j+=i)mx[j]=i;
	}
	int n,k;
	ll an=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>aa[i];
	sort(aa,aa+n);
	for(int i=0;i<n;i++){
		int h=aa[i],me=1;
		vector<pp > f;
		while(h>1){
			int p=mx[h],cnt=0;
			while(h%p==0){
				cnt++;
				h/=p;
			}
			f.push_back({p,cnt%k});
			me *= po(p,cnt%k);
		}
		int need = 1;
		for(auto v:f){
			int cm = k-v.second;
			cm%=k;
			int z = po(v.first,cm);
			if(z==-1){
				need=-1;
				break;
			}
			if(need*1LL*z>N){
				need=-1;
				break;
			}
			need*=z;
		}
		if(need!=-1)an+=cnt[need];
		cnt[me]++;
	}
	cout<<an;
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t=1;
	while(t--)solve();
	
	return 0;
}
