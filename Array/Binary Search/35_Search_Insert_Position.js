/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  let l = 0,
    r = nums.length - 1;

  while (r >= l) {
    const mid = Math.floor((r + l) / 2);
    const midN = nums[mid];

    if (midN === target) {
      return mid;
    } else if (target > midN) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return l - 1;
};

console.log(searchInsert([1, 3, 5, 6], 4));
