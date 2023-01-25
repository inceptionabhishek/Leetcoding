class Solution {
public:
    vector<int> adj[100001];
    bool visited[100001];
    vector<pair<int,int>> distance;
    void dfs(int node,int currDistance){
        if(visited[node]){
            return;
        }
        distance.push_back(make_pair(node,currDistance));
        visited[node]=true;
        for(auto j:adj[node]){
            dfs(j,currDistance+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1){
                continue;
            }
            adj[i].push_back(edges[i]);
        }
        dfs(node1,0);
        vector<pair<int,int>> v1=distance;
        distance.clear();
        memset(visited,false,sizeof(visited));
        dfs(node2,0);
        vector<pair<int,int>> v2=distance;
        distance.clear();
        int n=edges.size();
        vector<pair<int,int>> temp(n,{-1,-1});
//         for(auto j:v1){
//             cout << j.first << ' ' << j.second << endl;
//         }
        
//         cout << "--" << endl;
//         for(auto j:v2){
//             cout << j.first << ' ' << j.second << endl;
//         }
        
        for(int i=0;i<v1.size();i++){
            
            temp[v1[i].first].first=v1[i].second;
        }
        for(int i=0;i<v2.size();i++){
            temp[v2[i].first].second=v2[i].second;
        }
        
        // for(auto j:temp){
        //     cout << j.first << ' ' << j.second << endl;
        // }
        int index=-1;
        int mindistance=INT_MAX;
        for(int i=0;i<temp.size();i++){
            if(temp[i].first==-1 || temp[i].second==-1){
               
            }else{
                mindistance=min(mindistance,max(temp[i].first,temp[i].second));
            }
        }
        for(int i=0;i<temp.size();i++){
            if(max(temp[i].first,temp[i].second)==mindistance){
                return i;
            }
        }
        
        return index;
    }
};