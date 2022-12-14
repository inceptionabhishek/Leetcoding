class Solution {
public:
    int dp[102];
    int rec(vector <int> nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index]=max(nums[index]+rec(nums,index+2),rec(nums,index+1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[101];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i+1]=max(dp[i-1]+nums[i],dp[i]);
        }
        return dp[n];
    }
};