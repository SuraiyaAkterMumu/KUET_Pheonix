///safayet blog & cp algo
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
#define MAX                       10003
#define inf                      10000000000000000+7
#define M                        1000000002
#define MINI                     -1000000003
#define ok                    cout<<"ok"<<endl;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

//#define for(i,a,n)    for(int i=a;i<n;i++)
//it=myset.find(20);
//int a[8]= {0,0,-1,1,-1,1,-1,1};
//int b[8]= {-1,1,0,0,-1,1,1  ,-1};


#define mx 1002
int L[mx];
int P[mx][22];
int T[mx];
vector<int>g[mx];
void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q)
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

int main()
{
    int t;
    scanf("%d",&t);
    TEST_CASE(t)
    {
            for(int i=0;i<=mx;i++) g[i].clear();
        int n;
        sf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int subnode;
            sf("%d",&subnode);
            for(int j=0; j<subnode; j++)
            {
                int u;
                sf("%d",&u);
                g[i].pb(u-1);
                //ok
            }
        }

        dfs (0, 0,0);
        lca_init(n);
        LINE_PRINT_CASE;
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            int ans = lca_query(n,a-1,b-1);

            printf("%d\n",ans+1);
        }

    }

}
