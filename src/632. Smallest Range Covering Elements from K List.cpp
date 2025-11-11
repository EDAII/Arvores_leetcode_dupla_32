#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      
        using T = tuple<int, int, int>;

       
        priority_queue<T, vector<T>, greater<T>> pq;

        
        int currentMax = numeric_limits<int>::min();

        
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.emplace(nums[i][0], i, 0);  
            currentMax = max(currentMax, nums[i][0]);  
        }

        
        int bestStart = 0;
        int bestEnd = numeric_limits<int>::max();

        
        while (true) {
            
            auto [minVal, listIdx, elemIdx] = pq.top();
            pq.pop();

          
            if ((currentMax - minVal < bestEnd - bestStart) ||
                (currentMax - minVal == bestEnd - bestStart && minVal < bestStart)) {
                bestStart = minVal;
                bestEnd = currentMax;
            }

            
            if (elemIdx + 1 == (int)nums[listIdx].size())
                break;

            
            int nextVal = nums[listIdx][elemIdx + 1];

            
            pq.emplace(nextVal, listIdx, elemIdx + 1);

            
            currentMax = max(currentMax, nextVal);
        }

        
        return {bestStart, bestEnd};
    }
};
