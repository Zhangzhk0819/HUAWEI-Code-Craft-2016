#ifndef __DFS_H__
#define __DFS_H__

#include "config.h"
#include <vector>

using namespace std;

class DFS
{
	public:
		vector<int> path_vianode;
		vector<int> path;
		vector<int> path_shortest;
		vector<int> path_edge;
		
		bool s_vianode[maxvianode];
		bool s_src2via[maxvianode];
		bool s_via2via[maxvianode][maxvianode];
		bool s_via2dest[maxvianode];
		
		int step;
		
		int dist;
		int dist_shortest;
		//int dist_temp;
		
		void Initialization(int vianode_num);
		
		void CalPath(int path_add[maxnode]);
		bool IfCircle();
		void CopyPath(vector<int> path1, vector<int> path2);
		void DisplayPath(vector<int> path);
		
		void Node2Edge(int edge_num, int topology[maxedge][4]);
		void DisplayEdge();
		
		void CalValidPath(int path_src2via[maxvianode][maxnode], int path_via2dest[maxvianode][maxnode], int path_via2via[maxvianode][maxvianode][maxnode], int vianode[maxvianode], int vianode_num);
//		void DepthControl(int vianode_num, int dist_via2via[maxvianode][maxvianode]);
		
		void DisplayS(bool s[maxvianode], int vianode_num);
};


#endif
