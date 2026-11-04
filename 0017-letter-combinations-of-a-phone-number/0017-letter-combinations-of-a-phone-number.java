class Solution {
    Map<Integer, String> map = new HashMap<>();

    private void backtrack(String digits, int index, StringBuilder sb, List<String> res) {
        if (index == digits.length()) {
            res.add(sb.toString());
            return;
        }
        int digit = digits.charAt(index) - '0';
        String letters = map.get(digit);
        for (char c : letters.toCharArray()) {
            sb.append(c);
            backtrack(digits, index + 1, sb, res);
            sb.deleteCharAt(sb.length() - 1); // undo
        }
    }
    public List<String> letterCombinations(String digits) {
        map.put(2, "abc");  map.put(3, "def");
        map.put(4, "ghi");  map.put(5, "jkl");
        map.put(6, "mno");  map.put(7, "pqrs");
        map.put(8, "tuv");  map.put(9, "wxyz");    
        List<String> res=new ArrayList<>();
        backtrack(digits,0,new StringBuilder(),res);
        return res;
    }
}