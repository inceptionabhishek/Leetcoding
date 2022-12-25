class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int pref[nums.size()];
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }

        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int pos=lower_bound(pref,pref+n,queries[i])-pref;
            if(pos<nums.size()){
                if(pref[pos]==queries[i]){
                    ans.push_back(pos+1);
                }else{
                    ans.push_back(pos);
                }
            }else{
                ans.push_back(nums.size());
            }
        }
        return ans;
    }
};