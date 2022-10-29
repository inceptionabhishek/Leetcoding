class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map <int,string> ms;
        char start='a';
        for(int i=2;i<=9;i++){
            if(i==7 || i==9){
                string curr="";
                for(int j=0;j<4;j++){
                    curr += start;
                    start++;
                }
                ms[i]=curr;
            }else{
                string curr="";
                for(int j=0;j<3;j++){
                    curr += start;
                    start++;
                }
                ms[i]=curr;
            }
        }
        vector <string> ans;
        vector <string> finalans;
        for(int i=0;i<digits.length();i++){
            int val=digits[i]-'0';
            string curr=ms[val];
            if(ans.size()==0){
                for(int j=0;j<curr.length();j++){
                    string temp="";
                    temp+=curr[j];
                    ans.push_back(temp);
                }
            }else{
                vector <string> temp;
                for(int j=0;j<ans.size();j++){
                    for(int k=0;k<curr.length();k++){
                        string tt=ans[j];
                        tt += curr[k];
                        temp.push_back(tt);
                    }
                }
                for(int j=0;j<temp.size();j++){
                    ans.push_back(temp[j]);
                }
            }
        }
       
        for(auto j:ans){
            if(j.length()==digits.length()){
                finalans.push_back(j);
            }
        }
        return finalans;
    }
};