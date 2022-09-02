class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    
     int p = INT_MIN;
     vector<vector<double>>slopes(points.size(),vector<double>(points.size()));
       for(int count = 0;count<points.size();++count)
       {
           for(int next = count+1;next<points.size();++next)
           {double a = points[count][1]-points[next][1];
            double b = points[count][0]-points[next][0]; 
            if(a==0){
                slopes[count][next]=0;
               slopes[next][count]=0;
            }else{
               double h = a/b;
               slopes[count][next]=h;
               slopes[next][count]=h;
            }
            
           }
       }
        for(int i=0;i<slopes.size();++i)
        {
            map<double,int>m;
            int u =0;
            for(int j =0;j<slopes.size();++j)
                if(i!=j)
                m[slopes[i][j]]++,u=max(u,m[slopes[i][j]]);
            p =max(u,p);
        }
        
     return p+1;   
    }
};