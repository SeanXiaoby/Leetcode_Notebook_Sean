/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  const isCounted = (c) => c.match(/^[a-zA-Z0-9]+$/) !== null;

  const str = Array.from(s.toLowerCase()).filter(
    (c) => c.match(/^[a-zA-Z0-9]+$/) !== null
  );

  for (let i = 0; i < Math.floor(str.length / 2); i++) {
    if (str[i] !== str[str.length - 1 - i]) {
      return false;
    }
  }

  return true;
};

console.log(isPalindrome(",'6``c4i,::,i4ckk6',"));
