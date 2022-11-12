class MedianFinder {
public:
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxPq.empty() or maxPq.top()>num){
            maxPq.push(num);
        }else{
            minPq.push(num);
        }
        
        if(maxPq.size()>minPq.size()+1){
            minPq.push(maxPq.top());
            maxPq.pop();
        }else if(minPq.size()>maxPq.size()+1){
            maxPq.push(minPq.top());
            minPq.pop();
        }
        
    }
    
    double findMedian() {
        if(maxPq.size()==minPq.size()){
            return (double)(maxPq.top()+minPq.top())/2.0;
        }else{
            if(maxPq.size()>minPq.size())
                return maxPq.top();
            return minPq.top();
        }
    }
};