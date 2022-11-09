class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    
    StockSpanner() {}
    
    int next(int price) {
        int ans = 1;
        while(st.size() and st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        st.push(make_pair(price,ans));
        return ans;
    }
};