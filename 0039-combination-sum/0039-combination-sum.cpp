class Solution {
public:
    vector <vector <int> > ans;
    void rec(int index,int target,vector <int> curr,vector <int> candidates){
        if(index>=candidates.size()){
            if(target==0){
                ans.push_back(curr);
                return;
            }else{
                return ;
            }
        }
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        rec(index+1,target,curr,candidates);
        while(target>=0){
            curr.push_back(candidates[index]);
            target-=candidates[index];
            rec(index+1,target,curr,candidates);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> curr;
        rec(0,target,curr,candidates);
        return ans;
    }
};