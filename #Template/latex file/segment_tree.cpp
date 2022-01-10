// ------------------segment tree(normal)hakerearth------------ 
 long long int tree[mx*4];
 long long int tree_min[mx*4];
 long long int arr[mx];
 using namespace std;
void init( int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        tree_min[node]=arr[b];
        return;
    }
     int mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
    tree_min[node]=min(tree_min[node*2],tree_min[node*2+1]);
}

ll int query_sum( int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
     int mid=(b+e)/2;
    ll int p1=query_sum(node*2,b,mid,i,j);
    ll int p2=query_sum(node*2+1,mid+1,e,i,j);
    return p1+p2;
}

void update_sum( int node, int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        tree_min[node]=newvalue;
        return;
    }
    int mid=(b+e)/2;
    update_sum(node*2,b,mid,i,newvalue);
    update_sum(node*2+1,mid+1,e,i,newvalue);
    tree[node]=tree[node*2]+tree[node*2+1];
    tree_min[node]=min(tree_min[node*2],tree_min[node*2+1]);
}
