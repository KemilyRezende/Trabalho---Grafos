# Trabalho Grafos

## Problema Abordado

  <p>Este trabalho possui como cerne calcular a quantidade mínima de roteadores para cobrir o acesso à internet em uma área.</p>
  <p>Tal problema pode facilmente aplicar-se em ambientes corporativos, escolares ou até mesmo domésticos. A título de exemplo pode ser tomada a seguinte situação: Um diretor deseja garantir que em todas as salas de uma escola seja possível acessar à internet, para isso é necessário encontrar as áreas de cobertura partindo de cada ponto considerando os obstáculos para a transmissão do sinal, e então determinar a quantidade de roteadores necessária para que o acesso seja satisfatório.</p
  <p>O mapeamento deste problema pode ser executado através de um grafo não-direcionado com pesos nas arestas, onde cada vértice representará uma sala e cada aresta os pares de salas que podem ser atendidos pelo mesmo roteador cujos pesos representariam a intensidade do sinal.</p>
  
## Grafos

  <p>Grafos são estruturas de dados comumente representados por G = (V, E), onde V é o conjunto dos vértices (ou nós) de um grafo e E o conjunto das arestas. Cada aresta tem um ou dois vértices associados a si, sendo eles as suas extremidades. Para uma melhor compreensão é interessante pensar na conexão de amigos em uma rede social: </p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Graph.jpg" width="340px" height="340px"></p>
  <p>Cada usuário pode ser considerado um vértice e cada aresta representa que há conexão entre o par. Este é um exemplo básico de grafo simples não ordenado.</p>
  <p>Outra maneira muito simples de representar grafos é utilizando Listas de Adjacências, estas demonstram quais vértices são adjacentes a um determinado vértice. A lista de adjacência do grafo já mostrado seria este:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Lista%20de%20Adjac%C3%AAncia.png" width="230px" height="400px"></p>
  <p>Quando há muitas arestas no grafo o uso de listas de adjacência pode se tornar incômodo, para contornar este problema grafos podem ser representados como Matrizes de adjacência. Nestas quando dois vértices se conectam o valor 1 é armazenado no local indicado, quando não o valor 0. Segue a matriz de adjacência do grafo apresentado:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Matriz%20de%20Adjac%C3%AAncia.png" width="350px" height="350px"></p>
  <p>Grafos podem ainda ser representados por Matrizes de Incidência na formatação Vértice x Aresta. Quando uma aresta é incidente a um vértice a referente posição V x A será preenchida com 1, caso contrário com 0. Segue a representação do grafo apresentado em uma Matriz de Incidência:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Matriz%20de%20Incid%C3%AAncia.png" height="380px" width="350px"></p>
  
## Árvores Geradoras
<p>Uma Árvore Geradora é um subgrafo de um grafo simples conexo G qualquer que possua todos os vértices de G, entretanto, não há ciclos nesta, portanto, há apenas um caminho entre dois vértices v<sub>0</sub> e v<sub>n</sub>.</p>
<p>Uma maneira de gerar uma árvore geradora de um grafo é remover as arestas que criam ciclos, entretanto este não é um método eficiente. Dois métodos melhores a serem destacados são a Busca em Profundidade (DFS) e Busca em Largura (BFS).</p>

### Busca em Profundidade

  <p>Para obter a árvore geradora por este método escolhe-se arbitrariamente um vértice, este será a raiz. Partindo deste forma-se o caminho adicionando arestas e vértices, cada aresta é incidente do último vértice visitado a um vérticeque ainda não tenha sido adicionado à arvore. Segue-se fazendo isto enquanto possível, se todos os vértices foram visitados, a árvore está pronta, caso contrário deve-se retornar ao penúltimo vértice adicionado e repetir o mesmo procedimento e assim sucessivamente até que todos os vértices tenham sido visitados.</p>
  <p>Esta é uma aplicação recursiva sendo representada pelo pseudoalgorítmo a seguir:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Busca%20em%20Profundidade.png" height = "300px" width = "400px"></p>
  <p>É conhecido que este algorítmo possui um custo computacional equivalente a O(E) ou O(V<sup>2</sup>), onde E representa a número de restas e V o número de vértices.</p>
  
### Busca em Largura

  <p>O ponto de partida para o método de Busca em Largura é também escolher de forma arbitrária um vértice de G para ser a raiz. Diferentemente do método anterior, todos os vértices inidentes do vértice atual serão adicionados à árvore, os novos vértices estarão em nível 1. Em seguida é necessário ordena-los arbitrariamente e repetir o procedimento para cada um deles, ao fim do procedimentoos novos vértices estarão em nível 2 e assim é feito sucessivamente até que todos os vértices estejam inseridos na árvore.</p>
  <p>O método de Busca em largura pode ser representado pelo pseudoalgorítmo a seguir:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Busca%20em%20Largura.png" height = "300px" width = "400px"></p>
  <p>Assim como no método de Busca em Profundidade o custo computacional é equivalente a O(E) ou O(V<sup>2</sup>), onde E representa a número de restas e V o número de vértices.</p>
  
## Codificação de Huffman

  <p>Outra maneira de se construir uma árvore é com a utilização do Código de Huffman. Desenvolvido em 1951 por David Huffman trata-se de um algorítmo criado para comprensão de dados, ou seja, redução de número de bits necessários para representar uma informação.</p>
  <p>Para compreender o funcionamento deste algorítmo é importante apresentar o termo Floresta, este é usado para designar um conjunto de árvores. É exatamente este o ponto de oartida para a formação da árvore de Huffman. Tenha em mente a seguinte situação: É desejado aplicar codificação de Huffman a um texto. Cada palavra será contabilizada em relação a sua frequência no texto e guardada em um vértice, estes serão alocados em um vector ordenado como árvores formando assim a floresta, isto feito, pares serão tomados para a construção da árvore e a dupla será substituída no vector pela sua união. Ao fim do procedimento, quando o vector tiver tamanho 1 a árvore de Huffman estará completa. Note que esta é construída de forma invertida, das folhas para a raiz.</p>
  <p>Segue o pseudoalgorítmo para a construção da árvore de Huffman considerando o exemplo dado:</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Huffman.png" height = "300px" width = "400px"></p>
  <p>Implementado desta maneira este algorítmo possui o custo computacional de O(n), sendo n o tamanho do vector F.</p>

## Funcionamento do algorítmo proposto

  <p>Para solucionar o problema foi tomada a modelagem com um grafo não ordenado representado com base no modelo de Matriz de Incidência, para calcular a quantidade mínima de roteadores foram utilizadas técnicas da árvore de Huffman.</p>
  <p>Como problema modelo foi tomado o seguinte ambiente:</p>
  <p>As linhas internas indicam o grau de dificuldade para a propagação de sinal e as arestas a qualidade do mesmo entre cada vértice como indicado pela legenda. Todas as aplicações serão exemplificadas graficamente com base neste modelo.</p>

### A construção do grafo:

  <p>Para fins de otimização de memória os vértices, representados pela classe Vertex, não possuem um vector de vértices pois toda a manpulação de dados toma por base as arestas, estas são representadas pela classe Edge tendo como dados os dois vértices ligados e a força do sinal, este varia de 1-5, sendo 1 a pior frequeência e 5 a melhor. Dentro da classe Graph, que representa o grafo, as arestas são alocadas em um vectores de suas respectivas classes.</p>
  <p>Na função main (arquivo main.cpp) é possível ver trechos de código comentado, estes são adaptações para que o algorítmo receba manualmente outros modelos de grafos.</p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Grafo%20Modelo.PNG" height = "300px" width = "400px"></p>
  
### Funções cmp:

  <p>As funções cmpEdge e cmpGraph (arquivo main.cpp) são utilizadas como parâmetros para a função qsort. A primeira é utilizada para ordenar o vector das Arestas de forma decrescente, após a ordenação este é utilizado no cálculo da quantidade mínima de roteadores. A segunda é utilizada para ordenar de forma crescente o vector Forest, utilizado diretamente com as técnicas de Huffman para solucionar o problema proposto.</p>
  
### Huffman e cálculo de roteadores:

  <p>Este algorítmo vale-se em muito das técnicas de Huffman, diferenciando-se em suas condições de encerramento e na formação de uma árvore não binária.</p>
  <p>A princípio os vértices do grafo são armazenados como grafos no vector Forest, formando assim a Floresta Inicial. Após isto, o vector ordenado das arestas é utilizado para estabelecer as ligações entre os vértices.</p>
  <p>Um loop é iniciado para calcular a quantidade mínima de roteadores necessária para cobrir a área mapeada pelo grafo inicial. Em cada interação o primeiro item do vértice das arestas é utilizado para buscar os vértices conectados. Um dos vértices precisa ser uma subgrafo com apenas um item pois ao mesclar subgrafos pontos cegos desconhecidos poderiam surgir. Ao encontrar um dos vértices atendendo a estas características o outro pode estar inserido em um subgrafo, um novo subgrafo é criado com os vértices dos dois subgrafos (o que possui v<sub>x</sub> e o que possui v<sub>y</sub>) e em seguida ambos são deletados e substituídos pelo novo. A cada interação o primeiro item do vértice das arestas é deletado. Há duas condições de encerramento para este loop, quando o vector Forest tiver tamanho igual a 2, condição em que há apenas duas áreas de cobertura, ou quando o valor da aresta analisada é menor ou igual a 2, sendo uma frequência muito baixa para garantir acesso à internet de qualidade. Seguem as ilustrações para a melhor compreensão do algorítmo:</p>
  
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Vector%20ordenado.png" height = "150px" width = "400px"></p>
  <p align="center"><img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Funcionamento%20Huffman.png" height = "320px" width = "450px"></p>
  
  <p>Após executar esta etapa são contabilizados os pontos cegos da área, ou seja, subgrafos de apenas um vértice restantes e são exibidas para o usuário a quantidade de roteadores necessários (Tamanho do vector Forest - quantidade de pontos cegos), as áreas de cobertura e quais são os pontos cegos. Para o problema modelo os resultados são:p>
  <p>   São necessários 2 roteadores.</p>
  <p>   Área de cobertura 1: vértice 2, vértice 1</p>
  <p>   Área de cobertura 2: vértice 4, vértice 3, vértice 5</p>
  <p>   Pontos cegos: vértice 6</p>

## Conclusão

 <p>Após os procedimentos de pesquisa e aplicação em um modelo utilizando o algorítmo proposto afere-se que os objetivos do trabalho, compreensão do funcionamento da estrutura de dados em questão e aplicação da mesma em um problema real, foram atendidos.</p>
 <p>Para trabalhos futuros é valido a proposição de um algorítmo que possibilite a mesclagem de subgrafos sem que haja surgimento de pontos cegos não previstos.</p>

## Referências

<p>ROSEN, Kenneth H. . Matemática Discreta e Suas Aplicações. Sexta Edição. AMGH Editora ltda. 2009.</p>
<p>CÓDIGO DE HUFFMAN. Instituto de Matmática e Estatística da Universidade de São Paulo. Disponível em: https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/huffman.html . Último acesso: 25/11/2022</p>
