class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n=s.size();
        vector<int>pref(n);
        pref[0]=neededTime[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+neededTime[i];
        }
        auto sum=[&](int l,int r){
            if(l==0){
                return pref[r];
            }
            return pref[r]-pref[l-1];
        };
        int ans=0;
        for(int i=0;i<n;){
            int j=i+1;
            int maxy=0;
            maxy=neededTime[i];
            while(j<n && s[j]==s[i]){
                maxy=max(maxy,neededTime[j]);
                j++;
            }
            ans += sum(i,j-1)-maxy;
            i=j;
        }
        return ans;
    }
};