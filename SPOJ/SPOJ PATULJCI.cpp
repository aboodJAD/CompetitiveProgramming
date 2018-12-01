/*
suppose there is one color c with frequency equal to k/2+1,
then if we get a random element from the range then the probability of not getting c
is (k-k/2-1)/k = (k/2)/k = 1/2 
then if we ask p times for a random element the probability of not getting c is 1/2^p
so if we choose p such that we get a sufficient probability to get c then we are done.
i choose p to be 20 with probability to get c = 1-1/2^20=99.99%
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,m,c,cc[N];
vector<int > at[N];
int main(){
    srand(time(NULL));
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&cc[i]);
        at[cc[i]].push_back(i);
    }
    scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int k=r-l+1;
        int who=-1;
        for(int i=0;i<20;i++){
            int idx=rand()%k;
            idx+=l;
            int rgt=upper_bound(at[cc[idx]].begin(),at[cc[idx]].end(),r)-at[cc[idx]].begin();
            rgt--;
            int lft=lower_bound(at[cc[idx]].begin(),at[cc[idx]].end(),l)-at[cc[idx]].begin();
            if(rgt-lft+1>k/2){
                who=cc[idx];
                break;
            }
        }
        if(who!=-1)printf("yes %d\n",who);
        else printf("no\n");
    }
    return 0;
}

