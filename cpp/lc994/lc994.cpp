#include <ranges>
#include <vector>
#include <tuple>
#include <ranges>
#include <deque>
#include <algorithm>


using namespace std;

using Pos = pair<int, int>;
constexpr array<pair<int, int>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<Pos> rottenOranges;
        int orangesLeft = 0;
        // find rotten oranges in the initial grid
        auto gridXsz = grid.size(), gridYsz = grid[0].size();
        for(const auto &[xIdx, row] : views::enumerate(grid)){
            for(const auto &[yIdx, val] : row | views::enumerate){
                if(val == 2){
                    rottenOranges.emplace_back(xIdx, yIdx);
                } else if(val == 1){
                    ++orangesLeft;
                }
            }
        }
        if(rottenOranges.empty())
            return (orangesLeft == 0 ? 0 : -1);
        int cycles  = 0;

        auto inBounds = [&](int x, int y){return 0 <= x && 0 <= y && x < gridXsz && y < gridYsz;};
        while(!rottenOranges.empty()){
            deque<Pos> changedOranges;
            for(const auto &orange : rottenOranges){
                for(const auto &dir : dirs){
                    if(inBounds(orange.first + dir.first,
                        orange.second + dir.second) &&
                        grid[orange.first+dir.first][orange.second+dir.second] == 1){
                            changedOranges.emplace_back(orange.first+dir.first,
                                orange.second+dir.second);
                            grid[orange.first+dir.first][orange.second+dir.second] = 2;
                            --orangesLeft;
                        }
                }
            }
            if(changedOranges.empty()){
                if(orangesLeft == 0)
                    return cycles;
                return -1;
            }
            ++cycles;
            rottenOranges = move(changedOranges);
        }
        return cycles;
    }
};