class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>ms;
        for(auto j:nums){
            ms[j]++;
        }
        int tot=0;
        for(auto j:ms){
            tot += (j.second-1)*j.second/2;
        }
        return tot;
    }
};