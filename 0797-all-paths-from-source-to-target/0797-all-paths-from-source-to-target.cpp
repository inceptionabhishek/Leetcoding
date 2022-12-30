class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int maxnode=graph.size()-1;
        auto dfs = [&](int node,auto &&dfs,vector<int>curr){
            if(node==maxnode){
                curr.push_back(node);
                ans.push_back(curr);
                return;
            }
            curr.push_back(node);
            for(auto j:graph[node]){
                dfs(j,dfs,curr);
            }
        };
        vector<int>curr={};
        dfs(0,dfs,curr);
        return ans;
    }
};