class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size()-1;
        sort(people.begin(),people.end());
        int cnt=0;
        while(l < r){
            if(people[l]+people[r] <= limit){
                cnt++;
                l++;
                r--;
            }else{
                r--;
                cnt++;
            }
        }
        if(l == r){
            return  cnt + 1 ;
            
        }
        return cnt;
    }
};