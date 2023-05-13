class Solution {
public:
    const long long mod=1000000007;
    long long dp[100001];
int rec(int len,int zero,int one){
    if(len<0){
      return 0;
    }
    if(len==0){
        return 1;
    }
    if(dp[len]!=-1){
      return dp[len];
    }
    int ops1=rec(len-zero,zero,one)%mod;
    int ops2=rec(len-one,zero,one)%mod;
    return dp[len]=(ops2+ops1+mod)%mod;
}
int countGoodStrings(int low, int high, int zero, int one) {
            int ans=0;
            memset(dp,-1,sizeof(dp));
            for(int i=low;i<=high;i++){
                ans =(ans%mod + rec(i,zero,one)%mod)%mod;
            }
            return ans;
        }
};