public class skyline{
    // 218. The Skyline Problem
//     tc O(nlogn) sc O(n)
//     As we need the points of the skyline formed by the buldings, analyse what it is
//   the points which can be seen from top and its endpoint hasn't come
// So we will use priority queue for storing the max height so far
//     We will transform the buildings array according to our need
//     for starting index of the building as { building[0],-building[2]}
//    and ending index as  { building[0],building[2]}
// this is done just to differentiate starting and end indexes with their heights mentioned
//    Now, when we will see start index add the height of it in pq and at end index remove that particular end index's height
//     if the currmax is changed from the previous max then this is a skyline point and add it in the answer simply.
public List<List<Integer>> getSkyline(int[][] buildings) {
    int n = buildings.length,idx=0,prevMax=0;
    int[][] arrBuild = new int[2*n][2];
    PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->{
        return b-a;
    });
    
    List<List<Integer>> ans = new ArrayList<>();
    pq.add(0);
    for(int[] building:buildings){
        arrBuild[idx][0] = building[0];
        arrBuild[idx][1] = -building[2];
        idx++;
        arrBuild[idx][0] = building[1];
        arrBuild[idx][1] = building[2];
        idx++;
    }
    Arrays.sort(arrBuild,(a,b)->{
       return a[0]==b[0]?a[1]-b[1]:a[0]-b[0]; 
    });
    
    for(int[] arr:arrBuild){
        if(arr[1]<0){
            pq.add(-arr[1]);
        }
        else{
             pq.remove(arr[1]); 
        }
        int currMax = pq.peek();
        if(currMax!=prevMax){
            List<Integer> smallAns= new ArrayList<>();
            smallAns.add(arr[0]);
            smallAns.add(currMax);
            ans.add(smallAns);
            prevMax = pq.peek();
        }
    }
    return ans;
}
}