#include <iostream>
int totalLength = 0;

int graph[6][6] = {
					{-1, 3 ,-1 , 6 ,-1 , 3},
					{ 3,-1 , 2 , 5 , 5 , 1},
					{-1, 2 ,-1 , 1 , 9 , 6},
					{ 6, 5 , 1 ,-1 , 2 , 4},
					{-1, 5 , 9 , 2 ,-1 , 1},
					{ 3, 1 , 6 , 4 , 1 ,-1}
};

bool checkRunning(int nodeList[6]) {
	for (int i = 0; i < 6; i++)
	{
		if (nodeList[i] == -1)
			return true;
	}
	return false;
}

void InitArray(int nodeList[6]) {
	for (int i = 0; i < 6; i++)
	{
		nodeList[i] = -1;
	}
}


bool CheckIfWayAlreadyInList(int start, int end, int nodeList[6]) {
	for (int i = 1; i < 6; i++)
	{
		if (nodeList[i] == start && nodeList[i - 1] == end ||
			nodeList[i] == end   && nodeList[i - 1] == start) {
			return true;
		}
	}
	return false;
}

void addNode(int index, int nodeList[6]) {
	for (int i = 0; i < 6; i++)
	{
		if (nodeList[i] == -1) {
			nodeList[i] = index;
			return;
		}
	}
}


int getShortestPath(int nodeList[6]) {
	int value = 9999999;
	int start = -1;
	int end = -1;
	for (int i = 0; i < 6; i++)
	{
		if (nodeList[i] == -1) {
			continue;
		}

		for (int j = 0; j < 6; j++) {
			if (graph[nodeList[i]][j] == -1) {
				continue;
			}

			if (CheckIfWayAlreadyInList(nodeList[i], j, nodeList)) {
				continue;
			}
			else if (graph[nodeList[i]][j] < value) {
				value = graph[nodeList[i]][j];
				end = j;
				start = nodeList[i];
			}
		}
	}
	std::cout << value << "\t\t" << start << "\t\t" << end << std::endl;
	totalLength += value;
	return end;
}

void DispayPath(int nodeList[6]) {
	for (int i = 0; i < 6; i++)
	{
		std::cout << " " << nodeList[i] << " ";
	}
	std::cout << std::endl;
}

int getLength(int nodeList[6]) {
	int totalLength = 0;
	for (int i = 1; i < 6; i++)
	{
		if (nodeList[i] == -1) {
			return totalLength;
		}

		totalLength += graph[nodeList[i - 1]][nodeList[i]];
	}
	return totalLength;
}

int main() {
	int nodeList[6];
	InitArray(nodeList);

	addNode(0, nodeList);
	std::cout << "Weglänge\tStart\t\tZiel" << std::endl;
	while (checkRunning(nodeList)) {
		int newNode = getShortestPath(nodeList);
		addNode(newNode, nodeList);
	}
	std::cout << std::endl;
	DispayPath(nodeList);
	std::cout << "Total Length " << totalLength << std::endl;
	return 0;
}