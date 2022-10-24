class Solution {
public:
    int rec(vector <string> &arr,int index,vector <int> &chartaken){
        if(index>=arr.size()){
            int tot=0;
            for(int i=0;i<chartaken.size();i++){
                if(chartaken[i]==1){
                    tot++;
                }
            }
            return tot;
        }
        // we have a choice to select this index or not, which
        // means if we are selecting this index then we have to keep track of all the 
        // characters that are in this particular string, so that we do not ended up 
        // adding similar character in future.
        string curr= arr[index];
        // if any char of curr is present in this chartaken, then completely ignore this string
        bool found=0;
        for(int i=0;i<curr.length();i++){
            if(chartaken[curr[i]-'a'+1]==1){
                found=1;
                break;
            }
        }
        cout << curr << endl;
        cout << found << endl;
        for(int i=0;i<chartaken.size();i++){
            cout << chartaken[i] << " ";
        }
        cout << endl;
        int maxy=0;
        if(found==1){
            return rec(arr,index+1,chartaken);
        }
        else{
            int addthis2=rec(arr,index+1,chartaken);
            for(int i=0;i<curr.length();i++){
                chartaken[curr[i]-'a'+1]=1;
            }
            int addthis1=rec(arr,index+1,chartaken);
            maxy=max(addthis1,addthis2);
        }
        return maxy;
    }
    int maxLength(vector<string>& arr,string s="",int index=0) {
        unordered_set<char> ss(s.begin(),s.end());
        if(ss.size()!=s.length()){
            return 0;
        }
        int len=s.length();
        for(int i=index;i<arr.size();i++){
            len = max(len,maxLength(arr,s+arr[i],i+1));
        }
        return len;
    }
};