/*
first find number of ditinct subsequences assuming n=0:
it's a simple dp problem,by starting from first occurence of each char 
and build subsequences such that no duplication occurs..
based on the solution of this dp we can solve it for n>0,
we need to increase the calls to new states, which happens when we append
characters different from each other,and repeate the same added string until 
filling all n characters.
let's build the string that we are going to add to fill n charchters.
first append to this string characters that are not appeared in first m charcters
then for other characters let's get for each one last index appeared in(1....m)
and append them one by one in increasing order of thier last index..
then append this string to original string until we fill n characters..
Complexity O(N*F),F=size of alphabet. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e6+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,k,m,ap[26],dp[N];
string s;
int nxt[26][N];
int rec(int idx){
    int &ret=dp[idx];
    if(ret!=-1)return ret;
    ret=1;
    for(int j=0;j<k;j++){
        if(nxt[j][idx]!=-1){
            ret+=rec(nxt[j][idx]);
            ret%=mod;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    cin>>s;
    m=s.size();
    for(int i=0;i<m;i++)if(ap[s[i]-'a']==0)ap[s[i]-'a']=i+1;
    string ad;
    vector<pp > ord;
    for(int i=0,r=m+1;i<k;i++)if(ap[i]==0)ad+=i+'a',ap[i]=r++;
    int lst[26],an=1;
    for(int i=0;i<k;i++)lst[i]=-1;
    for(int i=0;i<m;i++)lst[s[i]-'a']=i;
    for(int i=0;i<k;i++)if(lst[i]!=-1)ord.push_back({lst[i],i});
    sort(ord.begin(),ord.end());
    for(auto v:ord)ad+=v.second+'a';
    while(int(ad.size()+s.size())<n+m)s+=ad;
    int y=0;
    while((int)s.size()<n+m)s+=ad[y++];
    for(int i=0;i<k;i++)lst[i]=-1;
    for(int i=(int)s.size()-1;i>-1;i--){
        for(int j=0;j<k;j++){
            if(lst[j]==-1)nxt[j][i]=-1;
            else nxt[j][i]=lst[j];
        }
        lst[s[i]-'a']=i;
    }
    memset(dp,-1,sizeof dp);
    for(int i=0;i<k;i++){
        if(!ap[i]||ap[i]>m+n)continue;
        an+=rec(ap[i]-1);
        an%=mod;
    }
    cout<<an;
    return 0;
}