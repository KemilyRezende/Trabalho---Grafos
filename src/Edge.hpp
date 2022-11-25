#include <iostream>
#include "Vertex.hpp"
#ifndef __EDGE__HPP
#define __EDGE__HPP

using namespace std;

class Edge{ // As arestas são classes dentro da classe Grafo para que possam apontar as conexões e seus respectivos pesos.
	public:
		int signal;
		Vertex v1;
		Vertex v2;
		// Construtor
		Edge(int signal, Vertex v1, Vertex v2);
};

#endif
