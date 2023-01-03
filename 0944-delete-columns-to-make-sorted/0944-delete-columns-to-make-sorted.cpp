class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            vector<char>v;
            for(int j=0;j<n;j++){
                v.push_back(strs[j][i]);
            }
            if(!is_sorted(v.begin(),v.end())){
                cnt++;
            }
        }
        return cnt;
    }
};