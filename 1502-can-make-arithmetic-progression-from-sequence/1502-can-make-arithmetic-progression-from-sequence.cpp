class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<int>d;
        for(int i=1;i<arr.size();i++){
            d.insert(arr[i]-arr[i-1]);
        }
        return d.size()==1;
    }
};