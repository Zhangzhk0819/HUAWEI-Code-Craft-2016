#include <stdlib.h>
#include <stdio.h>
#include "read_graph.h"

void ReadGraph::Initialization()
{
	for(int i=0; i<maxnode; ++i)
        for(int j=0; j<maxnode; ++j)
            node_distance[i][j] = maxint;
            
    node_num = 0;
    vianode_num = 0;
}

//Read the string from *topo(0->edge ID,0->source node,1->destination node,1->edge weight), and convert them into numbers, then asign the weight value to node_distance[][]
void ReadGraph::ReadTopology(char *topo[], int edge_num)
{
	char *buff[maxedge];      //Store pointer matrix from topo
	
	for(int i=0; i<edge_num; i++)
    	buff[i] = topo[i];
	
	for(int i=0; i<edge_num; ++i)
    {
    	int comma=0;
    	int edge, source, destination, weight;
    	bool cnt1=1, cnt2=1, cnt3=1;  	
    	
    	edge = atoi(buff[i]);
    	topology[i][0] = edge;
    	
    	for(; *buff[i]!='\0'; buff[i]++)
    	{
			if(*buff[i]==',')
				comma++;		
				
			if(comma==1 && *buff[i]!=',' && cnt1==1)
			{
				cnt1 = 0;
				source = atoi(buff[i]);
				topology[i][1] = source;
				
				if(source>node_num)
					node_num = destination;
			}
			
			if(comma==2 && *buff[i]!=',' && cnt2==1)
			{
				cnt2= 0 ;
				destination=atoi(buff[i]);
				topology[i][2] = destination;
				
				if(destination>node_num)
					node_num = destination;
			}
				
			if(comma==3 && *buff[i]!=',' && cnt3==1)
			{
				cnt3=0;
				weight = atoi(buff[i]);
				topology[i][3] = weight;
			}				
    	}
    	node_distance[source][destination]=weight;
    }
    node_num++;
}

void ReadGraph::RemoveNode(int node, int node_distance[maxnode][maxnode])
{
	//Copy node_distance[][] to node_distance_remove[][]
	for(int i=0; i<node_num; ++i)
		for(int j=0; j<node_num; ++j)
			node_distance_remove[i][j] = node_distance[i][j];
		
	//Node distance after remove the specific node
	for(int i=0; i<node_num; ++i)
		node_distance_remove[node][i] = maxint;
		
	for(int i=0; i<node_num; ++i)
		node_distance_remove[i][node] = maxint;
}

//Display the node distance, this is mainly for debug
void ReadGraph::DisplayTopology(int node_distance[maxnode][maxnode])
{
	printf("\n");
    for(int i=0; i<node_num; ++i)
    {
        for(int j=0; j<node_num; ++j)
            printf("%8d", node_distance[i][j]);
        printf("\n");
    }  
}

//Read the string from *demand(0->source node,1->destination node,2->first via node|3->second via node), and convert them into numbers
void ReadGraph::ReadDemand(char *demand)
{
	char *demand_buff;
	int comma=0, line=0;
	bool cnt1=1, cnt2=1; 
	//int viacnt=1;
	
	demand_buff = demand; 

	sourcenode = atoi(demand_buff);    //Convert the source node
	vianode_num++;
	
	for(; *demand_buff!='\0'; demand_buff++)
	{
		if(*demand_buff==',')
			comma++;
		if(*demand_buff=='|')
			line=1;			
			
		if(comma==1 && *demand_buff!=',' && cnt1==1)
		{
			cnt1=0;
			destinationnode=atoi(demand_buff);    //Convert the destination node
		}
		
		//Convert the via node
		if(comma==2 && *demand_buff!=',' && *demand_buff!='|')
		{
			if(cnt2==1)
			{
				cnt2=0;
				vianode[0]=atoi(demand_buff);
			}

			if(line==1)
			{
				line=0;
				vianode[vianode_num]=atoi(demand_buff);
				vianode_num++;
			}
		}			
	}
}

//Display the source node, destination node and via node
void ReadGraph::DisplayDemand()
{
	//Display source node, destination node
    printf("\n");
    printf("The source node is:\n %4d", sourcenode);
    printf("\n");
    printf("The destination node is:\n %4d", destinationnode);
    printf("\n");
    printf("\n");
    
    //Display the via node
    printf("The demanded via node is:\n");
    for(int i=0; vianode[i]!='\0'; ++i)
    {
        printf("%4d", vianode[i]);
    }
    printf("\n");
    printf("\n");
}
