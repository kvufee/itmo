import 

maxImpact = 0
gravityForce = 0
deformationDistance = 0.5

def isLethal(isBelted : bool, isAirbag : bool, carMass : int, speed : float):
    lethal = False
    throughWindow = False
    maxForce = 0
    
    if (isBelted == False and isAirbag == False):
        maxForce = 28
        throughWindow = True
    elif (isBelted == False and isAirbag == True):
        maxForce = 33
        throughWindow = True
    elif (isBelted == True and isAirbag == False):
        maxForce = 36
        throughWindow = False
    elif (isBelted == True and isAirbag == True):
        maxForce = 40
        throughWindow = False
        
    maxImpact = (0.5 * carMass * (speed / 3.6)**2) / deformationDistance
    gravityForce = maxImpact / (carMass * 9.8)
    
    if gravityForce > maxForce:
        lethal = True
    
    return lethal, throughWindow