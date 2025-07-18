[Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/)

Quick notes.

First approach was to do a two-pass recursive strategy, first to locate the rotten oranges, and then to recurse through
the map.

Iterative improvements 
* swapped int-indexed loops with for `grid | enumerate` and `row | enumerate`
* direct bounds checking in a five-ple if statement with `inBounds` lambda
* `using Pos = pair<int, int>`

Straightforward-ish BFS exercise.  These always feel like a bit of a code grind.