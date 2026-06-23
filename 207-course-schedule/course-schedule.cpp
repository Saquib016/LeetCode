class Solution {
public:
    bool iscycle(int src,vector<bool>& vis,vector<vector<int>>& l,vector<bool>& rec){
        vis[src]=true;
        rec[src]=true;
        for(int i=0;i<l.size();i++){
            int u  = l[i][1];
            int v = l[i][0];
            if(u==src){
            if(!vis[v]){
                if(iscycle(v,vis,l,rec)) 
                    return true;
                }
            else if(rec[v]) 
                return true;
            }
        }
        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v= numCourses;
        vector<bool> vis(v,false);
        vector<bool> rec(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(iscycle(i,vis,prerequisites,rec))
                    return false;
                }
                }
        return true;
    }
};