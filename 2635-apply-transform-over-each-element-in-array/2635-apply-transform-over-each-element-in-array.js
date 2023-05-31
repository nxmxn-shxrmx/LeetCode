/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    var a = arr.map((v,i)=>fn(v,i))
    return a;
};