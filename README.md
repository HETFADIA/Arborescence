# arborescence
Arborescence code


## Description

This program finds the minimum spanning arborescence (directed MST) for each test case.
It reads the graph, removes edges into the root, and picks the cheapest incoming edge for each node.
If a cycle is found, it contracts it and repeats until no cycles remain.
Then it expands the final edges to form the minimum-cost tree rooted at s.
Finally, it prints the total cost, each node’s distance from the root, and its parent.
If any edge has a negative weight, it prints -1 for that test.
At the end, it shows how long the program took to run.
