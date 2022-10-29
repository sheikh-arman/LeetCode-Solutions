class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>V;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                int siz=queries[i].size();
                if(dictionary[j].size()!=siz)continue;
                for(int k=0;k<siz;k++){
                    if(queries[i][k]!=dictionary[j][k]){
                        cnt++;
                    }
                    if(cnt>2)break;
                }
                if(cnt<=2){
                    V.push_back(queries[i]);break;
                }
            }
        }
        return V;
    }
};
//["tsl","sri","yyy","rbc","dda","qus","hyb","ilu","ahd"]
//["uyj","bug","dba","xbe","blu","wuo","tsf","tga"]