/*
while building the trie; keep in the struct node two variables
one to tell the most right index that branches to 0 and 1
when insert a number to the trie, update these two varibales
for current bit set value of branch as current index of number
and save for current index the 0 and 1 branch for most right index

to answer a query: query using r, change r to maximize the result 
and keep it larger than or equal to l
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=1e6+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

struct node{
    int nxt[2],to[2];
    node(){nxt[0]=nxt[1]=to[0]=to[1]=-1;}
};
int n,q,lft[N][16][2],ke[N][16][2];
vector<node > trie;
void insert(int a,int d){
    int cur=0;
    for(int i=15;i>-1;i--){
        int b=(a>>i)&1;
        if(trie[cur].nxt[b]==-1){
            trie[cur].nxt[b]=trie.size();
            trie.push_back(node());
        }
        trie[cur].to[b]=d;
        lft[d][i][b]=d;
        lft[d][i][!b]=trie[cur].to[!b];
        cur=trie[cur].nxt[b];
    }
}
int query(int a,int l,int r){
    int cur=0,an=0;
    for(int i=15;i>-1;i--){
        int b=(a>>i)&1;
        if(lft[r][i][!b]>=l){
            cur=trie[cur].nxt[!b];
            r=lft[r][i][!b];
            an|=1<<i;
        }else cur=trie[cur].nxt[b];
    }
    return an;
}
int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
      trie.clear();
      trie.push_back(node());
      cin>>n>>q;
      for(int i=1;i<=n;i++){
          int x;
          cin>>x;
          insert(x,i);
      }
      while(q--){
          int a,l,r;
          cin>>a>>l>>r;
          cout<<query(a,l,r)<<'\n';
      }
  }
  return 0;
}

