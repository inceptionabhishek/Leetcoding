class Solution {
public:
    int dp[15][17000];
    int mod=1000000007;
    int rec(int previndex,vector<int>&nums,int mask){
        int n=nums.size();
        if(mask == (1<<n)-1){
            return 1;
        }
        if(dp[previndex][mask]!=-1){
            return dp[previndex][mask]%mod;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(!(mask&(1<<i))){
                if(nums[i]%nums[previndex]==0 || nums[previndex]%nums[i]==0){
                    int newmask=mask;
                    newmask |= (1<<i);
                    int curr = rec(i,nums,newmask)%mod;
                    ans = (ans+curr)%mod;
                    ans = ans % mod;
                }
            }
        }
        return dp[previndex][mask]=ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            int mask = 0;
            mask |= (1 << i);
            int val = rec(i,nums,mask);
            ans = (ans+val)%mod;
        }
        return ans;
    }
};