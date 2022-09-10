class Solution {
    static int arr[][][];
    public int maxProfit(int k, int[] prices) {
        
        arr=new int[prices.length+1][2*k+1][2];
        for(int i[][]:arr)
            for(int f[]:i)
                Arrays.fill(f,-1);
        return transact(2*k,prices,false,0);
    }
    public static int  transact(int k,int []prices,boolean buyed,int i)
    {
       
        if(k==0||i==prices.length) return 0;
         if(arr[i][k][buyed==false?1:0]!=-1)return arr[i][k][buyed==false?1:0];
        
        if(!buyed)
        {
         
              int a= transact(k-1,prices,true,i+1)-prices[i]; 
            int b=transact(k,prices,false,i+1);
            return arr[i][k][buyed==false?1:0]=Math.max(a,b);
        }        
        else{
            // dp sell or not sell
            int a= transact(k-1,prices,false,i+1)+prices[i]; 
            int b=transact(k,prices,true,i+1);
            return arr[i][k][buyed==false?1:0]=Math.max(a,b);
        }
    
    }
}