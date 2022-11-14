class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxy=0;
        while(i<j){
            maxy=max(maxy,min(height[i],height[j])*(j-i));
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxy;
    }
};