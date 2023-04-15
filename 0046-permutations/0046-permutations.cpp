class Solution {
public:
    set<vector<int>>s;
    void per(vector<int>v,int i)
    {
        if(i==v.size())
        {
            s.insert(v);
            return;
        }
        for(int j = i;j<v.size();++j)
        {
            per(v,i+1);
            swap(v[i],v[j]);
            per(v,i+1);
            swap(v[i],v[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums,0);
         vector<vector<int>>v(begin(s),end(s));
        return v;
    }
};