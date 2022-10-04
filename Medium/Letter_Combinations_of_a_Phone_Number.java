public static List<String> letterCombinations_4Loops(String digits) {
    List<String> ans = new ArrayList<>();
    if (digits == null || digits.length() == 0) {
        return ans;
    }

    String[] letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = digits.length();
    int[] digitsArr = new int[len];
    for (int i = 0; i < len; i++) {
        digitsArr[i] = digits.charAt(i) - '0';
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < len; i++) {
        sb.append("a");
    }

    for (int i = 0; i < letters[digitsArr[0] - 2].length(); i++) {
        sb.replace(0, 1, letters[digitsArr[0] - 2].charAt(i) + "");
        if (len == 1) {
            ans.add(sb.substring(0, 1));
        }

        for (int j = 0; len >= 2 && j < letters[digitsArr[1] - 2].length(); j++) {
            sb.replace(1, 2, letters[digitsArr[1] - 2].charAt(j) + "");
            if (len == 2) {
                ans.add(sb.toString());
            }

            for (int k = 0; len >= 3 && k < letters[digitsArr[2] - 2].length(); k++) {
                sb.replace(2, 3, letters[digitsArr[2] - 2].charAt(k) + "");
                if (len == 3) {
                    ans.add(sb.toString());
                }

                for (int l = 0; len >= 4 && l < letters[digitsArr[3] - 2].length(); l++) {
                    sb.replace(3, 4, letters[digitsArr[3] - 2].charAt(l) + "");
                    ans.add(sb.toString());
                }
            }
        }
    }

    return ans;
}
