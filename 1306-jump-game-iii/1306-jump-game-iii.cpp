class Solution {
public:
  
    bool canReach(vector<int>& arr, int s) {
        
        if(s>=arr.size() || s<0)
            return false;
        
        if(arr[s]==0)
            return true;
        
        if(arr[s]==-1)
            return false;
        
        int h = arr[s];
        arr[s] = -1;
        return canReach(arr,s+h)||canReach(arr,s-h);
        
    }
};