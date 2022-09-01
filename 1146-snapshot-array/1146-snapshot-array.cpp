class SnapshotArray {
public:
    vector<vector<pair<int,int>>>v;
    int i=0;
    SnapshotArray(int length) {
        v = vector<vector<pair<int,int>>>(length);
    }
    
    void set(int index, int val) {
        v[index].push_back({i,val});
    }
    
    int snap() {
     ++i;
        return i-1;
    }
    
    int get(int index, int snap_id) {
        
        int l = 0;
        int r = v[index].size()-1;
        // cout<<r<<" ";
        int ans=0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(v[index][mid].first<=snap_id)
               ans=v[index][mid].second,l=mid+1;
            else
                r =mid-1;
        }
        
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */