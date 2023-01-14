class Solution {
public:
    vector<int>adj[1001];
    bool vis[1001];
    vector<int>currComponent;
    void dfs(int node){
        currComponent.push_back(node);
        vis[node]=true;
        for(auto j:adj[node]){
            if(!vis[j]){
                dfs(j);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        for(int i=0;i<n;i++){
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        vector<vector<int>> v;
        for(int i=0;i<=25;i++){
            if(!vis[i]){
                currComponent.clear();
                dfs(i);
                v.push_back(currComponent);
            }
        }
        map<int,int> ms;
        for(auto j:v){
            sort(j.begin(),j.end());
            int mini=j[0];
            for(auto i:j){
                ms[i]=mini;
            }
        }
        for(int i=0;i<baseStr.length();i++){
            int node=baseStr[i]-'a';
            baseStr[i]=ms[node]+'a';
        }
        return baseStr;
    }
};