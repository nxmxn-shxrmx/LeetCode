class Solution {
public:
    vector<int>ans;
    void f(int i ,int n)
    {
        if(i>n)
            return;

        ans.push_back(i);
        for(int j = 0;j<10;++j)
        {
            f(i*10+j,n);  
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i =1;i<=min(9,n);++i)
            f(i,n);
        
        return ans;
    }
};
