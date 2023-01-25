class Solution {
public:
    int dp[101];
    int rec(string s,int i){
        if(i==s.length()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int move1=0;
        int move2=0;
        if(s[i]!='0'){
            move1 += rec(s,i+1);
        }
        
        if(i+1<s.length() && (s[i]-'0')*10+s[i+1]-'0'<=26 && s[i]!='0'){
            move2+=rec(s,i+2);
        }
        return dp[i]=move1+move2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0'){
            return 0;
        }
        return rec(s,0);
        
        
        // int dp[101];
        // memset(dp,0,sizeof(dp));
        // for(int i=0;i<s.length();i++){
        //     for(int j=0;j<=1;j++){
        //         if(i+j<s.length() && (s[i]-'0')*10+s[i+j]-'0'<=26 && s[i]!='0' )
        //     }
        // }
    }
};