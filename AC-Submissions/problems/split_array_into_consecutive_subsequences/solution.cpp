/// Copied, I'll Solve Later.
class Interval{
    public:
    int start;
    int end;
    int len;
    Interval(int start,int end){
        this->start = start;
        this->end = end;
        len = end - start + 1;
    }
};
bool operator<(const Interval &i1,const Interval &i2){
    return i1.end == i2.end ? i1.len > i2.len : i1.end > i2.end;
}
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int num = nums.size();
        priority_queue<Interval> pq;
        for(int num:nums){
             while (!pq.empty() && pq.top().end + 1 < num) {
                if (pq.top().len < 3) return false;
                 pq.pop();
             }
            if (pq.empty() || pq.top().end == num) {
                Interval itr = Interval(num,num);
                pq.push(itr);
            } else {
                int st = pq.top().start;
                pq.pop();
                Interval itr = Interval(st,num);
                pq.push(itr);
            }
        }
        while (!pq.empty()) {
            if (pq.top().len < 3) return false;
             pq.pop();
         }
        return true;
    }
};