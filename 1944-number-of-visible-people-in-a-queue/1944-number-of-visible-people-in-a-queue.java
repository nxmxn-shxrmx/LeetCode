class Solution {
    public int[] canSeePersonsCount(int[] heights) {
    Stack<Integer>s= new Stack<Integer>();
    int []arr = new int[heights.length];
        arr[heights.length-1]=0;
    s.push(heights[heights.length-1]);
    // System.out.println(s.peek());
    for(int i=heights.length-2;i>=0;--i)
    {
        if(heights[i]<heights[i+1])
        {
            arr[i]=1;
            s.push(heights[i]);
        }
        
        else
        {
            int c = 0;
    
            while(!s.empty() && heights[i]>s.peek())
            {
                // System.out.println(c+" "+s.pop());
                s.pop();
                c++;
            }
            if(!s.empty())
                arr[i]++;
            arr[i]+=c;
            s.push(heights[i]);
        }
    
    }
        return arr;
    }
}