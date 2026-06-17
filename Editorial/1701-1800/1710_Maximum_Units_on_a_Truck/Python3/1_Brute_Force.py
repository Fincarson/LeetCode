class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        unitCount = 0
        remainingTruckSize = truckSize
        while remainingTruckSize > 0:
            maxUnitBoxIndex = self.findMaxUnitBox(boxTypes)
            if maxUnitBoxIndex == -1:  # all boxes are used
                break
            boxCount = min(remainingTruckSize, boxTypes[maxUnitBoxIndex][0])
            unitCount += boxCount * boxTypes[maxUnitBoxIndex][1]
            remainingTruckSize -= boxCount
            boxTypes[maxUnitBoxIndex][1] = -1  # mark box as used
        return unitCount

    def findMaxUnitBox(self, boxTypes):
        maxUnitBoxIndex = -1
        maxUnits = 0
        for i in range(len(boxTypes)):
            if boxTypes[i][1] > maxUnits:
                maxUnits = boxTypes[i][1]
                maxUnitBoxIndex = i
        return maxUnitBoxIndex
