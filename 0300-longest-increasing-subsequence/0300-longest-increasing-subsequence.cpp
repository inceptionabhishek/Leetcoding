class Solution {
public:
    int dp[2501][2501];
    int rec(int i,int prev,vector<int>&nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int ans=0;
        if(prev==-1){
            ans = max(1+rec(i+1,i,nums),rec(i+1,prev,nums));
        }
        else if(nums[i]<=nums[prev]){
            ans = max(ans,rec(i+1,prev,nums));
        }else{
            ans = max(1+rec(i+1,i,nums),rec(i+1,prev,nums));
        }
        return dp[i][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,-1,nums);
        return ans;
    }
};