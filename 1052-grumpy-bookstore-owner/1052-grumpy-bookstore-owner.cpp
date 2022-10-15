class Solution {
public:

    int maxSatisfied(vector<int>& v, vector<int>& grumpy, int k) {
        int n=v.size();
        int sum=0;
        for(int i=0;i<k;i++){
         sum += v[i];   
        }
        int sumright=0;
        int sumleft=0;
        for(int i=k;i<n;i++){
            if(grumpy[i]==0){
                sumright += v[i];
            }
        }
        int index=0;
        int maxy=0;
        
        maxy=sum+sumright;
        for(int i=k;i<n;i++){
            //cout << sumleft << " " <<sum  <<" " << sumright<< endl;
            sum =sum-v[index]+v[i];
            if(grumpy[index]==0){
                sumleft += v[index];
            }
            if(grumpy[i]==0){
                sumright-=v[i];
            }
            maxy=max(maxy,sum + sumleft+sumright);
            index++;
        }
        return maxy;
    }
};