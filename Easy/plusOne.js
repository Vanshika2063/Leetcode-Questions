/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits. */

/**
 * @param {number[]} digits
 * @return {number[]}
 */

var plusOne = (digits) => {
  for (let digit = digits.length - 1; 0 <= digit; digit--) {
    /* Time O(N) */
    const canCarry = digits[digit] === 9;
    if (canCarry) {
      digits[digit] = 0;
      continue;
    }

    digits[digit]++;

    return digits;
  }

  digits.unshift(1); /* Time O(N) | Space O(N) */

  return digits;
};
console.log(plusOne([1, 2, 3])); //returns [1,2,4]
/*Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]. */

console.log(plusOne([9])); //returns [1,0]
