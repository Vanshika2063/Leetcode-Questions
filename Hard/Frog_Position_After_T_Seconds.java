class pair{
    int node;
    double prob;
    public pair(int node1,double pair1){
        node=node1;
        prob=pair1;
    }
}
class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        //creating the adjacency list
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0;i<=n;i++){
            adj.add(new ArrayList<>());
        }
        //looping through edges to add in adj list
        for(int p[]:edges){
            int u=p[0];
            int v=p[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        //running bfs
        Queue<pair> q=new LinkedList<>();
        q.add(new pair(1,1.0));
        //creating vis array initialize false
        boolean vis[]=new boolean[n+1];
        //initially frog is at 1 so vis[1] will be true and prob is also .0
        vis[1]=true;int lvl=-1;
        while(!q.isEmpty()){
            int size=q.size();
            lvl++;
            while(size-->0){
                
                pair it=q.poll();
                int node=it.node;
                double prob=it.prob;
                
                //if we reach the target condition we return prob
                if(node==target && lvl==t)return prob;
                if(lvl>t)return 0.0;
                int y=0;
                
                for(int it1:adj.get(node)){
                    if(!vis[it1])y++;
                }
                
                boolean flag=false;
                //calculating prob
                for(int it1:adj.get(node)){
                    if(!vis[it1]){
                    q.add(new pair(it1,prob/y));
                    vis[it1]=true;
                    flag=true;
                    }
                }
                if(flag==false)
                {
                    q.add(new pair(node,prob));
                }
            }
        }
        return 1.0;
    }
}