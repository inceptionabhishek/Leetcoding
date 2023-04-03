class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int pref[n],suff[n];
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            if(pref[i-1]==0){
                pref[i]=nums[i];
                continue;
            }
            pref[i]=pref[i-1]*nums[i];
        }
        reverse(nums.begin(),nums.end());
        suff[0]=nums[0];
        for(int i=1;i<n;i++){
            if(suff[i-1]==0){
                suff[i]=nums[i];
                continue;
            }
            suff[i]=suff[i-1]*nums[i];
        }
        for(int i=0;i<n;i++){
            cout << pref[i] << ' ';
        }
        cout << endl;
        for(int i=0;i<n;i++){
            cout << suff[i] << ' ';
        }
        cout << endl;
        int ans=pref[0];
        ans = max(suff[0],ans);
        for(int i=1;i<n;i++){
            ans = max(ans,pref[i]);
            ans = max(ans,suff[i]);
        }
        return ans;
    }
};