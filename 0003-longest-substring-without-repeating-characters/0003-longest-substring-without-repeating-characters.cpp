class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> ms(300,-1);
        int maxyLen=0;
        int start=-1;
        for(int i=0;i<s.length();i++){
            if(ms[s[i]]>start){
                start=ms[s[i]];
            }
            ms[s[i]]=i;
            maxyLen=max(maxyLen,i-start);
        }
        return maxyLen;
    }
};