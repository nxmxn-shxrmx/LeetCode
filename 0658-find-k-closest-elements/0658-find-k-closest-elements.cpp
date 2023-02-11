class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-1;
        int center =l;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid]<=x)
                l = mid+1,center = mid;
            else
                r =mid-1;
        }
        vector<int>ans;
        int cen = center+1;
        while(k--)
        {
            if(center==-1)
            {
                ans.push_back(arr[cen]);
                cen++;
            }
            else if(cen==arr.size())
            {
                ans.push_back(arr[center]);
                center--;
            }
            else
            {
                if(abs(arr[center]-x)<=abs(arr[cen]-x))
                {
                    ans.push_back(arr[center]);
                    center--;
                }
                else
                {
                      ans.push_back(arr[cen]);
                    cen++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};