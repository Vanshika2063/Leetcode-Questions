class Solution {
    public int reverse(int x) {
        StringBuilder  sb= new StringBuilder();
        boolean isNegative=false;
        if(x<0)isNegative=true;
        x=Math.abs(x);
        if(x<0)return 0;
        sb.append(x);
        StringBuilder ans=sb.reverse();
            try {
                if(isNegative)return -1*Integer.parseInt(ans.toString());
                else return Integer.parseInt(ans.toString());
            
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}