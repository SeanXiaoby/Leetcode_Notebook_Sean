# Array

### Definition:
Array is a combination where an amount of data of the same type is stored **continuously** in the memory space.

### Key points:
- The index of array starts from **0**.
- The address of items in an array is continous in the memory.
- When **adding** or **deleting** items, all the other items **following** will be modified.
- Items in an array **cannot** be deleted but can only be **overwritten**.


### - 2D array:
- 2D array is also **continously** stored in memory.(For C++)

---

## Problems:

### Binary search:
#### #704: [Binary search (easy)](https://leetcode.com/problems/binary-search/):
- Runtime: O(logn)
- Constrains/Key words: 
  - The given array must be **sorted**.
  - There is **no duplicate** item in the array.
- while loop: left **<=** right
- Little trick: To prevent variable **overflow**, we can use:
```
mid = left + (right - left) /2
```
instead of: 
```
mid = (left + right) /2
```

#### #35: [Find insert position (easy)](https://leetcode.com/problems/search-insert-position/):
- Runtime: O(logn) + ascending order + no duplicate ==> **Binary search**
- Add a comparing at the stopping point: when left >= right, compare the target with the left value.
- ~~Mildly modify the [#704](https://leetcode.com/problems/binary-search/):~~
```cpp
if(target<nums[mid]){
  right = mid;  //Instead of "right = mid -1", to prevent right gets less than left
}
```
- The last point is **WRONG!!!** We **cannot** modify like that! It will stuck in a loop!

#### #34: [Find First and Last Position of Element in Sorted Array (medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/):
**Key words:** Two binary search
- Runtime: O(logn) + **Non-decreasing** order + **has** duplicate ==> **Binary search**
- Use binary search **twice** to find the staring pos and ending pos respectively.
- Find the left border(starting point):
  - If nums[mid] == target:
    - If mid == 0 or nums[mid -1] < target: **This is the left border!!**
    - Else(mid!=0 and left item is still the target value): search left side part: right = mid -1
  - If nums[mid] != target: Follow the normal binary search steps
- Find the right border(ending point):
  - If nums[mid] == target:
    - If mid == end or nums[mid +1] > target: **We hit the right border!!**
    - Else: search right part: left = mid +1;
  - If nums[mid] != target: follow the normal binary search steps
- Video reference: [two binary search](https://www.bilibili.com/video/BV1wy4y1k76F?share_source=copy_web&vd_source=1dccb53c95e247fd924dbfa0318596b5)
