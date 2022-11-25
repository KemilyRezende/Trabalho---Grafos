#include <iostream>
#include "Edge.hpp"

using namespace std;

Edge::Edge(int signal, Vertex v1, Vertex v2){ // Tratando-se de um Grafo n�o ordenado a ordem dos v�rtices n�o importa.
	this->signal = signal;
	this->v1 = v1;
	this->v2 = v2;
}
