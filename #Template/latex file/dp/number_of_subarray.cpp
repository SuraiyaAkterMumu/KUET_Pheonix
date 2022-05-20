// Function to find number of subarrays
// with sum exactly equal to k.
ll findSubarraySum(vector<ll>arr, int n, ll sum)
{
	unordered_map<ll, ll> prevSum;

	ll res = 0;
	ll currsum = 0;

	for (int i = 0; i < n; i++) {
		currsum += arr[i];
		if (currsum == sum)
			res++;
		if (prevSum.find(currsum - sum) !=prevSum.end())
			res += (prevSum[currsum - sum]);
		prevSum[currsum]++;
	}
	return res;
}
