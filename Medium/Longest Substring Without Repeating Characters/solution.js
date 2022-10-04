/**
 * Longest Substring Without Repeating Characters
 */

let lengthOfLongestSubstrings = (str) => {
  let subString = [];
  let length = 0;
  for (let i = 0; i < str.length; i++) {
    if (subString.includes(str[i]))
      subString.splice(0, subString.indexOf(str[i]) + 1);
    subString.push(str[i]);
    length = subString.length > length ? subString.length : length;
  }

  return length;
};

let s = "abcdeeeeee";

let res = lengthOfLongestSubstring(s);
console.log(res); // res: 5

/**
 * Input: s = "abcdeeeeee"
 * Output: 5
 * Explanation: The answer is "abcde", with the length of 1.
 */

