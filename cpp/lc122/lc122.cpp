//
// Created by matth on 7/9/2025.
//

#include "lc122.h"

int lc122::maxProfit(vector<int>& prices) {
    if(prices.size() == 1)
        return 0;
    return ranges::fold_left(prices
            | views::pairwise
            | views::filter([](const pair<int, int> &p) { return p.first < p.second; })
            | views::transform([](const pair<int, int> &p) { return p.second - p.first; }),
        0,
        std::plus{});
}

int lc122::maxProfitLowerMemory(vector<int>& prices) {
    if(prices.size() == 1)
        return 0;
    return ranges::fold_left(prices
         | views::pairwise
         | views::transform([](const pair<int, int> &p) { return (p.first < p.second ? p.second - p.first : 0);}),
         0, std::plus{});
}

int lc122::maxProfitPairXform(vector<int> &prices){
    if(prices.size() == 1)
        return 0;
    return std::ranges::fold_left(
            std::views::adjacent_transform<2>(prices,
            [](const int &left, const int &right) {return left < right ? right - left : 0;}),
            0,
            std::plus{}
    );
}

int lc122::maxProfit17(vector<int>& prices) {
    if(prices.size() < 2){
        return 0;
    }
    vector<int> diffs{};
    adjacent_difference(begin(prices), end(prices), back_inserter(diffs));
    return accumulate(begin(diffs)+1, end(diffs), 0,
                      [](int acc, int diff){return (diff > 0 ? acc + diff : acc);});
}