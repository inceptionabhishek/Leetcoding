class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> v;
        for(auto j:nums1){
            v.push_back(j);
        }
        for(auto j:nums2){
            v.push_back(j);
        }
        sort(v.begin(),v.end());
        if(v.size()%2!=0){
            return v[v.size()/2];
        }
        else{
            int val=v[v.size()/2]+v[v.size()/2 -1 ];
            double val2=(double)val/2;
            return val2;
        }
    }
};