//? Interleave The First Half Of The Queue With The Second Half

void interLeaveQueue(queue < int > & q) {
    queue<int> q2;
    int n = q.size()/2;
    for(int i=0;i<n;i++){
        q2.push(q.front());
        q.pop();
    }
    while(!q2.empty()){
                q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}