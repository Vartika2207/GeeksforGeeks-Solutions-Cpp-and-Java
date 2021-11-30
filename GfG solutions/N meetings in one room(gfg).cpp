class Solution
{
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second)
           return a.first < b.first;
        return a.second < b.second;   
    }
    
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meet;
        for(int i=0; i<n; i++){
            meet.push_back({start[i], end[i]});
            //v.push_back(make_pair(end[i],start[i]))
        }
        
        //sort based upon endtime
        sort(meet.begin(), meet.end(), cmp);
        
        int count = 1;
        int endTime = meet[0].second;
        for(int i=1; i<n; i++){
            if(meet[i].first > endTime){
                endTime = meet[i].second;
                count++;
            }
            else{
                continue;
            }
        }
        return count;
    }
};