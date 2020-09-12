class MyCalendarTwo {
public:
     map<int,int> info;   
    MyCalendarTwo() {
    map<int,int> info;    
    }
    
    bool book(int start, int end) {
        info[start]++;
        info[end]--;
        int booking =0;
        for(auto it = info.begin();it!=info.end();it++)
        {
            booking+=it->second;
            if(booking==3)
            {
                info[start]--;
                info[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
