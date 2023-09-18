class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                cnt+=mat[i][j];
                if(mat[i][j]==0){
                    break;
                }
            }
            v.push_back(make_pair(cnt,i));
        }
        auto cmp=[&](pair<int,int>a,pair<int,int>&b){
            if(a.first!=b.first)
                return a.first<b.first;
            return a.second<b.second;
        };
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);        
        }
        return ans;
    }
};