class MyCircularQueue {
public:
    vector<int>q;
    int head, tail;
    MyCircularQueue(int k) {
        for(int i=0;i<k;i++)
            q.push_back(-1);
        
        head = 0;
        tail = 0;
    }
 
    bool enQueue(int value) {
        if(isFull())
            return false;
     
        q[tail] = value;

        if(tail!=(q.size()-1))
            tail++;
        else
            tail = 0;

        return true;
    }
    
    bool deQueue() {
        if(q[head]==-1)
            return false;
        
        
        q[head] = -1;
        
        if(head == (q.size()-1))
            head = 0;
        else
            head++;
        
        return true;
    }
    
    int Front() {
        return q[head];
    }
    
    int Rear() {
        if(tail==0)
            return q[q.size()-1];
        
        return q[tail-1];
    }
    
    bool isEmpty() {
        for(int i=0;i<q.size();i++)
            if(q[i]!=-1)
                return false;
        
        return true;
    }
    
    bool isFull() {
        for(int i=0;i<q.size();i++)
            if(q[i]==-1)
                return false;
        
        return true;
    }
};