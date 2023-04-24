class Solution {
public:
    bool check(int days,vector<int>&b,int m,int k){
        //cout << "days : " << days << endl;
        vector<int> idx;
        for(int i=0;i<b.size();i++){
            if(b[i] <= days){
                idx.push_back(i);
            }
        }
        // for(auto j:idx){
        //     cout << j << ' ';
        // }
        // cout << endl;
        int cnt=0;
        int prev=-1;
        for(int i=0;i<idx.size();){
            //cout << cnt << ' ' << prev << ' ' << m << endl;
            if(cnt == k){
                m--;
                cnt=0;
                prev=-1;
            }else{
                if(prev == -1){
                    prev = idx[i];
                    cnt=1;
                }else{
                    if(idx[i]-prev != 1){
                        cnt=1;
                        prev= idx[i];
                    }else{
                        cnt++;
                        prev=idx[i];
                    }
                }
                i++;
            }
        }
        if(cnt == k){
            m--;
            cnt=0;
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r= *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(mid,bloomDay,m,k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};