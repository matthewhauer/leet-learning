//
// Created by matth on 7/8/2025.
//

#ifndef LEET_LEARNING_LC80SOLUTION_H
#define LEET_LEARNING_LC80SOLUTION_H

class lc80solutionTwoItr {
public:
    int removeDuplicates(vector<int>& nums) {
        int currNum = nums.front();
        int currCt = 0;
        int numCt = 0;
        auto writeItr = begin(nums);
        for(auto readItr = begin(nums); readItr != end(nums); ++readItr){
            if(currNum == *readItr){
                if(currCt < 2){
                    *writeItr = currNum;
                    ++writeItr;
                    ++numCt;
                }
                ++currCt;
            } else {
                currNum = *readItr;
                *writeItr = currNum;
                writeItr++;
                ++numCt;
                currCt = 1;
            }
        }
        return numCt;
    }
};


#endif //LEET_LEARNING_LC80SOLUTION_H
