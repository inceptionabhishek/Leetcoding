class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        vector<int> pref(n);
        pref[0]=possible[0]? 1 : -1;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1] + (possible[i]? 1 : -1);
        }
        int tot=pref[n-1];
        for(int i=0;i<n-1;i++){
            int curr = pref[i];
            int rem = tot - curr;
            if(curr>rem){
                return i+1;
            }
        }
        return -1;
    }
};