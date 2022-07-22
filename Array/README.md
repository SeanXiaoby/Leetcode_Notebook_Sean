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
- Constrains: 
  - The given array must be of **ascending order**.
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
