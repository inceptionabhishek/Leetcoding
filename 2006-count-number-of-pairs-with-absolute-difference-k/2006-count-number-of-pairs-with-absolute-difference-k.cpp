class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map <int,int> ms;
        for(int i=0;i<nums.size();i++){
            ms[nums[i]]++;
        }
        for(auto j:ms){
            cout  << j.first << ' ' << j.second << endl;
        }
        int tot=0;
        for(auto j:ms){
            int req=j.first+k;
            if(ms.count(req)>0){
                tot += ms[req]*j.second;
            }
        }
        return tot;
    }
};