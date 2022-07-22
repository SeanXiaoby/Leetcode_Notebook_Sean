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
#### #704: [Binary search(easy)](https://leetcode.com/problems/binary-search/):
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

#### #35: [Find insert position(easy)](https://leetcode.com/problems/search-insert-position/):
- Runtime: O(logn) + ascending order + no duplicate ==> **Binary search**
- Add a comparing at the stopping point: when left >= right, compare the target with the left value.
- Mildly modify the [#704](https://leetcode.com/problems/binary-search/):
```cpp
if(target<nums[mid]){
  right = mid;  //Instead of "right = mid -1", to prevent right gets less than left
}
```
