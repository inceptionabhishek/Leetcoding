class Solution {
public:
    int maxScore(string s) {
        int cnt=0;
        for(auto j:s){
            cnt+=j-'0';
        }
        int ans=0;
        int p=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                p++;
            }
            if(s[i]=='1'){
                cnt--;
            }
            ans = max(ans,p+cnt);
        }
        return ans;
    }
};