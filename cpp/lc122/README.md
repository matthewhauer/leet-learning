# 122. Best Time to Buy and Sell Stock II

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

## Statement:
* You are given an integer array prices where prices[i] is the price of a given stock on the ith day. 
* On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any
        time. However, you can buy it then immediately sell it on the same day.
* Find and return the maximum profit you can achieve.

## Thoughts
Another "Top Interview 150" question, this one reads like a classic pipeline question: calculate the sum of the
differences between adjacent sequence values.  Breaking this down into steps, we want to:
1. View the sequence **pairwise**, using `std::ranges::views::pairwise` (optional)
2. Filter the sequence pairs for only `(pair.first < pair.second)`, since we can't "achieve profit" if we sell for a
negative value
3. Calculate the difference between `pair.first` and `pair.second`
4. Accumulate the total

Two approaches immediately jump out: use `views` to perform a `pairwise | filter | transform` and `fold_left` the
resultant view, or use the sequence-based `adjacent_difference`, skip the first value, and write a custom accumulator
lambda for `std::accumulate` or `std::reduce`.

## Ranges solution
Straightforward per above.  Decompose the operations with `views::pairwise`, `views::filter`, `views::transform`, and 
accumulate with `ranges::fold_left`.

A quick pass for the code golf highlights that an intermediate view can be made OBE by combining a manual filter into
the `transform`.

Another check of cppreference.com digs up a `views::adjacent_transform`, which allows us to combine
`pairwise | transform` into a single cohesive function call.  This is further simplified using the specialization
`views::pairwise_transform`, which maps to `views::adjacent_transform<2>`.