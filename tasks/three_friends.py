n = int(input())

firstSt = input().split()
secondSt = input().split()
thirdSt = input().split()

fGrade, sGrade, tGrade = 0


for i in range(n):
    if firstSt[i] not in secondSt and firstSt[i] not in thirdSt:
        fGrade += 3

    elif firstSt[i] in secondSt and firstSt[i] not in thirdSt:
        fGrade += 1
        sGrade += 1

    elif firstSt[i] not in secondSt and firstSt[i] in thirdSt:
        fGrade+=1
        tGrade+=1
        

    if secondSt[i] not in firstSt and secondSt[i] not in thirdSt:
        sGrade += 3

    elif secondSt[i] in thirdSt and secondSt[i] not in firstSt:
        sGrade += 1
        tGrade += 1

    if thirdSt[i] not in firstSt and thirdSt[i] not in secondSt:
        tGrade += 3


print(fGrade, sGrade, tGrade)