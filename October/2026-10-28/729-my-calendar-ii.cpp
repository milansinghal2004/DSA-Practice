729-my-calendar-ii.cpp;leetcode;help

class MyCalendarTwo {
public:
    vector<pair<int, int>> events;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (auto event : events) {
            if (startTime < event.second &&
                endTime > event.first) {
                return false;
            }
        }

        events.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */