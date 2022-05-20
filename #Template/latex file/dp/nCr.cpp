ll dp[mx][mx];
ll nCr(ll n,ll r)
{
	if(r==1)
	{
		return n;	
	}
	if(n==r)
	{
		return 1;
	}
	if(dp[n][r]!=-1)
	{
		return dp[n][m];
	}
	else
	{
		dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
		return dp[n][r];
	}
 
}

