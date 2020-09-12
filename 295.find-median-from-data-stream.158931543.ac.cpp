

class MedianFinder {
    struct compare{
      bool operator()(int a ,int b)
      {
          return a>b;
      }
    };
    priority_queue<int> lowers;
    priority_queue<int,vector<int>,compare> highers;
public:
    
       
    
    /** initialize your data structure here. */
   /*
    MedianFinder() {
        //maxheap for lower range
      priority_queue<int> *lowers= new priority_queue<int>;
        //minheap for higher range
     priority_queue<int,vector<int>,compare> *highers = new  priority_queue<int,vector<int>,compare>;
        
        
    }
    */
    
    
    void addNum(int num) {
        //cout<<"enerrr";
        if(lowers.size()==0||num<lowers.top())lowers.push(num);
        else highers.push(num);
        int a = highers.size();
        int b = lowers.size();
      //  cout<<"ffffff"<<lowers.size()<<" "<<highers.size()<<(a-b)<<" "<<"lll";
        if(b-a>=2)
        {
            //cout<<"innnn";
            highers.push(lowers.top());
            lowers.pop();
        }
        else if(a-b>=2)
        {
            //cout<<"hhhhh";
            lowers.push(highers.top());
            highers.pop();
        }
        //cout<<"yyyy";
    }
    
    double findMedian() {
        
       
        if(lowers.size()==highers.size())
        {
           
            return (double)(lowers.top()+highers.top())/2;
            
        }
        else if(lowers.size()>highers.size())return lowers.top();
        else return highers.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
