#include <iostream>
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"
#ifndef __GRAPH__HPP
#define __GRAPH__HPP

using namespace std;

class Graph{
	public:
		vector<Vertex> vertices;
		vector<Edge> edges; // As conex�es do grafo s�o apontadas no vector de arestas.
		
		// Fun��es
		void insertVertex(Vertex v); 
		void insertEdge(int v1, int v2, int signal); 
		void printVertex();
};

#endif
