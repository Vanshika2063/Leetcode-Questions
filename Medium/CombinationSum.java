<<<<<<< HEAD
//                https://leetcode.com/problems/combination-sum/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum {
    public static void main(String[] args) {
        int[] candidates = {2,3,6,7};
        List<List<Integer>> sum = combinationSum(candidates, 7);
        System.out.println(sum);
    }
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombination(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
    public static void findCombination(int index, int[] arr, int target, List<List<Integer>> ans, List<Integer> ds){
        if(index == arr.length){
            if(target == 0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        if(arr[index] <= target){
            ds.add(arr[index]);
            findCombination(index, arr, target - arr[index], ans, ds);
            ds.remove(ds.size()-1);
        }
        findCombination(index+1, arr, target, ans, ds);
    }
}
=======
//                https://leetcode.com/problems/combination-sum/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum {
    public static void main(String[] args) {
        int[] candidates = {2,3,6,7};
        List<List<Integer>> sum = combinationSum(candidates, 7);
        System.out.println(sum);
    }
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombination(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
    public static void findCombination(int index, int[] arr, int target, List<List<Integer>> ans, List<Integer> ds){
        if(index == arr.length){
            if(target == 0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        if(arr[index] <= target){
            ds.add(arr[index]);
            findCombination(index, arr, target - arr[index], ans, ds);
            ds.remove(ds.size()-1);
        }
        findCombination(index+1, arr, target, ans, ds);
    }
}
>>>>>>> 67aafb10a70e470ee512334062930bef20542fa0
