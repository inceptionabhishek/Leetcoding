class Solution {
public:
    void getans(vector <vector <int>> &ans,vector <int> v,int begin){
        if(begin>=v.size()){
            ans.push_back(v);
            return;
        }
        for(int i=begin;i<v.size();i++){
            swap(v[begin],v[i]);
            getans(ans,v,begin+1);
            swap(v[begin],v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        getans(ans,nums,0);
        return ans;
    }
};