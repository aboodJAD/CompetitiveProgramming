/*
build the solution gradully..start from the first element find the best choices for a sequence ending at i
by choosing the best answer for previous positions..
it can be modeled as dp problem..
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
double PI=acos(-1);
int const N = 1e5 + 10,M=1e6+1, oo = 1e9;
const int mod = oo+7;
const ll  OO = 2e18;

int n,q,cc[N],vv[N];
set<pair<ll,int> > st;
ll mx[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>vv[i];
    for(int i=0;i<n;i++)cin>>cc[i];
    while(q--){
//        st.clear();
        fill(mx,mx+n+1,-OO);
        ll an=0,who1=-1,who2=-1;
        int a,b;
        cin>>a>>b;
        for(int i=0;i<n;i++){
            ll r=mx[cc[i]]+(a*1LL*vv[i]);
            r=max(r,b*1LL*vv[i]);
            if(who1!=-1&&who2==-1){
                if(who1!=cc[i])r=max(r,mx[who1]+b*1LL*vv[i]);
            }else if(who1!=-1&&who2!=-1){
                if(who1!=cc[i])r=max(r,mx[who1]+b*1LL*vv[i]);
                else r=max(r,mx[who2]+b*1LL*vv[i]);
            }
            mx[cc[i]]=max(mx[cc[i]],r);
            an=max(an,r);
            if(mx[cc[i]]>mx[who1]){
                if(who1==cc[i])continue;
                who2=who1;
                who1=cc[i];
            }else if(mx[cc[i]]>mx[who2]&&who1!=cc[i])who2=cc[i];
/*            if(st.find({mx[cc[i]],cc[i]})!=st.end())st.erase({mx[cc[i]],cc[i]});
            if(!st.empty())r=max(r,(--st.end())->first+b*1LL*vv[i]);
            r=max(r,b*1LL*vv[i]);
            mx[cc[i]]=max(mx[cc[i]],r);
            st.insert({mx[cc[i]],cc[i]});*/
        }
        cout<<an<<'\n';
    }
    return 0;
}