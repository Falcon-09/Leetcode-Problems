class MedianFinder {
public:
    MedianFinder() {

    }
    
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;

    void addNum(int num) {
        if (maxHeap.size() == 0 || maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(-num);

        if (maxHeap.size() > minHeap.size() + 1){
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() - minHeap.top()) / 2.0;

        return maxHeap.top();
    }
};