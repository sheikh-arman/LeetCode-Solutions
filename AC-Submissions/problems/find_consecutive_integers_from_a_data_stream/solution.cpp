class DataStream {
public:
    int a,b;
    int last,cnt;
    DataStream(int value, int k) {
        a=value;
        b=k;
        last=-1;
        cnt=0;
    }
    
    bool consec(int num) {
        if(num==a){
            cnt++;
        }
        else{
            cnt=0;
        }
        return cnt>=b;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */