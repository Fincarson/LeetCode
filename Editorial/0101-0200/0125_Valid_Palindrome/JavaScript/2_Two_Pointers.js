var isPalindrome = function (s) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        while (i < j && !isLetterOrDigit(s[i])) {
            i++;
        }
        while (i < j && !isLetterOrDigit(s[j])) {
            j--;
        }
        if ((s[i] + "").toLowerCase() !== (s[j] + "").toLowerCase())
            return false;
        i++;
        j--;
    }
    return true;
};
function isLetterOrDigit(character) {
    const charCode = character.charCodeAt();
    return (
        (charCode >= "a".charCodeAt() && charCode <= "z".charCodeAt()) ||
        (charCode >= "A".charCodeAt() && charCode <= "Z".charCodeAt()) ||
        (charCode >= "0".charCodeAt() && charCode <= "9".charCodeAt())
    );
}
