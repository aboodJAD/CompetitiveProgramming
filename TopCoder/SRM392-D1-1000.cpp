/*
count of digits in answer will be n (n=count of digits in input string) 9999.. is larger than any number.
fix number of repetitions for each digit in the resulting number let it be C, then there is n/C different types of digits in resulting number.

from this the number of different candidates(ignoring ordering of digits) are not high.

we can generate those numbers and for each of them we need to obtain a number from a set of n digits s.t  it's greater than input string and minimum possible, i did it greedily using multisets but i think there is a nicer implementation for it.

*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int > pp;
typedef long long ll;

int const N=2e5+10,oo=1e9,M=64;
ll const OO=1e18;
int mod=oo+7;
double const eps=1e-4,PI=acos(-1);

class EquiDigitNumbers{
public:
int n;
string in;
vector<string > all; 
string ke;
void generate(int d,int r,int count){
    if(count==0){
        all.push_back(ke);
        return ;
    }
    if(10-d==count){
        for(int i=0;i<r;i++)ke+='0'+d;
        generate(d+1,r,count-1);
        while(r--)ke.pop_back();
        return ;
    }
    generate(d+1,r,count);
    for(int i=0;i<r;i++)ke+='0'+d;
    generate(d+1,r,count-1);
    while(r--)ke.pop_back();
}
ll findNext(string num){
    n=num.size();
    int fr[10]={};
    for(int i=0;i<n;i++)fr[num[i]-'0']++;
    bool y=1;
    for(int i=0;i<10;i++)if(fr[i]&&fr[i]!=fr[num[0]-'0']){
        y=0;
        break;
    }
    if(y){
        stringstream ss(num);
        ll a;
        ss>>a;
        return a;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0&&n/i<=10){
            generate(i==n,i,n/i);
        }
    }
    set<ll > can;
    for(auto v:all){
        multiset<int > con;
        for(auto c:v)con.insert(c-'0');
        string un;
        for(int i=0;i<n;i++){
            int d=num[i]-'0';
            if(con.upper_bound(d)!=con.end()){
                int p=*con.upper_bound(d);
                string ad=un;
                ad+=p+'0';
                con.erase(con.find(p));
                for(auto q:con)ad+=q+'0';
                stringstream ss(ad);
                ll af;
                ss>>af;
                can.insert(af);
                con.insert(p);
            }
            if(con.find(d)==con.end())break;
            else{
                un+=d+'0';
                con.erase(con.find(d));
            }
        }
    }
    return *can.begin();
}
};