class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        long long mini=INT_MAX;
        int index=-1;
        long long leftsum=nums[0];
        long long rightsum=0;
        for(int i=1;i<nums.size();i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            long long val1=leftsum/(i+1);
            int val2=0;
            if(n-(i+1)!=0){
                val2=(rightsum)/(n-(i+1));
            }
            long long diff=abs(val1-val2);
            if(mini>diff){
                mini=diff;
                index=i;
            }
            if(i!=n-1){
                leftsum += nums[i+1];
                rightsum -= nums[i+1];
            }
        }
        return index;
    }
};