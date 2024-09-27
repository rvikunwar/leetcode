// // My Calendar II.cpp

// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

// Implement the MyCalendarTwo class:

// MyCalendarTwo() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.


class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {
        
    }
    
    // sweep line algorithm
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int bookings = 0;
        for(auto & slot: mp) {
            bookings += slot.second;
            if(bookings == 3) {
                mp[start]--;
                mp[end]++;

                if(mp[start] == 0) mp.erase(start);
                if(mp[end] == 0) mp.erase(end);
                return false;
            }
            if(slot.first > end) break;
        }   
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */