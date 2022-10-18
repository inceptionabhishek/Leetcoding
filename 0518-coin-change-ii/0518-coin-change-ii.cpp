class Solution {
public:
    int dp[5001][301];
    int rec(int amount,vector <int> &coins,int index){
        if(amount==0){
            return 1;
        }
        if(index>=coins.size()){
            return 0;
        }
        if(dp[amount][index]!=-1){
            return dp[amount][index];
        }
        if(coins[index]>amount){
            return dp[amount][index]=rec(amount,coins,index+1);
        }
        return dp[amount][index]=rec(amount-coins[index],coins,index)+rec(amount,coins,index+1);
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return rec(amount,coins,0);
        int n=coins.size();
        for(int i=1;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<=amount;i++){
            for(int j=1;j<=n;j++){
                if(coins[j-1]>i){
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
                int diff=i-coins[j-1];
                dp[i][j]=dp[diff][j]+dp[i][j+1];
            }
        }
        for(int i=0;i<=amount;i++){
            for(int j=1;j<=n;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[amount][n];
    }
};