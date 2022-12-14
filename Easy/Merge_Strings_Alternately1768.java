// 1768. Merge Strings Alternately
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.

public class Leetcode1768 {
    public static void main(String[] args) {
        String w1="abc";
        String w2="pqr";
        System.out.println(merge(w1,w2));
    }

    static String merge(String w1,String w2){
        String str="";
        int l=Math.min(w1.length(),w2.length());
        StringBuilder s=new StringBuilder();
        for (int i = 0; i < l; i++) {
            s.append(w1.charAt(i));
            s.append(w2.charAt(i));
        }
        if(w1.length()>w2.length()){
            str=w1;
        }
        else{
            str=w2;
        }
        for (int i = l; i <str.length() ; i++) {
            s.append(str.charAt(i));
        }
        return (s.toString());
    }
}