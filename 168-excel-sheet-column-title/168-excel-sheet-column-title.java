class Solution {
    public String convertToTitle(int columnNumber) {
        Map<Integer,Character> maps =new HashMap<>();
        int j=1;
        for(int i=65;i<=90;i++)
        {
            char ch=(char)i;
            maps.put(j%26,ch);
            j++;
        }
        int temp=columnNumber;
        String out="";
        while(temp>0)
        {
            out=maps.get(temp%26)+out;
            int tn=temp/26;
            if(temp%26==0)
                tn--;
            temp = tn;
        }
        return out;
        
    }
}