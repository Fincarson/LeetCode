var lengthOfLastWord = function (s) {
    s = s.trim(); // trim the trailing spaces in the string
    return s.length - s.lastIndexOf(" ") - 1;
};
