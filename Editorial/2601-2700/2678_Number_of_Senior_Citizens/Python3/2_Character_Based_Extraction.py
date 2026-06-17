class Solution:
    def countSeniors(self, details: List[str]) -> int:
        senior_count = 0

        # Iterate through each passenger's details
        for passenger_info in details:
            # Extract the digits of age
            age_tens = ord(passenger_info[11]) - ord("0")
            age_ones = ord(passenger_info[12]) - ord("0")

            # Calculate the full age
            age = age_tens * 10 + age_ones

            # Check if the passenger is a senior (strictly over 60 years old)
            if age > 60:
                senior_count += 1

        return senior_count
