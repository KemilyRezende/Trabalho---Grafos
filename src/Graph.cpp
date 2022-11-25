#include <iostream>
#include "Graph.hpp"

using namespace std;

void Graph::insertVertex(Vertex v){ // Insere um novo v�rtice no Grafo.
	this->vertices.push_back(v);
}

void Graph::insertEdge(int v1, int v2, int signal){ // Insere uma nova aresta no Grafo.
	Vertex init;
	init.value = -1;
	Vertex end;
	end.value = -1;
	int size = this->vertices.size();
	for (int i = 0; i < size; i++){ // Procura os v�rtices no Grafo.
		Vertex a = this->vertices[i];
		if (a.value == v1){
			init = a;
		}
		else if (a.value == v2){ // Considerando que para esse problema n�o haver�o loops no Grafo.
			end = a;
		}
		if (init.value != -1 && end.value != -1){ // Condi��o de encerramento do loop (for) quando ambos os v�rtices forem encontrados.
			break;
		}
	}
	
	if (init.value == -1 || end.value == -1){ // Caso um v�rtice n�o seja encontrado a mensagem a seguir � exibida.
		cout << "\nV�rtice n�o encontrado!! Tente novamente com v�rtices j� inseridos.\n";
	}
	else { // Caso ambos os v�rtices sejam encontrados a aresta � adicionada ao vector de arestas.
		Edge e(signal, init, end);
		this->edges.push_back(e);
	}
}

void Graph::printVertex(){ // Imprime quais v�rtices est�o no Grafo.
	int size = this->vertices.size(); 
	int ant = 0;
	for (int i = 0; i < size; i++){
		Vertex v = this->vertices[i];
		if (v.value != ant){
			cout << "V�rtice " << v.value << ", ";
		}
		ant = v.value;
	}
	cout << "\n";
}
