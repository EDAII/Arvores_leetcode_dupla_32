#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        priority_queue<int> maxHeap;

        int totalTime = 0; 

        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            
            totalTime += duration;
            maxHeap.push(duration);

            
            if (totalTime > lastDay) {
                totalTime -= maxHeap.top(); 
                maxHeap.pop();
            }
        }

        return (int)maxHeap.size();
    }
};
