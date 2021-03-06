// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins , coins + M);
	    vector<vector<int>> dp(M + 1, vector<int>(V + 1 , INT_MAX - 1));
	    for(int i = 0 ; i < M + 1 ; i++){
	        dp[i][0] = 0;
	    }
	    for(int i = 1 ; i < M + 1 ; i++){
	        for(int j = 1 ; j < V + 1 ; j++){
	            if(coins[i - 1] <= j){
	                dp[i][j] = min(dp[i - 1][j] ,1 + dp[i][j - coins[i - 1]]);
	            }else{
	                dp[i][j] = dp[i - 1][j];
	            }
	        }
	    }
	    if(dp[M][V] == INT_MAX - 1){
	        return -1;
	    }
	    return dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends