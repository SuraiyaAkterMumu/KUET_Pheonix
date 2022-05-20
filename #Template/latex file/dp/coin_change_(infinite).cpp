int coin[111],n;

int call(int amount)
{

    int dp[n][amount+1];
    for(int j=1; j<=amount; j++)
        {
                if(j%coin[0]==0) dp[0][j]=1;
                else dp[0][j]=0;
        }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=amount; j++)
        {

            if(j==0) dp[i][j]=1;
            else if(coin[i]>j)
            {
                dp[i][j]=(dp[i-1][j])%mod;
            }
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-coin[i]])%mod;
            }
            //cout<<dp[i][j];
        }
    }
}