class MedianFinder {
    priority_queue<double,vector<double>,greater<double>> minpq;
    priority_queue<double> maxpq;
public:
    MedianFinder() {
        minpq={};
        maxpq={};
    }
    
    void addNum(int num) {
        if(maxpq.size()==0)
        {
            maxpq.push(num);
        }
        
        else if(num<maxpq.top())
        {
            maxpq.push(num);
            if(maxpq.size()==minpq.size()+2)
            {
                minpq.push(maxpq.top());
                maxpq.pop();
            }
        }
        else
        {
            minpq.push(num);
            if(minpq.size()>maxpq.size())
            {
                maxpq.push(minpq.top());
                minpq.pop();
            }
        }        
        
    }
    
    double findMedian() {
        if(minpq.size()==maxpq.size())
        {
            
            double a=maxpq.size()==0?0:maxpq.top();
            double b=minpq.size()==0?0:minpq.top();
            return (a+b)/2;
        }
        else
        {
            return maxpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */