/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
  if (k === 0) return false;

  let left = 0,
    right = 1;
  const counter = new Set();

  counter.add(nums[left]);

  for (; right < nums.length; right++) {
    if (right - left > k) {
      counter.delete(nums[left]);
      break;
    }

    if (counter.has(nums[right])) {
      return true;
    } else {
      counter.add(nums[right]);
    }
  }

  while (right < nums.length) {
    counter.delete(nums[left]);

    if (counter.has(nums[right])) {
      return true;
    }

    counter.delete(nums[left]);
    counter.add(nums[right]);
    right++;
    left++;
  }

  return false;
};

console.log(containsNearbyDuplicate([1, 2, 3, 1, 2, 3], 2));
