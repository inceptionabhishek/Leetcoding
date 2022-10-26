class Solution {
public:
    int rec(int n,int m,string s1,string s2,vector <vector<int>> dp){
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n]==s2[m]){
            return dp[n][m]=1+rec(n-1,m-1,s1,s2,dp);
        }
        return dp[n][m]=max(rec(n-1,m,s1,s2,dp),rec(n,m-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.length();
        int m=text2.length();
        vector <vector <int>> dp(n+1,vector <int> (m+1,0));
        
        //return rec(n-1,m-1,text1,text2,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};