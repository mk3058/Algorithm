class RecentCounter {
public:
    /** 
        ping 요청이 와 
        그럼 현재 요청온 그 시간을 포함해서, 스택에서 하나씩 꺼내
        stack<int> 위에서 부터 하나씩 꺼내
        top - current > 3000
    */
    
    queue<int> requests;
    
    RecentCounter() {
    }
    
    int ping(int t) {
        
        requests.push(t);
        while (requests.front() + 3000 < t) {
            requests.pop();
        }
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */