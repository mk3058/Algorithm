/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    var idx = 0;
    var res = "";
    
    while (idx < word1.length && idx < word2.length) {
        res += word1.charAt(idx);
        res += word2.charAt(idx);
        idx++;
    }
    while(idx < word1.length) {
        res += word1.charAt(idx++);
    }
    while(idx < word2.length) {
        res += word2.charAt(idx++);
    }
    return res
};