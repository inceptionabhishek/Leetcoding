class Solution{
    public:
        int dp[100001];
        int rec(int i,vector<int>&nums){
            if(i>=nums.size()){
                return 1;
            }
            if(dp[i]!=-1){
                return dp[i];
            }
            int n=nums.size();
            int ans=0;
            if(i+1<n && nums[i]==nums[i+1]){
                ans |= rec(i+2,nums);
            }
            if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                ans |= rec(i+3,nums);
            }
            if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
                ans |= rec(i+3,nums);
            }
            return dp[i]=ans;
        }
        bool validPartition(vector<int> &nums){
            for(int i=0;i<nums.size();i++){
                dp[i]=-1;
            }
            int ans = rec(0, nums);
            return ans;
        }
};