class LUPrefix {
public:
    int cnt=0;
    int ar[100010];
    LUPrefix(int n) {
        for(int i=0;i<=n+1;i++)ar[i]=0;
    }
    
    void upload(int video) {
        ar[video]=1;
        while(ar[cnt+1]==1){
            cnt++;
        }
    }
    
    int longest() {
        return cnt;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */