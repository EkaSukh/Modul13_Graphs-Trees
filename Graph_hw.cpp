#include <iostream>
#include "Graph_hw.h"

Graph_hw::Graph_hw()
{
	//инициализация матрицы смежности нулями
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
}

void Graph_hw::addVertex(int vnumber)
{
	if (vertexCount < SIZE)
		vertexes[vertexCount++] = vnumber;
	else
		std::cout << "Graph already has " << SIZE << " vertexes\n";
}

void Graph_hw::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}

void Graph_hw::delVertex(int v)
{
	int foundIndex = -1;
	for (int i = 0; i < vertexCount; i++)
	{
		if (vertexes[i] == v)
			foundIndex = i;
	}
	for (int i = foundIndex; i < vertexCount - 1; i++)
		vertexes[i] = vertexes[i + 1];

	vertexCount--;

}

void Graph_hw::delEdge(int v1, int v2)
{
	matrix[v1][v2] = 0;
	matrix[v2][v1] = 0;

}

bool Graph_hw::edgeExist(int v1, int v2)
{
	return matrix[v1][v2] > 0;
}

bool Graph_hw::vertexExist(int vnumber)
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i] == vnumber)
			return true;
	return false;
}

void Graph_hw::findMinDistanceFloyd()
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
				weights[i][j] = 0;
			else
			{
				if (!edgeExist(i, j))
					weights[i][j] = INF;
				else
					weights[i][j] = matrix[i][j];
			}

		}

	}

	for (int k = 0; k < vertexCount; k++)
	{
		int ck = vertexes[k];
		for (int i = 0; i < vertexCount; i++)
		{
			if (i == k)
				continue;
			int ci = vertexes[i];
			for (int j = 0; j < vertexCount; j++)
			{
				if (j == k)
					continue;
				int cj = vertexes[j];
				if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
					weights[ci][cj] = weights[ci][ck] + weights[ck][cj];

			}
		}

	}

	printDistances();
}

	void Graph_hw::printDistances()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				std::cout << weights[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}

	void Graph_hw::printFriendOnDistance(int n)
	{std::cout << " through " << n << " handshakes:\n";
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
			{
				if(weights[i][j] == n)
				std::cout << i << " is friend to " << j << std::endl;
			}			
		}
	}