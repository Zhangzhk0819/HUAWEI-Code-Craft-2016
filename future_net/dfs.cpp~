#include <stdio.h>
#include "dfs.h"
#include <algorithm>

void DFS::Initialization(int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
		s_vianode[i] = false;
		
	for(int i=0; i<vianode_num; i++)
	{
		s_src2via[i] = true;
		s_via2dest[i] = true;
	}
	
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			s_via2via[i][j] = true;
			
	step = 0;
	
	dist_shortest = maxint;
	dist = 0;
}

void DFS::CalValidPath(int path_src2via[maxvianode][maxnode], int path_via2dest[maxvianode][maxnode], int path_via2via[maxvianode][maxvianode][maxnode], int vianode[maxvianode], int vianode_num)
{		
	for(int i=0; i<vianode_num; i++)
		for(int j=1; path_src2via[i][j]!=maxint; j++)
			for(int k=0; k<vianode_num; k++)
				if(path_src2via[i][j]==vianode[k] && path_src2via[i][j]!=vianode[i])
					s_src2via[i] = 0;
					
	for(int i=0; i<vianode_num; i++)
		for(int j=1; path_via2dest[i][j]!=maxint; j++)
			for(int k=0; k<vianode_num; k++)
				if(path_via2dest[i][j]==vianode[k])
					s_via2dest[i] = 0;
					
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int t=1; path_via2via[i][j][t]!=maxint; t++)
				for(int k=0; k<vianode_num; k++)
					if(path_via2via[i][j][t]==vianode[k] && path_via2via[i][j][t]!=vianode[j])
						s_via2via[i][j] = 0;
						
	for(int i=0; i<vianode_num; i++)
		s_via2via[i][i] = 0;
}

/*void DFS::DepthControl(int vianode_num, int dist_via2via[maxvianode][maxvianode])
{
	int dist_via2via_sort[maxvianode][maxvianode];
	
	for(int i=0; i<maxvianode; i++)
		for(int j=0; j<maxvianode; j++)
			dist_via2via_sort[i][j] = dist_via2via[i][j];
			
	for(int i=0; i<vianode_num; i++)
		sort(dist_via2via_sort[i], dist_via2via_sort[i] + vianode_num);
		
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			if(s_via2via[i][j])
				if(dist_via2via[i][j] > dist_via2via_sort[i][depth_s])
					s_via2via[i][j] = 0;
}*/

void DFS::CalPath(int path_add[maxnode])
{
	for(int i=0; path_add[i]!= maxint; i++)
		path.push_back(path_add[i]);
}

bool DFS::IfCircle()
{
	for(int i=0; i<path.size(); i++)
		for(int j=0; j<path.size(); j++)
			if(i!=j && path[i] == path[j])
				return true;
				
	return false;
}

void DFS::CopyPath(vector<int> path1, vector<int> path2)
{
	path2.clear();
	for(int i=0; i<path1.size(); i++)
		path2.push_back(path1[i]);
}

void DFS::DisplayPath(vector<int> path)
{
	for(int i=0; i<path.size(); i++)
		printf("%4d", path[i]);
}

void DFS::Node2Edge(int edge_num, int topology[maxedge][4])
{
	int k;
	for(k=0; k<path_shortest.size() - 1; k++)
		for(int i=0; i<edge_num; i++)
		{
			if(path_shortest[k] == topology[i][1] && path_shortest[k+1] == topology[i][2])
				path_edge.push_back(topology[i][0]);
		}
}

void DFS::DisplayEdge()
{
	for(int i=0; i<path_edge.size(); i++)
	{
		printf("%d", path_edge[i]);
		printf("|");
	}
}

void DFS::DisplayS(bool s[maxvianode], int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
		printf("%4d", s[i]);
	printf("\n");
}










