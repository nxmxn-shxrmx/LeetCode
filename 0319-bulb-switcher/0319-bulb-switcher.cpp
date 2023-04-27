class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0)return 0;
        if(n<=3)
        return 1;
        
     return  sqrt(n);   
    }
};


