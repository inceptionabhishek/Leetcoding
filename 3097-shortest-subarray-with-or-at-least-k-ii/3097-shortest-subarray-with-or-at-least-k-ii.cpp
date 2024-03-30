class Solution {
public:
    int get(vector<int> bits){
        int val = 0;
        for(int bit=0;bit<32;bit++){
            if(bits[bit]){
                val += (1<<(32-bit-1));
            }
        }
        return val;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int i=0,j=0;
        int n=nums.size();
        vector<int>bits(32,0);
        while(i<n){
            for(int bit=0;bit<32;bit++){
                if(nums[i]&(1<<bit)){
                    bits[31-bit]++;
                }
            }
            while(get(bits)>=k && j<=i){
                ans = min(ans,i-j+1);
                int toremove = nums[j];
                for(int bit=0;bit<32;bit++){
                    if(toremove&(1<<bit)){
                        bits[31-bit]-=1;
                    }
                }
                
                j++;
            }
            i++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};