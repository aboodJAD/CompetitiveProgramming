/*
in every greedy solution ,we will face a problem that after choosing a number
to bind to a fixed number, we are not sure that the chosen number will not affect the choice
for next fixed numbers...
so first sort the numbers in both arrays(array of first a number , and second number b) , start from larger to smaller,
try to bind current number from array a to one from array b, the best choice is to get a number from array b sum to current number
maximum possible,this can happened either by adding a number from array b and result is less than m or adding it 
to maximum in b(current number in a is the largest)..
if we choose to add it to maximum in b, then check if there is a better choice for maximum in b from array a, 
and thus we are always sure that current choice will not affect upcoming choices..
i used multiset to solve this..
coplexity O(NlogN)
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=5e5+10,oo=1e9,M=5e5;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

int n,m;
multiset<int > a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.insert(c);
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b.insert(c);
    }
    vector<int > an;
    while(!a.empty()){
        int cur=*(--a.end());
        auto to=b.upper_bound(m-1-cur);
        int oth=*(--b.end());
        auto toto=a.upper_bound(m-1-oth);
        if(to==b.begin()){
            if(toto==a.begin()){
                an.push_back((cur+oth)%m);
                a.erase(a.find(cur));
                b.erase(b.find(oth));
            }else{
                toto--;
                if(*toto+oth>(oth+cur)%m){
                    an.push_back(*toto+oth);
                    a.erase(toto);
                    b.erase(b.find(oth));
                }else{
                    an.push_back((cur+oth)%m);
                    a.erase(a.find(cur));
                    b.erase(b.find(oth));                    
                }
            }
        }else{
            to--;
            int can1=*to+cur;
            int can2=(oth+cur)%m;
            if(toto==a.begin()){
                if(can1>can2){
                    an.push_back(can1);
                    a.erase(a.find(cur));
                    b.erase(to);
                }else{
                    an.push_back(can2);
                    a.erase(a.find(cur));
                    b.erase(a.find(oth));                    
                }
            }else{
                toto--;
                int can3=oth+*toto;
                if(can1>=can2&&can1>=can3){
                    an.push_back(can1);
                    a.erase(a.find(cur));
                    b.erase(to);                    
                }else if(can2>=can1&&can2>=can3){
                    an.push_back(can2);
                    a.erase(a.find(cur));
                    b.erase(a.find(oth));                    
                }else{
                    an.push_back(can3);
                    a.erase(toto);
                    b.erase(b.find(oth));
                }
            }
        }
    }
    sort(an.begin(),an.end(),greater<int>());
    for(auto v:an)cout<<v<<' ';
    return 0;
}

