class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>v(edges.size(),INT_MAX);
        v[node1]=0;
        queue<int>q;
        q.push(node1);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            if(edges[i]!=-1 && v[edges[i]]>v[i]+1)
                q.push(edges[i]),v[edges[i]]=v[i]+1;
        }
        vector<int>u(edges.size(),INT_MAX);
        u[node2]=0;
        q.push(node2);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            if(edges[i]!=-1 && u[edges[i]]>u[i]+1)
                q.push(edges[i]),u[edges[i]]=u[i]+1;
        }
        int mx  = INT_MAX;
        int ans = 0;
        for(int i =0;i<edges.size();++i)
        {
            int p = max(u[i],v[i]);
            if(p<mx)
            {
                mx = p;
                ans =i;
            }
        }
        return mx==INT_MAX?-1:ans;
    }
};