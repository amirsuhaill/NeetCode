class TimeEntry{
public:
    string val;
    int time;
    TimeEntry(string val,int time){
        this->val = val;
        this->time = time;
    }
};

class TimeMap {
private:
    unordered_map<string,vector<TimeEntry>> mpp;
public:

    TimeMap() {     

    }
    
    void set(string key, string value, int timestamp) {
        TimeEntry entry(value,timestamp);
        mpp[key].push_back(entry);
    }
    
    string get(string key, int timestamp) {
        
        vector<TimeEntry> entries = mpp[key];

        int low = 0, high = entries.size()-1;
        int ansIdx = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(entries[mid].time <= timestamp){
                ansIdx = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return (ansIdx == -1) ? "" : entries[ansIdx].val; 
    }
};
