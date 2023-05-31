class UndergroundSystem {
public:
    map<int,pair<int,string>>m;
    map<string,pair<int,int>>p;
    UndergroundSystem() {
        m.clear();
        p.clear();
    }
    
    void checkIn(int id, string s, int t) {
       m[id] = {t,s};
    }
    
    void checkOut(int id, string s, int t) {
        string d = m[id].second + " " + s;
        auto &i = p[d];
        i.first += t - m[id].first;
        i.second++;
    }
    
    double getAverageTime(string s, string e) {
        string route = s +" " + e;
        return (double)p[route].first/p[route].second;
    }
};