/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  let left = s.length - 1,
    right = s.length;
  let lastOne = "";
  while (left > 0) {
    if (s[left] === " ") {
      left--;
      continue;
    }

    right = left;

    while (s[left] !== " " && left !== -1) {
      left--;
    }

    return right - left;
  }
  return 0;
};

console.log(lengthOfLastWord("a"));
