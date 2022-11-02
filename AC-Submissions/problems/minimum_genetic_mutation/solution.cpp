//copied//solve later
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        queue<string> q;
        unordered_set<string> visited; // set for having check that the mutation was visited or not
        q.push(start);
        int count = 0;
        
        while(!q.empty()) 
        {
            int n = q.size();
            while(n--) {
                string node = q.front();
                q.pop();
                
				// if we reach the end mutation then return count
                if(node == end) return count;
                
				// At each index we are checking the possible mutation for each char A, C, G, T 
                for(char ch : "ACGT") {
                    for(int i = 0; i < node.size(); i++) {
                        string adjNode = node;
                        adjNode[i] = ch;
						
						// if mutation is not present in the set and present in the bank vector
						// then push it in the queue and insert it in set
                        if(!visited.count(adjNode) && 
                          find(bank.begin(), bank.end(), adjNode) != bank.end()) 
                        {
                            q.push(adjNode);
                            visited.insert(adjNode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};