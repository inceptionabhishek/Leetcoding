class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int maxy=0;
        int curr;
        for(auto j:m){
            if(maxy<j.second){
                maxy=j.second;
                curr=j.first;
            }
        }
        return curr;
    }
};