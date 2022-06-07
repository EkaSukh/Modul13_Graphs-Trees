#pragma once

#define SIZE 11
#define INF 1e09

class Graph_hw
{
private:
	//������� ���������� ����������
	int weights[SIZE][SIZE];
	//������� ��������� ������
	int matrix[SIZE][SIZE];
	//������ �����
	int vertexes[SIZE];
	//������� ����������� ������
	int vertexCount;

	//��������������� �������
	bool edgeExist(int v1, int v2);
	bool vertexExist(int vnumber);


public:
	Graph_hw(); 

	//���������� � �������� ������
	void addVertex(int vnumber);
	void addEdge(int v1, int v2, int weight);
	void delVertex(int vnumber);
	void delEdge(int v1, int v2);

	//���������� ������� ���������� ���������� �� ������
	void findMinDistanceFloyd();	

	//����� � ������� ������� ���������� ����������
	void printDistances();

	//����� ��������� ����� �������� ���������� �����������
	void printFriendOnDistance(int n);
};