class Solution {
public:
  
    bool canReach(vector<int>& arr, int s) {
        
        if(s>=arr.size() || s<0 || arr[s]<0)
            return false;
        
        arr[s] = -arr[s];
        return arr[s]==0||canReach(arr,s-arr[s])||canReach(arr,s+arr[s]);
        
    }
};