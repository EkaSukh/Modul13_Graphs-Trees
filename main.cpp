#include "Graph_hw.h"
//#include "Tree.h"
//#include "BinaryTree.h"
#include <iostream>

int main()
{
	//создание графа с максимальным количеством вершин 11
	Graph_hw g;

	// ввод вершин, кторые есть имена персон
	g.addVertex(0);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addVertex(6);
	g.addVertex(7);
	g.addVertex(8);
	g.addVertex(9);
	g.addVertex(10);

	//эта вершина уже не добавится
	g.addVertex(11);

	//добавление ребер, все с весом один, как индикатор рукопожатия
	g.addEdge(0, 1, 1);
	g.addEdge(0, 2, 1);
	g.addEdge(0, 3, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 4, 1);

	g.addEdge(2, 3, 1);
	g.addEdge(2, 4, 1);
	g.addEdge(4, 3, 1);

	
	g.addEdge(4, 5, 1);
	g.addEdge(3, 6, 1);
	g.addEdge(5, 6, 1);

	g.addEdge(4, 8, 1);
	g.addEdge(8, 7, 1);
	g.addEdge(5, 7, 1);
	g.addEdge(7, 9, 1);
	g.addEdge(7, 10, 1);
	g.addEdge(10, 9, 1);
		
	//Расчет матрицы кратчайших путей по флойду
	g.findMinDistanceFloyd();

	//вывод знакомцев на расстоянии трех рукопожатий
	g.printFriendOnDistance(3);
	

	
	return 0;
}