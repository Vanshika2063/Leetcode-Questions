class MedianFinder {

    PriorityQueue<Integer> low =  new PriorityQueue<Integer>((a,b) -> (b-a));
    PriorityQueue<Integer> hi =  new PriorityQueue<Integer>();
    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        low.offer(num);
        
        hi.offer(low.poll());
        
        if(low.size() < hi.size())
        {
            low.offer(hi.poll());
        }
        
    }
    
    public double findMedian() {
        
        return low.size() > hi.size() ? low.peek() : (low.peek() + hi.peek())/2.0; 

    }
}
