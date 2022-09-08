class Solution {
    public String reverseWords(String s) {
        s+=" ";
        String u = "";
        String r = "";
        for(int i =0;i<s.length();++i)
        {
            if(s.charAt(i)==' ')
            {
                if(r.length()==0)
                    continue;
                if(u.length()==0)
                    u =r;
                else
                {
                    u = r+ " "+u;
                    
                }
                // System.out.println(r);
                
                r = "";
            }
            else
                r+=s.charAt(i);
        }
        return u;
    }
}