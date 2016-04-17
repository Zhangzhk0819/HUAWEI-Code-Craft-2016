#include "lib_record.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "route.h"
#include "read_graph.h"
#include "dijkstra.h"
#include "sk.h"
#include "dfs.h"
#include "config.h"

using namespace std;

ReadGraph graph;
Dijkstra dijkstra;
DFS dfs;
SK sk;

void Search(vector<int> path_vianode, bool s_vianode);
void Initialization();

int path_source2via[maxvianode][maxnode];
int dist_source2via[maxvianode];

int path_via2destination[maxvianode][maxnode];
int dist_via2destination[maxvianode];

int path_via2via[maxvianode][maxvianode][maxnode];
int dist_via2via[maxvianode][maxvianode];

bool s_one = false;
int maxvianode_threshold = 15;

//你要完成的功能总入口
void search_route(char *topo[5000], int edge_num, char *demand)
{    	
    /**************************** Initialization of the pulic variables *****************************/
//    printf("%d\n", s_one);
    Initialization();		
    graph.Initialization();     
    dijkstra.Initialization();
       
	/************************************* Read the graph ******************************************/
	graph.ReadTopology(topo, edge_num);	
//	graph.DisplayTopology(graph.node_distance);
	
	graph.ReadDemand(demand);
	graph.DisplayDemand();
	
	/**************************** Initialization of SK66 Algorithm *********************************/
	
	////////////////////////////////// Source to via ///////////////////////////////////////////
	//Calculate distance between source node to via node
    graph.RemoveNode(graph.destinationnode, graph.node_distance);
    
    printf("Destination node is:%d\n", graph.destinationnode);
    printf("node number is:%d\n\n", graph.node_num);
//    graph.DisplayTopology(graph.node_distance_remove);
    
    dijkstra.CalShortestDist(graph.node_num, graph.sourcenode, graph.node_distance_remove);    	
    
//    printf("Distance between source node to via node is:\n");    
     for(int i=0; i<graph.vianode_num; i++)
    {    	    	    	
    	//Put the distance between source node to via node into dist_source2via[]
    	dist_source2via[i] = dijkstra.dist[graph.vianode[i]];    	
//    	printf("%4d", dist_source2via[i]);    	
    }
//    printf("\n");
//    printf("\n");   
    
    
    //Search the shortest path from source node to via node
//    printf("Path node between source node to via node is:\n");
   for(int i=0; i<graph.vianode_num; i++)
    {    	    	    	
    	dijkstra.SearchPath(graph.sourcenode, graph.vianode[i]);
//    	dijkstra.DisplayPath();    	
    	
       	//Put the searched path to path_source2node[][]
       	for(int j=0; dijkstra.path[j]!=maxint; j++)
    		path_source2via[i][j] = dijkstra.path[j];    		
    	dijkstra.ResetPath();    	
    }
    dijkstra.ResetDist();
//    printf("\n\n");
    
    ////////////////////////////////// Via to via ///////////////////////////////////////////

//    printf("Path node between via node to via node is:\n");
    for(int i=0; i<graph.vianode_num; i++)
    {
    	////////////////////////////// via node to destination node ////////////////////////////////
    	graph.RemoveNode(graph.sourcenode, graph.node_distance);
    	graph.RemoveNode(graph.destinationnode, graph.node_distance_remove);
    	//graph.DisplayTopology(graph.node_distance_remove);
    	dijkstra.CalShortestDist(graph.node_num, graph.vianode[i], graph.node_distance_remove);
    	    	
    	for(int j=0; j<graph.vianode_num; j++)
    	{
    		//Distance between via node to via node
    		dist_via2via[i][j] = dijkstra.dist[graph.vianode[j]];
    		    		
    		//Search the shortest path from via node to via node
    		if(i!=j) //Why i can not be equal to j??????????
    		{
				dijkstra.SearchPath(graph.vianode[i], graph.vianode[j]);
//				dijkstra.DisplayPath();
				
				for(int t=0; dijkstra.path[t]!=maxint; t++)
					path_via2via[i][j][t] = dijkstra.path[t];
				dijkstra.ResetPath();
			}
    	}
    	dijkstra.ResetDist();
//    	printf("\n\n");
    }
//    printf("\n\n");
    
    ////////////////////////////////// Via to destination ///////////////////////////////////////////
    
    for(int i=0; i<graph.vianode_num; i++)
    {
    	////////////////////////////// via node to destination node ////////////////////////////////
    	graph.RemoveNode(graph.sourcenode, graph.node_distance);
    	//dijkstra.RemoveNode(graph.destinationnode, graph.node_num, dijkstra.node_distance_remove);
    	dijkstra.CalShortestDist(graph.node_num, graph.vianode[i], graph.node_distance_remove);
    	
    	//Distance between via node to destination node
    	dist_via2destination[i] = dijkstra.dist[graph.destinationnode];
    	    	
    	//Search the shortest path from via node to destination node
    	dijkstra.SearchPath(graph.vianode[i], graph.destinationnode);
//    	printf("Path node from via node %d to destination node is:\n", graph.vianode[i]);
    	//dijkstra.DisplayPath(); 
//    	sk.DisplayPath(dijkstra.path);
    	//sk.DisplayPath(path_via2destination[i]);
    	
		for(int j=0; dijkstra.path[j]!=maxint; j++)
			path_via2destination[i][j] = dijkstra.path[j];
			
		//sk.DisplayPath(path_via2destination[i]);
		dijkstra.ResetPath();
		dijkstra.ResetDist();		

//    	printf("\n\n");
    }

    
    /**************************************** SK66 Algorithm ****************************************/
    
    /**************************************** DFS Algorithm ****************************************/
	dfs.Initialization(graph.vianode_num);
	dfs.CalValidPath(path_source2via, path_via2destination, path_via2via, graph.vianode, graph.vianode_num);
//	dfs.DepthControl(graph.vianode_num, dist_via2via);
	
    //Display s_***
    dfs.DisplayS(dfs.s_src2via, graph.vianode_num);
    dfs.DisplayS(dfs.s_via2dest, graph.vianode_num);
    printf("\n");
    
    for(int i=0; i<graph.vianode_num; i++)
    	dfs.DisplayS(dfs.s_via2via[i], graph.vianode_num);
    printf("\n");
	
	printf("Start:\n");
	s_one = false; //Why s_one will change its value when reach here???????
//	printf("%d\n", s_one);
	Search(dfs.path_vianode, dfs.s_vianode);

	//Display the shortest distance
	printf("The shortest distance is:\n");
	printf("%d\n\n", dfs.dist_shortest);
		
	//Display the shortest path
	printf("The shortest path is:\n");
	dfs.DisplayPath(dfs.path_shortest);
	printf("\n\n");
	
	dfs.Node2Edge(edge_num, graph.topology);
	dfs.DisplayEdge();
	printf("\n\n");
	
	for(int i=0; i<dfs.path_edge.size(); i++)
		record_result(dfs.path_edge[i]);
}

void Search(vector<int> path_vianode, bool s_vianode)
{
	if(s_one)
		return;
	
	if(dfs.path_vianode.size() == graph.vianode_num)
	{		
		if(dfs.s_via2dest[dfs.path_vianode[dfs.path_vianode.size() - 1]])
		{			
			dfs.CalPath(path_source2via[dfs.path_vianode[0]]);
			dfs.path.pop_back();
			for(int i=0; i<dfs.path_vianode.size() - 1; i++)
			{
				dfs.CalPath(path_via2via[dfs.path_vianode[i]][dfs.path_vianode[i+1]]);
				dfs.path.pop_back();
			}
			dfs.CalPath(path_via2destination[dfs.path_vianode[dfs.path_vianode.size() - 1]]);
			
			dfs.dist += dist_via2destination[dfs.path_vianode[dfs.path_vianode.size() - 1]];

						
			if(!dfs.IfCircle())
				if(dfs.dist_shortest > dfs.dist)
				{
					dfs.dist_shortest = dfs.dist;
					
					//Why CopyPath do not work??????
					//dfs.CopyPath(dfs.path, dfs.path_shortest);
					dfs.path_shortest.clear();
					for(int i=0; i<dfs.path.size(); i++)
						dfs.path_shortest.push_back(dfs.path[i]);
										
					dfs.DisplayPath(dfs.path_shortest);						
					printf("a\n\n");
					
					if(graph.vianode_num >= maxvianode_threshold)
					{
						s_one = true;
						return;	
					}				
				}
			dfs.path.clear();
				
			dfs.dist -= dist_via2destination[dfs.path_vianode[dfs.path_vianode.size() - 1]];
		}
		return;
	}
	
	for(int i = 0; i < graph.vianode_num; i++)
	{
		if(dfs.step == 0)
		{
			if(dfs.s_src2via[i])
			{
				dfs.dist += dist_source2via[i];
				
				dfs.path_vianode.push_back(i);
				dfs.s_vianode[i] = true;
				dfs.step++;
				
				Search(dfs.path_vianode, dfs.s_vianode);
				
				dfs.path_vianode.pop_back();
				dfs.s_vianode[i] = false;
				dfs.step--;
				
				dfs.dist -= dist_source2via[i];
			}
		}
		else
		{
			if(!dfs.s_vianode[i] && dfs.s_via2via[dfs.path_vianode[dfs.path_vianode.size() - 1]][i])
			{
				dfs.dist += dist_via2via[dfs.path_vianode[dfs.path_vianode.size() - 1]][i];
				
				if(dfs.dist < dfs.dist_shortest)
				{
					dfs.path_vianode.push_back(i);
					dfs.s_vianode[i] = true;
					dfs.step++;
				
					Search(dfs.path_vianode, dfs.s_vianode);
				
					dfs.path_vianode.pop_back();
					dfs.s_vianode[i] = false;
					dfs.step--;
				}
				
				dfs.dist -= dist_via2via[dfs.path_vianode[dfs.path_vianode.size() - 1]][i];
			}
		}
	}
}

void Initialization()
{	
	for(int i=0; i<maxvianode; i++)
    	for(int j=0; j<maxnode; j++)
    		dist_via2via[i][j] = maxint;
	
	for(int i=0; i<maxvianode; i++)
    	for(int j=0; j<maxnode; j++)
    	{
    		path_source2via[i][j] = maxint;
    		path_via2destination[i][j] = maxint;
    	}
    	
    for(int i=0; i<maxvianode; i++)
    	for(int j=0; j<maxvianode; j++)
			for(int k=0; k<maxnode; k++)
				path_via2via[i][j][k] = maxint;     
}







