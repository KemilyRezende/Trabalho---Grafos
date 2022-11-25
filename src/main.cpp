#include <iostream>
#include <vector>
#include <cstdlib>
#include <locale.h>
#include "Graph.hpp"

using namespace std;

int cmpEdge(const void *a, const void *b){ // Fun��o de compara��o utilizada como par�metro da fun��o qsort no vector de arestas.
	// L�gica invertida para que o vector seja ordenado de forma decrescente.
	Edge one = *((Edge*)a);
	Edge two = *((Edge*)b);
	if (one.signal > two.signal) return -1;
	else if (one.signal < two.signal) return 1;
	else return 0;
}

int cmpGraph(const void *a, const void *b){ // Fun��o de compara��o utilizada como par�metro da fun��o qsort no vector Floresta.
	// L�gica padrão para que o vector seja ordenado de forma crescente.
	Graph one = *((Graph*)a);
	Graph two = *((Graph*)b);
	if (one.vertices.size() > two.vertices.size()) return -1;
	else if (one.vertices.size() < two.vertices.size()) return 1;
	else return 0;
}

void createForest(Graph g){
	vector<Graph>Forest;
	int t = g.vertices.size();
	for (int i = 0; i < t; i++){ // Cria a floresta colocando cada v�rtice como uma �rvore.
		Graph a;
		Vertex node = g.vertices[i];
		a.insertVertex(node);
		Forest.push_back(a);
	}
	qsort(g.edges.data(), g.edges.size(), sizeof(Edge), cmpEdge); // Ordena o vector de arestas de forma decrescente.
	int tam = Forest.size();
	do {
		bool check = false;
		Edge e = g.edges[0]; // Sempre utiliza a aresta de maior peso, ou seja, de sinal mais forte.
		if (e.signal > 2){ // Caso o sinal seja maior ou igual a 3 roda o algor�tmo.
			Vertex v;
			vector<Graph>::iterator it;
			for (it = Forest.begin(); it != Forest.end(); ++it){
				Graph a = *it;
				int s = a.vertices.size();
				if (s < 2){ // Procura v1 entre as �rvores de v�rtice �nico.
					Vertex av = a.vertices[0];
					if (e.v1.value == av.value){
						v = e.v1; // Armazena o v�rtice procurado.
						Forest.erase(it); // Deleta a �rvore na Floresta, por isso � importante se tratar de uma �rvore de v�rtice �nico.
						check = true;
						break;
					}
				}	
			}
			if (check){ 
			// Caso v1 seja uma �rvore de v�rtice �nico v2 � procurado tamb�m dentro das outras �rvores.
				vector<Graph>::iterator it;
				for (it = Forest.begin(); it != Forest.end(); ++it){
					Graph a = *it;
					int tam2 = a.vertices.size();
					for (int j = 0; j < tam2; j++){
						Vertex v1 = a.vertices[j];
						if (v1.value == e.v2.value){ 
							Graph b;
							a.insertVertex(v);
							a.insertEdge(v.value, v1.value, e.signal);
							int c = a.edges.size();
							int d = a.vertices.size();
							for(int k = 0; k < d; k++){
								Vertex aux = a.vertices[k];
								b.insertVertex(aux);
							}
							for (int k = 0; k < c; k++){
								Edge l = a.edges[k];
								b.insertEdge(l.v1.value, l.v2.value, l.signal);
							}
							Forest.erase(it);
							Forest.push_back(b);
							break;
						}
					}
				}
				qsort(Forest.data(), Forest.size(), sizeof(Graph), cmpGraph);  // Ordena o vector Floresta para que as �rvores de v�rtice �nico estejam no come�o.
			}
			else { 
			// Caso o v1 n�o atenda os requisitos a ordem � invertida procurando primeiro o v2.
				bool check3 = false;
				vector<Graph>::iterator it;
				for (it = Forest.begin(); it != Forest.end(); ++it){
					Graph a = *it;
					int s = a.vertices.size();
					if (s < 2){
						Vertex av = a.vertices[0];
						if (e.v2.value == av.value){
							v = e.v2;
							Forest.erase(it);
							check3 = true;
							break;
						}
					}
				}
				if (check3){ // Se v2 � uma �rvore de um �nico v�rtice, v1 � procurado tamb�m dentro das outras �rvores.
					vector<Graph>::iterator it;
					for (it = Forest.begin(); it != Forest.end(); ++it){
						Graph a = *it;
						int tam2 = a.vertices.size();
						for (int j = 0; j < tam2; j++){
							Vertex v1 = a.vertices[j];
							if (v1.value == e.v1.value){
								Graph b;
								a.insertVertex(v);
								a.insertEdge(v.value, v1.value, e.signal);
								int c = a.edges.size();
								int d = a.vertices.size();
								for(int k = 0; k < d; k++){
									Vertex aux = a.vertices[k];
									b.insertVertex(aux);
								}
								for (int k = 0; k < c; k++){
									Edge l = a.edges[k];
									b.insertEdge(l.v1.value, l.v2.value, l.signal);
								}
								Forest.erase(it);
								Forest.push_back(b);
								break;
							}
						}
					}
					qsort(Forest.data(), Forest.size(), sizeof(Graph), cmpGraph);
				}
			}
			// Se nem v1 nem v2 atende os requisitos nada � feito pois juntar subgrafos poderia criar pontos cegos n�o previstos.
			g.edges.erase(g.edges.begin()); // Deleta a aresta analisada.
		}
		else break;	
		// Se o sinal for menor que 3 as arestas seguintes tamb�m ser�o, logo o loop se encerra pois a qualidade de acesso seria ruim.
		tam = Forest.size();
	} while (tam > 2); 
	// Ao alcan�ar uma floresta com 2 �rvores, ou seja, 2 roteadores o loop se encerra por encontrar uma quantidade satisfat�ria.
	
	vector<Vertex> blind;
	for (int i = 0; i < tam; i++){ 
	// Todos as �rvores de um �nico v�rtice restante ser�o pontos cegos, ou seja, n�o � poss�vel enviar sinal para estes pontos.
		Graph gr = Forest[i];
		if (gr.vertices.size() == 1){
			blind.push_back(gr.vertices[0]);
		}
	}
	if (Forest.size() == blind.size()){ // Se h� apenas �rvores de um �nico v�rtice todos os pontos s�o incomunic�veis.
		cout << "\nN�o h� conex�es poss�veis na �rea.";
	}
	else{
		cout << "\nS�o necessarios " << Forest.size() << " roteadores para cobrir a �rea.\n";
		int cont = 1;
		int bl = blind.size();
		tam = Forest.size();
		for (int i = 0; i < tam; i++){
			Graph gr = Forest[i];
			if (gr.vertices.size() > 1){ // Imprime quais v�rtices participam de cada �rea de cobertura.
				cout << "�rea de cobertura " << cont << ": ";
				gr.printVertex();
				cont++;
			}
		}
		if (!(blind.empty())){
			cout << "Pontos cegos: ";
			for (int i = 0; i < bl; i++){ // Imprime os pontos cegos.
				Vertex b = blind[i];
				cout << "v�rtice " << b.value << ", ";
			}
			cout << ".\n";
		}
	}
}

int main(){
	Graph g;
	setlocale(LC_ALL, "Portuguese");
	int values, aux = 1; //
	//int v1, v2, signal, op = 0;
	cout << "V�rtices no Grafo: ";
	cin >> values;
	for (int i = 0; i < values; i++){
		Vertex v;
		v.value = aux;
		g.insertVertex(v);
		aux++;
	}
	//cout << "Ligações:";
	int aux_v1[] = {1,1,1,2,3,3,4,4,5};
	int aux_v2[] = {2,3,4,4,4,5,5,6,6};
	int aux_sinal[] = {5,2,2,2,5,3,4,1,1};
	for (int i = 0; i < 9; i++){
		g.insertEdge(aux_v1[i], aux_v2[i], aux_sinal[i]);
	}
	//do {
	//	cout << "\nV�rtice 1: "; // O usu�rio deve conhecer o mapeamento.
	//	cin >> v1;
	//	cout << "\nV�rtice 2: ";
	//	cin >> v2;
	//	cout << "\nPot�ncia do sinal: ";
	//	cin >> signal;
	//	g.insertEdge(v1, v2, signal);
	//	cout << "\nDeseja adicionar uma nova liga��o?\n1- Sim.\n2 - N�o.\n";
	//	cin >> op;
	//} while (op != 2);
	createForest(g);
	return 0;
}
