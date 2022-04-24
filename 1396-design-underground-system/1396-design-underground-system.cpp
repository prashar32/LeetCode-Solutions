class UndergroundSystem {
public:
    map<int,pair<string,int>>IN;
    map<pair<string,string>,pair<int,int>>OUT;
    UndergroundSystem() {
        IN.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        IN[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = IN[id];
        auto &[totalTime, times] = OUT[make_pair(startStation, stationName)];
        totalTime += (t - startTime);
        times += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [totalTime, times] = OUT[make_pair(startStation, endStation)]; 
        return (double)totalTime/times;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */