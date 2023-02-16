class Solution {
public:

    int maxFrequency(vector<int>& v, int k) {
     sort(begin(v),end(v));
     int u =0;
        int j = v.size()-1;
        for(int i = v.size()-1;~i;--i)
        {
                k-=(v[j]-v[i]);
                if(k<0)
                {
                    k +=(j-i)*(v[j]-v[j-1]);
                    j--;
                }
            u = max(j-i+1,u);
            
        }
        
        return j+1;
    }
};

//9 6 3
//
//13 8 5 4
//13 8 0  
//1