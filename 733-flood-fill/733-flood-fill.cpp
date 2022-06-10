class Solution {
public:
    vector<vector<bool>>b;
    void reurse(vector<vector<int>>&v,vector<vector<int>>&g ,int i,int j,int c,int pi,int pj)
    {
    
        
        if(b[i][j]==true)
            return;
        b[i][j]=true;
         g[i][j]=c;
      // cout<<i<<" "<<j<<"\n";
        
        if(i+1<v.size() && v[i+1][j]==v[i][j])
            reurse(v,g,i+1,j,c,i,j);
        if(j+1<v[0].size() && v[i][j+1]==v[i][j])
            reurse(v,g,i,j+1,c,i,j);
        if(j-1>=0 && v[i][j-1]==v[i][j])
            reurse(v,g,i,j-1,c,i,j);
        if(i-1>=0  && v[i-1][j]==v[i][j])
            reurse(v,g,i-1,j,c,i,j);
            
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int i, int j, int c) {
        b  =  vector<vector<bool>>(v.size(),vector<bool>(v[0].size(),false));
        vector<vector<int>>g(v.begin(),v.end());
        
        reurse(v,g,i,j,c,-1,-1);
      //  cout<<"\n\n";
        return g;
    }
};