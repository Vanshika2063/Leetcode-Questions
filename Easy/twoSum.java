import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class twoSum {
    public static void main(String[] args) {
        int[] arr= {2,7,11,15};
        int target= 17;
    }
    static int[] sum(int[] arr, int target){
		Map<Integer, Integer> numMap = new HashMap<>();
		for (int i = 0; i < arr.length; i++) {
            int complement = target - arr[i];
            if (numMap.containsKey(complement)) {
                return new int[] { numMap.get(complement), i };
            } else {
                numMap.put(arr[i], i);
            }
        }
        return new int[] {};
    }
}
