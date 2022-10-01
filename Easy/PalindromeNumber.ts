/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.
*/


function isPalindrome(x: number): boolean {
    if (x < 0)return false;
    return x.toString() == x.toString().split("").reverse().join("")
};