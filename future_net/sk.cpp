#include <stdio.h>
#include "sk.h"

void SK::Initialization(int vianode_num)
{   		
	//Initialize SK_path[][][] and SK_path_backup[][][]
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int k=0; k<maxnode; k++)
			{
				SK_path[i][j][k] = maxint;
				SK_path_backup[i][j][k] = maxint;
			}
			
	//Initialize SK_path_temp[]
	for(int i=0; i<maxnode; i++)
		SK_path_temp[i] = maxint;
		
	for(int i=0; i<maxnode; i++)
		for(int j=0; j<maxnode; j++)
			s_via2via[i][j] = 0;
			
	//distance_shortest = maxint;
}

void SK::NodeInsert(int *newnode, int *trace)
{
	int temp[maxnode];
	int i;
	int *p1;
	int *p2;
	
	p1 = newnode;
	p2 = trace;
	
	for(int j=0; j<maxnode; j++)
		temp[j] = maxint;
	
	for(i=0; *p1!=maxint; i++)
	{
		temp[i] = *p1;
		p1++;		
	}
	
	for(; *p2!=maxint; i++)
	{
		temp[i-1] = *p2;
		p2++;
	}
    
	p2 = trace;
	for(i=0; temp[i]!=maxint; i++)
	{
		*p2 = temp[i];
		p2++;
	}
}

void SK::Reset(int vector[])
{
	for(int i=0; vector[i]!=maxint; i++)
	{
		vector[i] = maxint;
		//path_tmp++;
	}
}

void SK::DistBackup(int vianode_num)
{	
	//Backup shortest distance
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			SK_dist_backup[i][j] = SK_dist[i][j];
}

void SK::DistDisplay(int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
	{
		printf("The %d's dist:\n", i);
		for(int j=0; j<vianode_num; j++)
			printf("%4d", SK_dist[i][j]);
		printf("\n");
	}
}

void SK::MinDist(int vianode_num, int i, int l)  
{
	//int dist_min = maxint;
	for(int j=0; j<vianode_num; j++)
		if(i!=j && l!=j && dist_min > SK_dist_backup[l][j])
		{
			dist_min = SK_dist_backup[l][j];
			vianode_min = j;
		}
}

void SK::BackupPath(int vianode_num)
{
	//Clear path
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int k=0; k<maxnode; k++)
				SK_path_backup[i][j][k] = maxint;
	
	//Backup path
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int k=0; SK_path[i][j][k]!=maxint; k++)
				SK_path_backup[i][j][k] = SK_path[i][j][k];
}

void SK::ResetPath(int vianode_num)
{
	//Clear path
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int k=0; k<maxnode; k++)
				SK_path[i][j][k] = maxint;
}

void SK::DisplayPath(int path[maxnode])
{
	for(int i=0; path[i]!=maxint; i++)
		printf("%4d", path[i]);
	printf("\n");
}

void SK::SetPath(int frompath[maxnode], int topath[maxnode])
{
	for(int i=0; frompath[i]!=maxint; i++)
		topath[i] = frompath[i]; 
}

void SK::ResetPath(int path[maxnode])
{
	for(int i=0; i<maxnode; i++)
		path[i] = maxint; 
}

void SK::Node2Edge(int edge_num, int topology[maxedge][4], int path_shortest[maxnode])
{
	int k;
	for(k=0; path_shortest[k+1]!=maxint; k++)
		for(int i=0; i<edge_num; i++)
		{
			if(path_shortest[k] == topology[i][1] && path_shortest[k+1] == topology[i][2])
				path_edge[k] = topology[i][0];
		}
					
	path_edge[k] = maxint;
}

void SK::DisplayEdge()
{
	for(int i=0; path_edge[i]!=maxint; i++)
	{
		printf("%d", path_edge[i]);
		printf("|");
	}
}

void SK::CalValidPath(int path_src2via[maxvianode][maxnode], int path_via2dest[maxvianode][maxnode], int path_via2via[maxvianode][maxvianode][maxnode], int vianode[maxvianode], int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
	{
		s_src2via_valid[i] = 1;
		s_via2dest_valid[i] = 1;
	}
	
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			s_via2via_valid[i][j] = 1;
		
	for(int i=0; i<vianode_num; i++)
		for(int j=1; path_src2via[i][j]!=maxint; j++)
			for(int k=0; k<vianode_num; k++)
				if(path_src2via[i][j]==vianode[k] && path_src2via[i][j]!=vianode[i])
					s_src2via_valid[i] = 0;
					
	for(int i=0; i<vianode_num; i++)
		for(int j=1; path_via2dest[i][j]!=maxint; j++)
			for(int k=0; k<vianode_num; k++)
				if(path_via2dest[i][j]==vianode[k])
					s_via2dest_valid[i] = 0;
					
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			for(int t=1; path_via2via[i][j][t]!=maxint; t++)
				for(int k=0; k<vianode_num; k++)
					if(path_via2via[i][j][t]==vianode[k] && path_via2via[i][j][t]!=vianode[j])
						s_via2via_valid[i][j] = 0;
						
	for(int i=0; i<vianode_num; i++)
		s_via2via_valid[i][i] = 0;
}

void SK::DisplayS(bool s[maxvianode], int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
		printf("%4d", s[i]);
	printf("\n");
}

void SK::BackupS(int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			s_via2via_backup[i][j] = s_via2via[i][j];
}

void SK::ResetS(int vianode_num)
{
	for(int i=0; i<vianode_num; i++)
		for(int j=0; j<vianode_num; j++)
			s_via2via[i][j] = 0;
}

bool SK::IfNodeInPath(int node, int path[maxnode])
{
	bool in = 0;
	for(int i=0; path[i]!=maxint; i++)
		if(node == path[i])
			in = 1;
			
	return in;
}














