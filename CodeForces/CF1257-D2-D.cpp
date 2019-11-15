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
 
int aa[N];
vector<int > mxs;
pp bb[N];
vector<int > at[N],fr;
void solve(){
	int n,m;
	cin>>n;
	mxs.clear();
	mxs.resize(n+2);
	for(int i=0;i<n;i++)cin>>aa[i];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>bb[i].first>>bb[i].second;
		mxs[bb[i].second]=max(mxs[bb[i].second],bb[i].first);
	}
	for(int i=n;i>-1;i--)mxs[i]=max(mxs[i],mxs[i+1]);
	int an=0;
	for(int i=0;i<n;i++){
		int j=i,mxp=0;
		while(j<n){
			int h=max(mxp,aa[j]);
			if(h<=mxs[j-i+1]){
				mxp=max(mxp,aa[j]);
				j++;
			}else break;
		}
		j--;
		if(j<i){
			cout<<"-1\n";
			return ;
		}
		an++;
		i=j;
	}
	cout<<an<<'\n';
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	
	return 0;
}
