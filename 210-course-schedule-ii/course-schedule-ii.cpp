class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<vector<int>>& graph, vector<bool>& path){
        vis[src] = true;
        path[src] = true;

        for(int i = 0; i < graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v, vis, graph, path)) return true;
                }
                else if(path[v]){
                    return true;
                }
            }
        }

        path[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int>& s, vector<vector<int>>& graph){
        vis[src] = true;

        for(int i = 0; i < graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src && !vis[v]){
                topoSort(v, vis, s, graph);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        // cycle check
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCycle(i, vis, prerequisites, path))
                    return {};
            }
        }

        stack<int> s;
        vector<bool> vis2(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis2[i]){
                topoSort(i, vis2, s, prerequisites);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};