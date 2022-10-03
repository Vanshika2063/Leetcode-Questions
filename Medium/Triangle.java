import java.util.List;
public class Triangle {

    /**
     * Given a triangle array, return the minimum path sum from top to bottom.
     * Time Complexity: O(n ^ 2), where n is the number of rows of the triangle.
     * Space Complexity: O(1).
     *
     * @param triangle A list of lists of integers from an triangle array.
     * @return An integer of the minimal path sum from top to bottom of the given triangle array.
     */
    public int getMinimumTotalWithBottomUpDynamicProgrammingV2(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(
                        triangle.get(i + 1).get(j),
                        triangle.get(i + 1).get(j + 1)
                ));
            }
        }
        return triangle.get(0).get(0);
    }
}
