#include <stdio.h>
#include "dijkstra.h"

void Dijkstra::Initialization()
{
	for(int i=0; i<maxnode; i++)
	{
		path[i] = maxint;
		dist[i] = maxint;
		prev[i] = maxint;
	}
}

void Dijkstra::ResetPath()
{
	for(int i=0; i<maxnode; i++)
		path[i] = maxint;
}

void Dijkstra::ResetDist()
{
	for(int i=0; i<maxnode; i++)
	dist[i] = maxint;
		
	for(int i=0; i<maxnode; i++)
		prev[i] = maxint;
}

void Dijkstra::DisplayPath()
{
	for(int i=0; path[i]!=maxint; i++)
    	printf("%8d", path[i]);
    printf("\n");
}

void Dijkstra::CalShortestDist(int node_num, int sourcenode, int node_distance[maxnode][maxnode])
{
    bool s[maxnode];    // 判断是否已存入该点到S集合中
    
    //Initialize dist[i],s[i] and prev[i]
    for(int i=0; i<node_num; ++i)
    {
        dist[i] = node_distance[sourcenode][i];
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] == maxint)
            prev[i] = maxint;
        else
            prev[i] = sourcenode;
    }
    dist[sourcenode] = 0;
    s[sourcenode] = 1;
 
    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    for(int i=0; i<node_num; ++i)
    {
        int tmp = maxint;
        int u = sourcenode;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=0; j<node_num; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中
 
        // 更新dist
        for(int j=0; j<node_num; ++j)
            if((!s[j]) && node_distance[u][j]<maxint)
            {
                int newdist = dist[u] + node_distance[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

void Dijkstra::SearchPath(int source, int destination)
{
    int que[maxnode];
    int tot = 1;
    int *path_tmp;
    
    path_tmp = path;
    que[tot] = destination;
    tot++;
    int tmp = prev[destination];
    
    while(tmp != source)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = source;
    
    for(int i=tot; i>=1; --i)
    {
    	*path_tmp = que[i];
    	path_tmp++;
    }  
}



