#pragma once

#define SIZE 11
#define INF 1e09

class Graph_hw
{
private:
	//матрица кратчайших расстояний
	int weights[SIZE][SIZE];
	//матрица смежности вершин
	int matrix[SIZE][SIZE];
	//массив вешин
	int vertexes[SIZE];
	//счетчик добавленных вершин
	int vertexCount;

	//вспомогательные функции
	bool edgeExist(int v1, int v2);
	bool vertexExist(int vnumber);


public:
	Graph_hw(); 

	//добавление и удаление вершин
	void addVertex(int vnumber);
	void addEdge(int v1, int v2, int weight);
	void delVertex(int vnumber);
	void delEdge(int v1, int v2);

	//заполнение матрицы кратчайших расстояний по Флойду
	void findMinDistanceFloyd();	

	//вывод в консоль матирцы кратчайших расстояний
	void printDistances();

	//вывод занкомцев через заданное количество рукопожатий
	void printFriendOnDistance(int n);
};