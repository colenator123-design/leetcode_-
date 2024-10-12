class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // 將區間按照起點進行排序
        sort(intervals.begin(), intervals.end());
        // 最小堆，用來儲存區間的結束點
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (const auto& interval : intervals) {
            // 如果當前區間的起點大於堆頂的結束點，則可以合併到該組
            if (!minHeap.empty() && interval[0] > minHeap.top()) {
                minHeap.pop();
            }
            // 將當前區間的結束點放入堆中
            minHeap.push(interval[1]);
        }
        
        // 堆的大小即為最少的組數
        return minHeap.size();
    }
};
