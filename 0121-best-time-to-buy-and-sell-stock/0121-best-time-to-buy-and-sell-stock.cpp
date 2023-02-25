class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector <int> storemin;
        int mini=INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            storemin.push_back(mini);
        }
        int maxyans=0;
        for(int i=0;i<prices.size();i++){
            maxyans=max(maxyans,prices[i]-storemin[i]);
        }
        return maxyans;
    }
};