class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;){
            int j=i+1;
            int maxy=0;
            int su=neededTime[i];
            maxy=neededTime[i];
            while(j<n && s[j]==s[i]){
                maxy=max(maxy,neededTime[j]);
                su+=neededTime[j];
                j++;
            }
            ans += su-maxy;
            i=j;
        }
        return ans;
    }
};