class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int>colsum,rowsum;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s+=mat[i][j];
            }
            rowsum.push_back(s);
        }
        for(int i=0;i<rowsum.size();i++){
            cout << rowsum[i] << ' ';
        }
        cout << endl;
        for(int i=0;i<m;i++){
            int s=0;
            for(int j=0;j<n;j++){
                s+=mat[j][i];
            }
            colsum.push_back(s);
        }
        for(int i=0;i<colsum.size();i++){
            cout << colsum[i] << ' ';
        }
        cout << endl;
        int cnt=0;
        set<pair<int,int>> p;
        for(int i=0;i<rowsum.size();i++){
            for(int j=0;j<colsum.size();j++){
                if(rowsum[i]==1 && colsum[j]==1 && mat[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};