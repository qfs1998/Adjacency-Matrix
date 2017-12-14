#pragma once
//ͼ���ڽӾ��󴢴�Adjacency Matrix
#include <iostream>
using namespace std;
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
using VertexType = char;
typedef enum { DG, DN, UDG, UDN }GraphKind;
typedef struct
{
	VertexType vex[MAX_VERTEX_NUM];//��������
	int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
	int vexnum, arcnum;//������Ŀ������Ŀ
	GraphKind kind;
}MGraph;

int LocateVex(const MGraph&G,const char&vex)
{
	for (int i = 0; i < G.vexnum; ++i)
		if (vex == G.vex[i])
			return i;
}

void Creat_UDG(MGraph&G)
{
	cout << "Input vexnum and arcnum\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "Input the value of vertex\n";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vex[i];
	for (int i = 0; i < G.vexnum; ++i)//Initialize the Adjacency Matrix
		for (int j = 0; j < G.vexnum; ++j)
			G.arc[i][j] = 0;
	cout << "Input the value of arc,please give the vertexs of the arc to find the arc\n";
	char v1,v2;
	for (int k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arc[i][j] = 1;
		G.arc[j][i] = G.arc[i][j];
	}
	return;
}

void Creat_DG(MGraph&G)
{
	cout << "Input vexnum and arcnum\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "Input the value of vertex\n";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vex[i];
	for (int i = 0; i < G.vexnum; ++i)//Initialize the Adjacency Matrix
		for (int j = 0; j < G.vexnum; ++j)
			G.arc[i][j] = 0;
	cout << "Input the value of arc,please give the vertexs of the arc to find the arc\n";
	char v1, v2;
	for (int k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arc[i][j] = 1;
	}
	return;
}

void Print_Graph_info(const MGraph&G)
{
	switch(G.kind)
	{
	case UDG:
			cout << "������ " << G.vexnum << " ���� " << G.arcnum << endl;
			for (int i = 0; i < G.vexnum; ++i)
			{
				int d = 0;
				for (int j = 0; j < G.vexnum; ++j)
					d += G.arc[i][j];
				cout << "����" << G.vex[i] << "����Ϊ" << d<<endl;
			}
			for (int i = 0; i < G.vexnum; ++i)
			{
				for (int j = 0; j < G.vexnum; ++j)
				{
					cout << G.arc[i][j] << ' ';
				}
				cout << endl;
			}
			break;
	case DG:
		cout << "������ " << G.vexnum << " ���� " << G.arcnum << endl;
		for (int i = 0; i < G.vexnum; ++i)
		{
			int od = 0,id=0;
			for (int j = 0; j < G.vexnum; ++j)
				od += G.arc[i][j];
			for (int j = 0; j < G.vexnum; ++j)
				id += G.arc[j][i];
			cout << "���� " << G.vex[i] << " ����Ϊ " << od<<" ���Ϊ"<<id<<" ����Ϊ "<<od+id<<endl;
		}
		for (int i = 0; i < G.vexnum; ++i)
		{
			for (int j = 0; j < G.vexnum; ++j)
			{
				cout << G.arc[i][j] << ' ';
			}
			cout << endl;
		}
		break;
	}
	return;
}

void CreatGraph(MGraph&G)
{
	cout << "����ͼ�����ͣ�0-DG,1-DN,2-UDG,3-UDN\n";
	int i;
	cin >> i;
	G.kind = (GraphKind)i;
	switch (G.kind)
	{
	case DG:
		Creat_DG(G);
		break;
	case UDG:
		Creat_UDG(G);
		break;
	}
	return;

}