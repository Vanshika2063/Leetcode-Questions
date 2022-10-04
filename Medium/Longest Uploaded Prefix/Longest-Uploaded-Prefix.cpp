class LUPrefix {
    set<int> s;
    int size;
public:
    LUPrefix(int n) {
        size=n;
        // insert all unprocessed videos, initially all (1 to n)
        for(int i=1;i<=n;i++)
            s.insert(i);
    }
    
    void upload(int video) {
        // delete the uploaded video from set
        s.erase(video);
    }
    
    int longest() {
        // now, if set is empty, it means all videos are uploaded. hence answer = size
        if(s.empty())
            return size;
        else{
            // otherwise, ans = the minimum element in set minus 1
            // this is because all elements lesser than it are already processed
            int f = *s.begin();
            return f-1;
        }
    }
};
