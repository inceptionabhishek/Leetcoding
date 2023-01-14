class Solution {
public:
    vector<int>adj[1001];
    bool vis[1001];
    int maxy=30;
    vector<int>currComponent;
    void dfs(int node){
        currComponent.push_back(node);
        maxy=min(maxy,node);
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
        map<int,int> ms;
        for(int i=0;i<=25;i++){
            if(!vis[i]){
                currComponent.clear();
                maxy=30;
                dfs(i);
                for(auto j:currComponent){
                    ms[j]=maxy;
                }
            }
        }
        for(int i=0;i<baseStr.length();i++){
            int node=baseStr[i]-'a';
            baseStr[i]=ms[node]+'a';
        }
        return baseStr;
    }
};