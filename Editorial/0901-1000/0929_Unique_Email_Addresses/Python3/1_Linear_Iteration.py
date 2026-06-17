class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        # Hash set to store all the unique emails.
        uniqueEmails = set()

        # Iterate over each character in email.
        for email in emails:
            cleanMail = []

            # Iterate over each character in email.
            for currChar in email:
                # Stop adding characters to localName.
                if currChar == '+' or currChar == '@':
                    break

                # Add this character if not '.'.
                if currChar != '.':
                    cleanMail.append(currChar)

            # Compute domain name (substring from end to '@').
            domainName = []
            for currChar in reversed(email):
                domainName.append(currChar)
                if currChar == '@':
                    break

            # Reverse domain name and append to local name.
            domainName = ''.join(domainName[::-1])
            cleanMail = ''.join(cleanMail)
            uniqueEmails.add(cleanMail + domainName)

        return len(uniqueEmails)
