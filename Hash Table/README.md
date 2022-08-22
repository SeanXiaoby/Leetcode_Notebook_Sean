# Hash Table
### Index:


----

### Definition:
- Hash table is always used to find if an element is exsisted in a container.
- Runtime complexity: O(1) Space: O(1)
- Array is actually a simple hash table
- There are three types of containers in C++ that are hash tables:
  - Array
  - unordered_set
  - unordered_map
- Comparisions of different types of containers:
|集合 |底层实现 | 是否有序 |数值是否可以重复 | 能否更改数值|查询效率 |增删效率|
|---|---| --- |---| --- | --- | ---|
|std::set |红黑树 |有序 |否 |否 | O(log n)|O(log n) |
|std::multiset | 红黑树|有序 |是 | 否| O(logn) |O(logn) |
|std::unordered_set |哈希表 |无序 |否 |否 |O(1) | O(1)|

|映射 |底层实现 | 是否有序 |数值是否可以重复 | 能否更改数值|查询效率 |增删效率|
|---|---| --- |---| --- | --- | ---|
|std::map |红黑树 |key有序 |key不可重复 |key不可修改 | O(logn)|O(logn) |
|std::multimap | 红黑树|key有序 | key可重复 | key不可修改|O(log n) |O(log n) |
|std::unordered_map |哈希表 | key无序 |key不可重复 |key不可修改 |O(1) | O(1)|


### Key points:
- 



---

## Problems:

