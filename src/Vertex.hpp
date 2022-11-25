#include <iostream>
#include <vector>
#ifndef __VERTEX__HPP
#define __VERTEX__HPP

using namespace std;

class Vertex{ // Por quest�es de otimiza��o de espa�o na aplica��o os v�rtices n�o possuem o vector de adjac�ncia como o de padr�o.
	public:
		int value; // Trata-se do n�mero de identifica��o do v�rtice, exemplo: v1, v2...
		// Construtor
		void vertex(int value);
};

#endif
