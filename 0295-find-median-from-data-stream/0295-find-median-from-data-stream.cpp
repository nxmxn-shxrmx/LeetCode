class MedianFinder {
public:
    multiset<int>l,r;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        l.insert(num);
        if(l.size()-r.size()>1)
        {
            auto it = l.end();
            --it;
            r.insert(*it);
            l.erase(l.find(*it));
          
        }
        if(r.size())
        {
             auto it = l.end();
            --it;
            if(*it>*r.begin())
            {
                l.insert(*r.begin());
                r.erase(r.find(*r.begin()));
                r.insert(*it);
                l.erase(l.find(*it));
            }
        }
    }
    

    double findMedian() {
    
      auto it = l.end();
        --it;
        
        if(l.size()%2!=r.size()%2)
          return *it;
    
        
        int p = *it;
        int o = *it;
        if(r.size())
            p = *r.begin();
        
        return (o+p)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */