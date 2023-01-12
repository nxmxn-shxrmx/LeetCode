/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let l = 0;
    let r =  nums.length-1;
    var a =[];
    for(var i = 0;i<nums.length;++i)
    {
        a[i] = [nums[i],i];
    }
    a.sort((x,y)=>
          {
        return x[0]-y[0];
    });
   while(l<r)
   {
        if(a[l][0]+a[r][0]==target)
            return [a[l][1],a[r][1]];
       else if(a[l][0]+a[r][0]>target) r--;
       else l++; 
   }
    return [];
};