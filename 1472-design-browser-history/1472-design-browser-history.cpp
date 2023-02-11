class BrowserHistory {
    vector<string> history;
    int index=0;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index+1;
    }
    
    void visit(string url) {
        index+=1;
        history.resize(index);
        history.push_back(url);
        
    }
    
    string back(int steps) {
        index=index-steps>0?index-steps:0;
        return history[index];
    }
    
    string forward(int steps) {
        index=index+steps<history.size()?index+steps:history.size()-1;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */