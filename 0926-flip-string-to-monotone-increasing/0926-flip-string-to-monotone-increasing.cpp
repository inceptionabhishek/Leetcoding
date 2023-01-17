class Solution {
public:
    int dp[100001][2];
    int rec(string &s,int index, int one){
        //cout << index << endl;
        if(index>=s.length()){
            return 0;
        }
        if(dp[index][one]!=-1){
            return dp[index][one];
        }
        int totOps=0;
        if(one){
            if(s[index]=='0'){
                int op1=1+rec(s,index+1,one);
                totOps=op1;
            }else{
                int op1=rec(s,index+1,one);
                totOps=op1;
            }
        }else{
            if(s[index]=='0'){
                int op1=1+rec(s,index+1,1);
                int op2=rec(s,index+1,0);
                totOps+=min(op1,op2);
            }else{
                int op1=rec(s,index+1,1);
                int op2=1+rec(s,index+1,0);
                totOps+=min(op1,op2);
            }
        }
        return  dp[index][one]=totOps;
    }
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=rec(s,0,0);
        return ans;
    }
};