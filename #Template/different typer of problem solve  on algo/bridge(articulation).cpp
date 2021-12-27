//lightoj Critical Links
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>    //for memset
using namespace std;

#define ll                      int long long
#define ull                      unsigned long long
#define ld                       long double
#define pi                       acos(-1)
#define pb                       push_back
#define pbk                      pop_back
#define mp                       make_pair
#define ff                       first
#define ss                       second
#define pii                      pair<int,int>
#define gcd(a,b)                 __gcd(a,b)
#define lcm(a,b)                (a/gcd(a,b))*b
#define READ                     freopen("in.txt","r",stdin);
#define WRITE                    freopen("outer.txt","w",stdout);
#define sort(t)                  sort(t.begin(),t.end())
#define mem(a,b)                 memset(a,b,sizeof a)
#define TEST_CASE(t)             for(int z=1;z<=t;z++)
#define PRINT_CASE               printf("Case %d: ",z)
#define LINE_PRINT_CASE          printf("Case %d:\n",z)
#define sf                       scanf
#define pf                       printf
#define cs(p)                    printf("Case %d: ", ++(p))
#define dist(ax,ay,bx,by)        sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define mx                       100003
#define inf                      10000000000000000+7
#define M                        1000000002
#define MINI                     -1000000003
#define ok                    cout<<"ok"<<endl;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

vector<int>adj[mx];
int visited[mx],node[mx],low[mx],parent[mx],disTime[mx],discover_time,root;
set<pii>s;

void bridge(int u,int root=-1)
{
    visited[u]=1;
    int cnt=0;
    disTime[u]=low[u]=++discover_time;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(parent[u]==v)
            continue;
        if(visited[v])
            low[u]=min(low[u],disTime[v]); //back edge thakle
        else
        {
            parent[v]=u;
            bridge(v,u);
            low[u]=min(low[u],low[v]);
            if(disTime[u]<low[v])
            {
                s.insert({min(u,v),max(u,v)});
                //cout<<u<<" "<<v<<endl;
                //node[u]=1;
            }

        }


    }


}

int main()
{
    int test;
    cin>>test;
    TEST_CASE(test)
    {
        memset(visited,0,sizeof visited);
        memset(node,0,sizeof node);
        memset(low,0,sizeof low);
        memset(disTime,0,sizeof disTime);

        for(int i=0; i<mx; i++)
        {
            adj[i].clear();
        }
        s.clear();
        int node;
        sf("%d",&node);
        for(int i=1; i<=node; i++)
        {
            int u,n;
            char c1,c2;
            cin>>u;
            getchar();
            cin>>c1>>n>>c2;
            for(int nn=1; nn<=n; nn++)
            {
                int v;
                cin>>v;
                adj[u].pb(v);
            }
        }
        for(int i=0; i<node; i++)
        {

            if(!visited[i])
            {
                bridge(i);
            }
        }


        LINE_PRINT_CASE;
        cout<<s.size()<<" critical links"<<endl;
        for(auto it=s.begin();it!=s.end();it++)
        {
                cout<<it->ff<<" - "<<it->ss<<endl;
        }




    }
}


