class Solution {
public:
    int dp[1001][2001];
    int rec(int index,int k,vector<vector<int>>& piles){
        int n=piles.size();
        if(k<0){
            return INT_MIN;
        }
        if(k==0){
            return 0;
        }
        if(index >= n){
            if(k==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int op1 = rec(index+1,k,piles);
        int op2 = INT_MIN;
        int tot=0;
        for(int i=0;i<piles[index].size();i++){
            tot += piles[index][i];
            op2 = max(op2,tot+rec(index+1,k-(i+1),piles));
        }
        return dp[index][k]=max(op1,op2);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,k,piles);
        return ans;
    }
};