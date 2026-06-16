let numUniqueEmails = function (emails) {
    // hash set to store all the unique emails
    let uniqueEmails = new Set();

    emails.forEach((email) => {
        // split into two parts local and domain
        let parts = email.split("@");

        // split local by '+'
        let local = parts[0].split("+");

        // remove all '.', and concatenate '@' and append domain
        uniqueEmails.add(local[0].replaceAll(".", "") + "@" + parts[1]);
    });

    return uniqueEmails.size;
};
