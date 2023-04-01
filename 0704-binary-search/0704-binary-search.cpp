class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        sort(nums.begin(),nums.end());
        int right = nums.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        if(nums[left]==target){
            return left;
        }
        return -1;
    }
};