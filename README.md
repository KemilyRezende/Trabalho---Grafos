# Trabalho Grafos

## Problema Abordado

  <p>Este trabalho possui como cerne calcular a quantidade mínima de roteadores para cobrir o acesso à internet em uma área.</p>
  <p>Tal problema pode facilmente aplicar-se em ambientes corporativos, escolares ou até mesmo domésticos. A título de exemplo pode ser tomada a seguinte situação: Um diretor deseja garantir que em todas as salas de uma escola seja possível acessar à internet, para isso é necessário encontrar as áreas de cobertura partindo de cada ponto considerando os obstáculos para a transmissão do sinal, e então determinar a quantidade de roteadores necessária para que o acesso seja satisfatório.</p
  <p>O mapeamento deste problema pode ser executado através de um grafo não-direcionado com pesos nas arestsas, onde cada vértice representará uma sala e cada aresta os pares de salas que podem ser atendidos pelo mesmo roteador cujos pesos representariam a intensidade do sinal.</p>
  
## Grafos

  <p>Grafos são estruturas de dados comumente representados por G = (V, E), onde V é o conjunto dos vértices (ou nós) de um grafo e E o conjunto das arestas. Cada aresta tem um ou dois vértices associados a si, sendo eles as suas extremidades. Para uma melhor compreensão é interessante pensar na conexão de amigos em uma rede social: </p>
  <img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Graph.jpg" width="420px" height="420px">
  <p>Cada usuário pode ser considerado um vértice e cada aresta representa que há conexão entre o par. Este é um exemplo básico de grafo simples não ordenado.</p>
  <p>Outra maneira muito simples de representar grafos é utilizando Listas de Adjacências, estas demonstram quais vértices são adjacentes a um determinado vértice. A lista de adjacência do grafo já mostrado seria este:</p>
  <img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Lista%20de%20Adjac%C3%AAncia.png" width="300px" height="500px">
  <p>Quando há muitas arestas no grafo o uso de listas de adjacência pode se tornar incômodo, para contornar este problema grafos podem ser representados como Matrizes de adjacência. Nestas quando dois vértices se conectam o valor 1 é armazenado no local indicado, quando não o valor 0. Segue a matriz de adjacência do grafo apresentado:</p>
  <img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Matriz%20de%20Adjac%C3%AAncia.png" width="450px" height="450px">

## Árvores Geradoras
<p>Uma Árvore Geradora é um subgrafo de um grafo simples conexo G qualquer que possua todos os vértices de G, entretanto, não há ciclos nesta, portanto, há apenas um caminho entre dois vértices v<sub>0</sub> v<sub>n</sub>.</p>
<p>Uma maneira de gerar uma árvore geradora de um grafo é remover as arestas que criam ciclos, entretanto este não é um método eficiente. Dois métodos melhores a serem destacados são a Busca em Profundidade (DFS) e Busca em Largura (BFS).</p>

### Busca em Profundidade

  <p>Para obter a árvore geradora por este método escolhe-se arbitrariamente um vértice, este será a raiz. Partindo deste forma-se o caminho adicionando arestas e vértices, cada aresta é incidente do último vértice visitado a um vérticeque ainda não tenha sido adicionado à arvore. Segue-se fazendo isto enquanto possível, se todos os vértices foram visitados, a árvore está pronta, caso contrário deve-se retornar ao penúltimo vértice adicionado e repetir o mesmo procedimento e assim sucessivamente até que todos os vértices tenham sido visitados.</p>
  <p>Note que esta é uma aplicação recursiva sendo representada pelo algorítmo a seguir:</p>
  <img src="https://github.com/KemilyRezende/Trabalho---Grafos/blob/main/img/Busca%20em%20Profundidade.png" height = "300px" width = "400px">
  
### Busca em Largura
  <p></p>
## Árvore geradora mínima

## Algorítmo de Kruskal

## Funcionamento do algorítmo proposto

## Referências

<p>ROSEN, Kenneth H. . Matemática Discreta e Suas Aplicações. Sexta Edição. AMGH Editora ltda. 2009.</p>
