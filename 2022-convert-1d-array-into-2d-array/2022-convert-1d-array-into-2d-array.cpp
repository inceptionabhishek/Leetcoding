class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector <vector <int>> ans;
        if(original.size()!=n*m){
            return ans;
        }
        vector <int> curr;
        for(int i=0;i<original.size();){
            int j=i;
            int temp=0;
            while(temp!=n){
                curr.push_back(original[j]);
                j++;
                temp++;
            }
            i=j;
            ans.push_back(curr);
            curr.clear();
        }
        return ans;
    }
};