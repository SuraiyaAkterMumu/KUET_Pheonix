struct info
{
    ll prop,sum;
} tree[mx*4];
int a[mx];
void init(int node,int  b, int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        tree[node].prop=0;
        return;
    }
    int mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
    tree[node].prop=tree[node*2].prop+tree[node*2+1].prop;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
         tree[node].sum=((e-b+1)*x)-tree[node].sum;
        tree[node].prop+=x;
        return;
    }
    int mid=(b+e)/2;
    update(node*2,b,mid,i,j,1);
    update(node*2+1,mid+1,e,i,j,1);

    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum+
                                       (e-b+1)*tree[node].prop;

}
int query(int node,int b,int e,int i,int j,int carry=0)
{

    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        {
                //cout<<"node"<<node<<endl;
                return  tree[node].sum+carry*(e-b+1);
        }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)>>1;
     int p1=query(left,b,mid,i,j,tree[node].prop+carry);
     int p2=query(right,mid+1,e,i,j,tree[node].prop+carry);
     return p1+p2;
