class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int>ms;
        for(auto j:nums){
            ms[j]++;
        }
        nums.clear();
        for(auto j:ms){
            cout << j.first << ' ' << j.second << endl;
            int curr = j.second;
            while(curr>0){
                nums.push_back(j.first);
                curr--;
            }
                
        }
        ms.clear();
        return nums;
    }
};