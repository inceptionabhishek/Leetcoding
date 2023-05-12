#define ll long long int

class Solution {
public:
    ll dp[100001];
    ll rec(int index,vector<vector<int>>& questions){
        int n=questions.size();
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        ll t1=questions[index][0] + rec(index +questions[index][1]+1,questions);
        ll t2=rec(index+1,questions);
        return dp[index]= max(t1,t2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        ll ans=rec(0,questions);
        return ans;
    }
};