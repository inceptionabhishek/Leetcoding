class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='0';
        for(int i=0;i<letters.size();i++){
            if(letters[i]-'a' > target-'a'){
                if(ans=='0'){
                    ans=letters[i];
                }else{
                    if(letters[i]-'a' < ans-'a'){
                        ans = letters[i];
                    }
                }
            }
        }
        
        return ans=='0' ? letters[0] : ans;
    }
};