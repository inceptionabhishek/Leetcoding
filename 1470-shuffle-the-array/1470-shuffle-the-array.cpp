class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int index = 0;
        vector<int> res(nums.size());

        for(int i = 0; i < nums.size(); i++) {

            res[i] = i % 2 == 0 ? nums[index] : nums[index + n];
            if(i % 2) index++;
        }

        return res;
    }
};