# Array
### Index:
- [Intro](https://github.com/SeanXiaoby/Leetcode_Notebook_Sean/tree/main/Array#definition)
- [Binary Search](https://github.com/SeanXiaoby/Leetcode_Notebook_Sean/tree/main/Array#binary-search)
- [Two Pointers](https://github.com/SeanXiaoby/Leetcode_Notebook_Sean/tree/main/Array#two-pointers)
- [Sliding Window]()

----

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

#### #69: [Sqrt(x) (easy)](https://leetcode.com/problems/sqrtx/)
- Search in a natural integer array ==> **Binary Search**
- Initialized searching range: 1 ~ x
- Set stopping condition:
  - If x == sq(mid): return mid
  - If mid hit the border: return mid
  - If x is right between the squares of two integer: return the smaller one
  - Else: follow the normal binary search steps
- **Warning::** When squaring mid, the result might overflow. We can tranfer the variable type to double to solve this problem.

----
### Todo lists:
- ~~#278: [First bad version](https://leetcode.com/problems/first-bad-version/)~~ 
- #367: [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)
- [LeetCode算法题整理（二分法篇）Binary Search](https://darktiantian.github.io/LeetCode%E7%AE%97%E6%B3%95%E9%A2%98%E6%95%B4%E7%90%86%EF%BC%88%E4%BA%8C%E5%88%86%E6%B3%95%E7%AF%87%EF%BC%89Binary-Search/)

----

### Two Pointers:

- Usually used in erasing elements
- Only iterate the whole array once: runtime complexity O(n)
- Only need memory for the original array: space complexity O(1)
- Usage:
  - **Fast pointer: Find the next matched element**
  - **Slow pointer: save the element to slow pointer index**
  
#### #27: [Remove Element (easy)](https://leetcode.com/problems/remove-element/):
- If using std::vector::erase: Runtime complexity: O(n<sup>2</sup>)
- Two pointers solution:
  - Fast pointer: Find the matched element (to erase)
  - Slow pointer: If the fast pointer does **not** point to a matched element, save the element to the slow pointer position.
- When fast pointer reach the end of the array, the loop ends. The slow pointer's val should be the length of un-erased elements.

#### #977: [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/):
- Use two pointers from both the head and the tail.
- Stop when index1 == index2
- Compare nums[index1] and nums[index2], push the larger one to res vector.
- Reverse res vector

----

### Sliding Window
#### When to use sliding window??
- **Sorted** input array
- Find **continous** sub-array

#### #209 [Minimize size subarray sum (medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
- Brute-force: O(n<sup>2</sup>)  ----> Sliding window: O(n)
- Outer loop: index of window ending
- Insider loop: Judge if window match requirements (If sum of items inside the window >= target)
  - If true: Make window smaller: left-index ++
  - If false: Enter next loop
- [Video tutorial](https://www.bilibili.com/video/BV1tZ4y1q7XE?share_source=copy_web&vd_source=1dccb53c95e247fd924dbfa0318596b5)




