class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList1) {
        Set<String> wordList = new HashSet<>();
        for(int i =0; i< wordList1.size(); i++)
            wordList.add(wordList1.get(i));
        if(!wordList.contains(endWord))
            return 0;
        Queue<String> q = new LinkedList<>();
        wordList.add(endWord);
        
        q.offer(beginWord);
        int level =0;
        
        while(!q.isEmpty())
            {
            level++;
            int size = q.size();
            
            for(int i = 0; i < size; i++)
                {
                
                String curr = q.poll();
                
                for( int j = 0; j < curr.length(); j++)
                    {
                    char c[] = curr.toCharArray();
                    for(char x ='a'; x<='z'; x++)
                        {
                    c[j]  =x;
                        
                        String temp = String.valueOf(c);
                        if(temp.equals(endWord))
                            return level+1;
                        if(curr!= temp && wordList.contains(temp))
                            {
                            q.add(temp);
                            wordList.remove(temp);
                            
                            }
                        }
                        
                    }
                
                }
            
            }
        
        return 0;
        
    }
}
