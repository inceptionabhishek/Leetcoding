class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans=1e18;
        vector<long long>mini(nums.size(),1e18);
        for(int i=0;i<nums.size();i++){
            long long s=0;
            for(int j=0;j<nums.size();j++){
                mini[j]=min(mini[j],1LL*nums[(i+j)%(nums.size())]);
                s += mini[j];
            }
            s = 1LL*(s+1LL*i*x);
            ans = min(ans,s);
        }
        return ans;
    }
};