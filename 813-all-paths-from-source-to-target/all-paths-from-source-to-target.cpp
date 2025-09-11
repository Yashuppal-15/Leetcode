class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        helper(graph,0,temp,ans);
        return ans;
    }
    void helper(vector<vector<int>>& graph,int node,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(node == graph.size()-1) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < graph[node].size();i++)
        {
            temp.push_back(graph[node][i]);
            helper(graph,graph[node][i],temp,ans);
            temp.pop_back();
        }
    }
};