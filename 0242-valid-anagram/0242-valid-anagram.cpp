class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>p(26,0),q(26,0);
        for(int i=0;i<s.length();i++){
            p[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            p[t[i]-'a']--;
        }
        return p==q;
    }
};