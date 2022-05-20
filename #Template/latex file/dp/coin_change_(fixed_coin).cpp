int coin_change_fiexdLength(int amount,int i)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[amount][i]!=-1)
        return dp[amount][i];
    ll rep1=0,rep2=0;
    for(int ii=1; ii<=n_coin[i]; ii++)
    {
        if((amount - coin[i]*ii>=0))
            rep1+=coin_change_fiexdLength(amount-coin[i]*ii,i+1);
    }
    rep2+=coin_change_fiexdLength(amount,i+1);
    return dp[amount][i]=(rep1%mod+rep2%mod)%mod;
}