ll int weight[2005];
ll int cost[2005];

ll int dp(int w,int n)
{
    ll int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                k[i][j]=0;
            else if(j-weight[i]>=0)
             k[i][j]=max(cost[i]+k[i-1][j-weight[i]],k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
        }
    }
    return k[n][w];
}