#pragma once
#include<iostream>
#define MAX_VERTEX_NUM 20
typedef char VertexType;
using namespace std;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode * nextarc;
}ArcNode;
typedef struct
{
	VertexType data;
	ArcNode * firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int LocateVex(const ALGraph&G, const VertexType&v)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (v == G.vertices[i].data)
			return i;
	}
}
void CreatDG(ALGraph&G)
{
	cout << "�����붥����Ŀ�ͱ���\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "�����붥���ֵ\n";
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	VertexType v1, v2;
	cout << "������ߵ���Ϣ������ӻ�β����ͷ�Ľڵ㣩\n";
	for (int k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
	}
	return;
}
int Indegree(ALGraph&G, const int &k)
{
	int indegree = 0;
	VertexType t = G.vertices[k].data;
	for (int i = 0; i < G.vexnum; ++i)
	{
		ArcNode* p = G.vertices[i].firstarc;
		while (p)
		{
			if (t == G.vertices[p->adjvex].data)
				++indegree;
			p = p->nextarc;
		}
	}
	return indegree;
}
void Print_ALGragh(ALGraph&G)
{
	cout << "����Ϊ:";
	for (int i = 0; i < G.vexnum; ++i)
		cout << G.vertices[i].data << ' ';
	cout << "����Ϊ:" << G.arcnum;
	cout << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cout << "�ڵ�" << G.vertices[i].data << "���ڽӵ���";
		ArcNode *p = G.vertices[i].firstarc;
		if (!p)
			cout << "��\n";
		else
		{
			while (p)
			{
				cout << G.vertices[p->adjvex].data;
				p = p->nextarc;
			}
			cout << endl;
		}
	}
	for (int i = 0; i < G.vexnum; ++i)
	{
		int outdegree = 0;
		ArcNode *p = G.vertices[i].firstarc;
		while (p)
		{
			++outdegree;
			p = p->nextarc;
		}
		cout << "�ڵ�" << G.vertices[i].data << "����Ϊ" << outdegree << "���Ϊ" << Indegree(G, i) << endl;
	}
	return;
}
