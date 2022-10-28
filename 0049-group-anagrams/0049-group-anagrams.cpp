class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector <string>> v;
        map <string,vector <string>> ms;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            ms[temp].push_back(strs[i]);
        }
        for(auto j:ms){
            vector <string> curr;
            for(auto i:j.second){
                curr.push_back(i);
            }
            v.push_back(curr);
        }
        return v;
    }
};