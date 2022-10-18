class Solution {
public:
    long long dp[100001][4][4];
    const long long mod=1000000007;
    int rec(int n,int tot,int absentMax,int lateMax){
        if(absentMax>=2){
            return 0;
        }
        if(lateMax>=3){
            return 0;
        }
        
        if(tot>=n){
            return 1;
        }
        if(dp[tot][absentMax][lateMax]!=-1){
            return dp[tot][absentMax][lateMax]%mod;
        }
        return dp[tot][absentMax][lateMax]=(rec(n,tot+1,absentMax+1,0)%mod+
            rec(n,tot+1,absentMax,0)%mod+
            rec(n,tot+1,absentMax,lateMax+1)%mod)%mod;
    }
    int checkRecord(int n) {
        int tot=0;
        int absentMax=0;
        int lateMax=0;
        memset(dp,-1,sizeof(dp));
        return rec(n,tot,absentMax,lateMax);
    }
};