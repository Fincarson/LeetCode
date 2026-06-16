var plusOne = function (digits) {
    let n = digits.length;
    //move along the input array starting from the end
    for (let i = n - 1; i >= 0; --i) {
        //set all the nines at the end of array to zeros
        if (digits[i] == 9) {
            digits[i] = 0;
        }
        //here we have the rightmost not-nine
        else {
            //Increase this rightmost not-nine by 1
            digits[i]++;
            //and the job is done
            return digits;
        }
    }
    //We're here because all the digits are nines
    digits.unshift(1);
    return digits;
};
