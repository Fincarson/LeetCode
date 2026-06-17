class Solution:
    def removeSubfolders(self, folder):
        # Sort the folders alphabetically
        folder.sort()

        # Initialize the result list and add the first folder
        result = [folder[0]]

        # Iterate through each folder and check if it's a sub-folder of the last added folder in the result
        for i in range(1, len(folder)):
            last_folder = result[-1]
            last_folder += "/"

            # Check if the current folder starts with the last added folder path
            if not folder[i].startswith(last_folder):
                result.append(folder[i])

        # Return the result containing only non-sub-folders
        return result
