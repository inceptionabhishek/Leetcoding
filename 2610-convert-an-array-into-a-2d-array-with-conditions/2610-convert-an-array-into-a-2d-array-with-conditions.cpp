class Solution {
public:
    bool check(map<int,int>&ms){
        for(auto j:ms){
            if(j.second !=0 ){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>ms;
        for(auto j:nums){
            ms[j]++;
        }
        vector<vector<int>> ans;
        while(check(ms)){
            vector<int>temp;
            for(auto j:ms){
                if(j.second==0){
                    continue;
                }
                temp.push_back(j.first);
                ms[j.first]-=1;
            }
            ans.push_back(temp);
        }
        return ans;
        ms.clear();
    }
};