LeetCode Problem 80 - Remove Duplicates from Sorted Array II

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

This is one of the "Top Interview 150" problems in the early "Arrays/Strings" section, plus is marked as a "two pointers"
problem.  It reads as a straightforward two-pointer walk, where a 'write' and 'read' pointer advance at different rates.
The input array must be modified in-place, the test harness will fail the solution if it uses more than O(1) _extra_
memory.

I had my classic, "tried to solve the problem before reading the whole thing", and did not recognize that only
duplicates after the second should be removed.  A little different than dropping the sequence into a `set` and squashing
the results into the original vector!

After coming up with the initial "two iterators" solution, I ask ChatGPT for C++23 style enhancement _hints_, and it
provided the following:
1. Consider replacing the explicit loop with `ranges::for_each` or `views::enumerate`.  Other ideas included using
  `views::iota` + `views::zip` to match index & value.  Alternately `views::pairwise` or `views::chunk_by`, which may be
  a C++26 draft feature.
2. Replace dupe tracking with `views::group_by` if available.
3. Use `ranges::subrange` or `views::take_while` for more structure, and if `erase` based logic is used in the future
4. Favor `ranges::copy_if` or `ranges::copy` later on.
5. Stretch: Create a `DistinctTwiceView`.