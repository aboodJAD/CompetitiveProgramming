/*
we can observe that number of components can change only on height of buildings
so if we have buildings with heights 2 5 6 8, then changes in number of components will occur 
at days equal to heights.
use line sweep in increasing order of heights and keep number of components before each step.
if current height is h with index i then if height of building(i-1) and height of building(i+1) greater than h
then new compnent will arise. for consective buildings with same height treat them as one building;
save pair of height(number of days) and cnt of components then lower_boundfor each query.
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
 
int const N=1e6+2,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n,d,y,aa[N];
pp bb[N];
vector<pp > rng;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        rng.clear();
        cin>>n>>d;
        for(int i=0;i<n;i++)cin>>aa[i],bb[i]={aa[i],i};
        sort(bb,bb+n);
        rng.push_back({0,1});
        int cnt=1;
        for(int i=0;i<n;i++){
            vector<int > at;
            int j=i;
            while(j<n&&bb[j].first==bb[i].first){
                at.push_back(bb[j].second);
                j++;
            }
            for(int k=0;k<(int)at.size();k++){
                int y=k+1;
                while(y<(int)at.size()&&at[y]==at[y-1]+1)y++;
                y--;
                if(at[k]&&aa[at[k]-1]>aa[at[k]]&&at[y]+1<n&&aa[at[y]+1]>aa[at[k]])cnt++;
                else if((at[k]==0||aa[at[k]-1]<aa[at[k]])&&(at[y]+1==n||aa[at[y]+1]<aa[at[k]]))cnt--;
                k=y;
            }
            rng.push_back({bb[i].first,cnt});
            i=j-1;
        }
///        for(auto v:rng)cout<<v.first<<' '<<v.second<<endl;
        while(d--){
            cin>>y;
            auto v=upper_bound(rng.begin(),rng.end(),make_pair(y,oo));
            v--;
            cout<<v->second;
            if(d)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
