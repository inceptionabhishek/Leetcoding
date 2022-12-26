class Solution {
public:
    int dp[10001];
    int rec(vector <int> &nums,int index){
        if(index==nums.size()-1){
            return 1;
        }
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int MaxJump = nums[index];
        for(int i=1;i<=MaxJump;i++){
            if(rec(nums,index+i)){
                return dp[index]=1;
            }
        }
        return dp[index]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=rec(nums,0);
        if(ans==1){
            return true;
        }
        return false;
    }
};