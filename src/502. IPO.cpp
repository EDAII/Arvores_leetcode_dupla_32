#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        
        vector<pair<int, int>> projects; 
        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }

        
        sort(projects.begin(), projects.end());

        
        priority_queue<int> availableProjects; 

        int index = 0; 
        long long currentCapital = w; 

        
        for (int i = 0; i < k; i++) {
            
            while (index < n && projects[index].first <= currentCapital) {
                availableProjects.push(projects[index].second); 
                index++;
            }

            
            if (availableProjects.empty()) break;

            
            currentCapital += availableProjects.top();
            availableProjects.pop();
        }

       
        return (int)currentCapital;
    }
};
