class Solution {
public List<List> combinationSum(int[] candidates, int target) 
{
  List<List<Integer>> ans = new ArrayList();

    findCombinations(candidates, 0,  target, ans, new ArrayList<>());
 
    return ans;
}

public void findCombinations(int[] candidates, int index, int target, List<List<Integer>> ans,  List<Integer> current)
{
    if(target == 0)
    {
        ans.add(new ArrayList<Integer>(current));
        return;
    }
    
    for(int i = index; i< candidates.length ; i++)
    {
        if(candidates[i] <= target )
        {   
            current.add(candidates[i]);
            findCombinations(candidates,i,target-candidates[i],ans,current);
            current.remove(new Integer(candidates[i]));
        }
    }
}
}
