function isPalindrome(s: string) {
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        while (i < j && !isLetterOrDigit(s.charAt(i))) {
            i++;
        }
        while (i < j && !isLetterOrDigit(s.charAt(j))) {
            j--;
        }
        if (
            (s.charAt(i) + "").toLowerCase() !==
            (s.charAt(j) + "").toLowerCase()
        )
            return false;
        i++;
        j--;
    }
    return true;
}
function isLetterOrDigit(character: string) {
    const charCode = character.charCodeAt(0);
    return (
        (charCode >= "a".charCodeAt(0) && charCode <= "z".charCodeAt(0)) ||
        (charCode >= "A".charCodeAt(0) && charCode <= "Z".charCodeAt(0)) ||
        (charCode >= "0".charCodeAt(0) && charCode <= "9".charCodeAt(0))
    );
}
