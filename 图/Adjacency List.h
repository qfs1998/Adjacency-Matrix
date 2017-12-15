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
	cout << "请输入顶点数目和边数\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入顶点的值\n";
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	VertexType v1, v2;
	cout << "请输入边的信息（输入从弧尾到弧头的节点）\n";
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
	cout << "顶点为:";
	for (int i = 0; i < G.vexnum; ++i)
		cout << G.vertices[i].data << ' ';
	cout << "边数为:" << G.arcnum;
	cout << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cout << "节点" << G.vertices[i].data << "的邻接到：";
		ArcNode *p = G.vertices[i].firstarc;
		if (!p)
			cout << "无\n";
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
		cout << "节点" << G.vertices[i].data << "出度为" << outdegree << "入度为" << Indegree(G, i) << endl;
	}
	return;
}
