class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto it:tokens){
           if(it == "+"){
               long long a = st.top();
               st.pop();
               long long b = st.top();
               st.pop();
               long long c = b+a;
               st.push(c);
           }
           else if(it == "-"){
               long long a = st.top();
               st.pop();
               long long b = st.top();
               st.pop();
               long long c = b-a;
               st.push(c);
           }
           else if(it == "/"){
               long long a = st.top();
               st.pop();
               long long b = st.top();
               st.pop();
               long long c = b/a;
               st.push(c);
           }
           else if(it == "*"){
               long long a = st.top();
               st.pop();
               long long b = st.top();
               st.pop();
               long long c = b*a;
               st.push(c);
           }

           else st.push(stoi(it));
        }

        return st.top();
    }
};