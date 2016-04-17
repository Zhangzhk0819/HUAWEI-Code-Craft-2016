#ifndef __READGRAPH_H__
#define __READGRAPH_H__

#include "config.h"

class ReadGraph
{
	public:
		int topology[maxedge][4];
		
		int node_distance[maxnode][maxnode];   //Distance between every node pair, after initializatin, the distance between non-connected nodes is maxint
		int node_distance_remove[maxnode][maxnode]; // node distance after remove one specific node
		
		int node_num;   //nodes number which will be used in the following code
		int vianode_num;
		
		int sourcenode;
		int destinationnode;
		int vianode[maxvianode];
		
		void Initialization();
		
		void ReadTopology(char *topo[], int edge_num);
		void RemoveNode(int node, int node_distance[maxnode][maxnode]);
		void DisplayTopology(int node_distance[maxnode][maxnode]);
		
		void ReadDemand(char *demand);
		void DisplayDemand();
			
	private:		
};

#endif
