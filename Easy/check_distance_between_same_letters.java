class Solution {
    public boolean checkDistances(String s, int[] distance) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                if (i - map.get(c) - 1 != distance[c - 'a'])
                    return false;
            } else {
                map.put(c, i);
            }
        }
        return true;
    }
}
