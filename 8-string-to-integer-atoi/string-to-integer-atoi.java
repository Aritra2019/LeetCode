class Solution {
    public int myAtoi(String s) {
          s = s.trim();  // remove leading/trailing spaces
        if (s.isEmpty()) return 0;

        int i = 0;
        int sign = 1;
        long result = 0;

        // Handle sign
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }

        // Convert digits
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            result = result * 10 + (s.charAt(i) - '0');

            // Clamp to int range
            if (result * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (result * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;

            i++;
        }

        return (int)(result * sign);
    }
}