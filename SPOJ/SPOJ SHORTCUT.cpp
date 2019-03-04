/*
sort points by x-coordinate then by y-coordinate.
for each point find the nearest valid point to left(has same y coordinate) or down(same x-coordinate)
and then minimize the distance
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=3e5+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int t,n;
string s;
struct event{
    int x,y,id;
    char fr,to;
    event(int xx,int yy,char frf,char tot,int i){
        x=xx,y=yy,fr=frf,to=tot,id=i;
    }
    bool operator<(event &e)const {
        if(e.x!=x)return x<e.x;
        return y<e.y;
    }
};
struct solution{
    int l,b,e;
    char d;
};
pp getNext(event v){
    if(v.to=='N')return {v.x,v.y+1};
    if(v.to=='S')return {v.x,v.y-1};
    if(v.to=='E')return {v.x+1,v.y};
    if(v.to=='W')return {v.x-1,v.y};
    return {v.x,v.y};
}
pp getPre(event v){
    if(v.fr=='N')return {v.x,v.y-1};
    if(v.fr=='S')return {v.x,v.y+1};
    if(v.fr=='E')return {v.x-1,v.y};
    if(v.fr=='W')return {v.x+1,v.y};
    return {v.x,v.y};
}
solution sweep(vector<event> tr){
    solution res;
    res.l=oo;
    map<int,pp > mp[2]; 
    for(auto v:tr){
        if(mp[0].find(v.x)!=mp[0].end()){
            if(getNext(v)!=make_pair(v.x,mp[0][v.x].first)&&getPre(v)!=make_pair(v.x,mp[0][v.x].first)){
                solution ch;
                ch.l=v.y-mp[0][v.x].first;
                ch.b=mp[0][v.x].second;
                ch.e=v.id;
                if(ch.b<ch.e)ch.d='N';
                else {
                    swap(ch.b,ch.e);
                    ch.d='S';
                }
                if(res.l>ch.l)res=ch;
                else if(res.l==ch.l){
                    if(res.b>ch.b){
                        res=ch;
                    }else if(res.b==ch.b){
                        if(res.e<ch.e)res=ch;
                    }
                }
            }
        }
        if(mp[1].find(v.y)!=mp[1].end()){
            if(getNext(v)!=make_pair(mp[1][v.y].first,v.y)&&getPre(v)!=make_pair(mp[1][v.y].first,v.y)){
                solution ch;
                ch.l=v.x-mp[1][v.y].first;
                ch.b=mp[1][v.y].second;
                ch.e=v.id;
                if(ch.b<ch.e)ch.d='E';
                else {
                    swap(ch.b,ch.e);
                    ch.d='W';
                }
                if(res.l>ch.l){
                    res=ch;
//                    cout<<v.x<<' '<<v.y<<' '<<mp[1][v.y].first<<' '<<v.fr<<endl;
                }
                else if(res.l==ch.l){
                    if(res.b>ch.b){
                        res=ch;
                    }else if(res.b==ch.b){
                        if(res.e<ch.e)res=ch;
                    }
                }
            }
        }
        mp[0][v.x]={v.y,v.id};
        mp[1][v.y]={v.x,v.id};
    }
    return res;
}
void solve(){
    vector<event> ev;
    int x=0,y=0;
    ev.push_back(event(x,y,'-',s[0],0));
    for(int i=0;i<n;i++){
        if(s[i]=='N')y++;
        else if(s[i]=='S')y--;
        else if(s[i]=='E')x++;
        else x--;
        ev.push_back(event(x,y,s[i],i==n-1?'-':s[i+1],i+1));
    }
    sort(ev.begin(),ev.end());
    solution res=sweep(ev);
    cout<<res.l<<' '<<res.b<<' '<<res.e<<' '<<res.d<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        solve();
    }
    return 0;
}

