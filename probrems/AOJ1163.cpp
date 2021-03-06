#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define get0(x)     (get<0>(x))
#define get1(x)     (get<1>(x))
#define get2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807LL
#define LLMIN       -9223372036854775808LL
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;
using namespace std;

int gcd(int x,int y){
	if(y==0)	return x;
	else	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}

#define MAX_V 1002

struct Edge{ int to,cap,rev; };
int used[MAX_V];
vector<Edge> G[MAX_V];

void addEdge(int from,int to,int cap){
    G[from].push_back((Edge){to,cap,(int)G[to].size()});
    G[to].push_back((Edge){from,0,(int)G[from].size()-1});
}
int DFS(int v,int t,int f){
    if(v==t)
        return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
        Edge &e=G[v][i];
        if(!used[e.to] && 0<e.cap){
            int d=DFS(e.to,t,min(f,e.cap));
            if(0<d){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int maxFlow(int s,int t){
    int flow=0;
    while(1){
        for(int i=0;i<MAX_V;i++)
            used[i]=false;
        int f=DFS(s,t,INT_MAX);
        if(f==0)
            break;
        flow+=f;
    }
    return flow;
}


int n,m;

void solve(){
    REP(i,MAX_V){used[i]=0;G[i].clear();}
    vector<int> b,r;
    REP(i,m){int bb;cin>>bb;b.pb(bb);}
    REP(i,n){int rr;cin>>rr;r.pb(rr);}
    REP(i,m)REP(j,n){
        if(gcd(b[i],r[j])>1){
            addEdge(i,m+j,1);
            // printf("b[i]=%d r[j]=%d\n",b[i],r[j]);
        }
    }
    REP(i,m)addEdge(n+m,i,1);
    REP(i,n)addEdge(m+i,n+m+1,1);
    int ans=maxFlow(n+m,n+m+1);
    cout<<ans<<endl;
}

int main(void){
    while(1){
        cin>>m>>n;
        if(n==0&&m==0)
            break;
        solve();
    }
     return 0;
}
