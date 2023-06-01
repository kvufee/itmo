import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt


# Read and preprocess data
data = pd.read_csv("Simple_pairwise-London_tube_map.txt", sep='\t', header = None)
data.rename(columns = {0:'from', 1:'to', 2:'remove'}, inplace = True)
data = data.drop('remove', axis=1)

# Make graph from given data
g = nx.Graph()
g = nx.from_pandas_edgelist(data, 'from', 'to')

# Draw graph
plt.figure(figsize=(30, 25))
nx.draw_kamada_kawai(g, with_labels = True, node_size = 200, font_size = 20)

# Additional tasks
amount_of_components = nx.number_connected_components(g)


counter = 0

degrees = pd.unique(list(g.degree))
test = []

for i in range(len(degrees)):
    if degrees[i][1] >= 3:
        counter += 1

diameter = nx.diameter(g)