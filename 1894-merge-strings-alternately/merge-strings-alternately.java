class Solution {
    public String mergeAlternately(String word2, String word3) {
        StringBuilder merged = new StringBuilder();
        int maxLen = Math.max(word2.length(), word3.length());
        
        for (int i = 0; i < maxLen; i++) {
            if (i < word2.length()) {
                merged.append(word2.charAt(i));
            }
            if (i < word3.length()) {
                merged.append(word3.charAt(i));
            }
        }
        
        return merged.toString();
    }
}