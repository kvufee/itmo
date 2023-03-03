import matplotlib.pyplot as plt
import numpy as np


print('Input a vector')
inputVector = int(input())

vector = list(map(int, str(inputVector)))
vector.reverse()

vector = np.array(vector)
vector = vector.astype(np.int32)

resultValues = np.array([])

for item in range(len(vector)):
    resultValues = np.append(resultValues, vector[item] * (2 ** item))


# first plot
x = resultValues

plt.hist(x)

plt.show()

#second plot
x = resultValues

plt.plot(x)

plt.show()