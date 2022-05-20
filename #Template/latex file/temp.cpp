/* BISMILLAHIR RAHMANIR RAHIM  */
#include<bits/stdc++.h>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define READ             freopen("in.txt", "r", stdin);
#define WRITE            freopen("out.txt", "w", stdout);
#define ll               int long long
#define ull              unsigned long long
#define ld               long double
#define lld              long long double
#define pi               acos(-1)
#define pb               push_back
#define pff              push_front
#define pbk              pop_back
#define pfk              pop_front
#define mp               make_pair
#define gcd(a,b)         __gcd(a,b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define dist(ax,ay,bx,by)  sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,a,b,x)    for(__typeof(b) i=a;i<=b;i+=x)
#define rloop(i,b,a,x)   for(__typeof(b) i=b;i>=a;i-=x)
#define lead_zero(x)     __builtin_clzll(x)
#define trail_zero(x)    __builtin_ctz(x)
#define total_1s(x)      __builtin_popcount(x)
#define first_1(x)       __builtin_ffs(x)
#define log2_(x)         __builtin_clz(1) - __builtin_clz(x)
#define Q               int test; scanf("%d", &test);for (int z = 1; z<= test; z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0);
#define pf               printf
#define ff               first
#define ss               second
#define all(v)           v.begin(),v.end()
#define SZ(a)            (int)a.size()
/* #### check this paramter before submit ##### */
#define mxN                  100005
#define inf              10000000000000000
#define mod              1000000007
#define mini            -1000000003

/*----------------------Graph Moves----------------*/
///const int fx[]={+1,-1,+0,+0};
///const int fy[]={+0,+0,+1,-1};
///const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
///const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
///const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
///const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
 //int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
/*-----------------------Bitmask------------------*/
///int Set(int N,int pos){return N=N | (1<<pos);}
///int reset(int N,int pos){return N= N & ~(1<<pos);}
///bool check(int N,int pos){return (bool)(N & (1<<pos));}
