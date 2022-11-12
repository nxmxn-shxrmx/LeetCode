class StockSpanner {
public:
    stack<int>s;
    vector<int>v;
    int i = 0;
     StockSpanner() {
    }
    
 int next(int price) {
        v.push_back(price);
        while(!s.empty() && v[s.top()]<=v[i])
            s.pop();
        if(s.empty())
        {
            s.push(i);
            i+=1;
            return i;
        }
        else
        {
            int h = s.top();
            s.push(i);
            i+=1;
            return i-1-h;
        }
        return 0;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */