class Solution {
public:
    const int mod =(int)1e9 + 7;
    long long dp[1001][1001];
    int countofSubsetsLessK(vector<int>&nums,int index,int sum,int k){
        
        if(sum>k){
            return 0;
        }
        if(index >= nums.size()){
            if(sum<k){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum]%mod;
        }
        long long take=countofSubsetsLessK(nums,index+1,sum+nums[index],k)%mod;
        long long nottake=countofSubsetsLessK(nums,index+1,sum,k)%mod;
        return dp[index][sum]=(take+nottake+mod)%mod;
    }
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    long long countPartitions(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        long long tt=0;
        for(auto j:nums){
            tt += j;
        }
        if(tt<2*k){
            return 0;
        }
        long long tot=binpow(2,nums.size(),mod);
        return (tot-2LL*countofSubsetsLessK(nums,0,0,k)%mod+mod)%mod;
    }
};