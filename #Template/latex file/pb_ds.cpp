//https://cses.fi/problemset/task/2169
//Nested Ranges Count

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using o_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n;
    cin>>n;
    o_set<pair<int, int>>b,c;
    vector<array<int, 3>>a(n);
    vector<int>aa(n),bb(n);

    for(int i=0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    // sorting using lambda//
    sort(a.begin(), a.end(),[&](const array<int, 3> x, const array<int, 3> y){
        if(x[0]==y[0]) return x[1]>y[1];
        else return x[0]<y[0];
    });
    for(int i=0,j=n-1; i<n; i++,j--){
        aa[a[j][2]] = (c.order_of_key({a[j][1]+1, -1})) ;
        c.insert({a[j][1],i});
    }
    for(int i=0; i<n; i++){
        bb[a[i][2]] = (i-b.order_of_key({a[i][1], -1})) ;
        b.insert({a[i][1],i});
    }
    for(int i=0; i<n; i++) cout<<aa[i]<<" ";cout<<endl;
    for(int i=0; i<n; i++) cout<<bb[i]<<" ";cout<<endl;

}

