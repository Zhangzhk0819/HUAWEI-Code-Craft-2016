#ifndef __SK_H__
#define __SK_H__

#include "config.h"

class SK
{
	public:
		//int distance_shortest;
		//int path_shortest[maxnode];
		
		//int vianode_add;   //l
		int vianode_min;   //j
		int dist_min;
		
		//Used in initialization step
		bool s_src2via_valid[maxvianode];
		bool s_via2dest_valid[maxvianode];
		bool s_via2via_valid[maxvianode][maxvianode];
		
		//Used in iterative step
		bool s_via2via[maxvianode][maxvianode];
		bool s_via2via_backup[maxvianode][maxvianode];
		
		int path_edge[maxedge];
		
		int SK_dist[maxvianode][maxvianode];
		int SK_dist_backup[maxvianode][maxvianode];
		
		int SK_path[maxvianode][maxvianode][maxnode];
		int SK_path_backup[maxvianode][maxvianode][maxnode];
		int SK_path_temp[maxnode];
		
		void Initialization(int vianode_num);
		
		void NodeInsert(int *newnode, int *trace);
		void Reset(int vector[]);
		
		void BackupPath(int vianode_num);
		void ResetPath(int vianode_num);		
		void DisplayPath(int path[maxnode]);
		void SetPath(int frompath[maxnode], int topath[maxnode]);
		void ResetPath(int path[maxnode]);
		
		void DistDisplay(int vianode_num);
		void DistBackup(int vianode_num);
		
		void MinDist(int vianode_num, int i, int l);
		
		void Node2Edge(int edge_num, int topology[maxedge][4], int path_shortest[maxnode]);
		void DisplayEdge();
		
		void CalValidPath(int path_src2via[maxvianode][maxnode], int path_via2dest[maxvianode][maxnode], int path_via2via[maxvianode][maxvianode][maxnode], int vianode[maxvianode], int vianode_num);
		void DisplayS(bool s[maxvianode], int vianode_num);
		void BackupS(int vianode_num);
		void ResetS(int vianode_num);
		bool IfNodeInPath(int node, int path[maxnode]);
									
	private:		
};

#endif
