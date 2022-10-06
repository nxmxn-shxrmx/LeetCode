class TimeMap {
public:
    map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string v, int t) {
        m[key][-t] = v;
    }
    
    string get(string key, int t) {
        auto it = m[key].lower_bound(-t);
        if(it==m[key].end()) return "";
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */