##Implemente uma Arvore AVL e uma Arvore Red-Black com o seguintes requisitos

* A implementação deverá ser em C++.

* O programa deverá ser capaz de ler um arquivo ASCII com os seguintes dados de Locais e seus CEPs, nesta forma: <CEP>|<Logradouro>. O caracter separador de campos será o caracter ,,|". O arquivo conterá um local por linha. (Exemplo para leitura dos Ceps e gráficos com gnuplot Arquivo)

* Serão fornecidos 3 arquivos com tamanhos diferentes (Santa Catarina, Distrito Federal e Sao Paulo). Tente primeiro usar o programa com o menor. (links para download: df, sc, sp)

* O programa deverá, durante a inclusão e a exclusão escrever em um arquivo os seguintes dados, em ascii, neste formato: <número de elementos na árvore> <tempo necessário para efetuar uma operação de inclusão ou de exclusão>. IMPORTANTE: O tempo necessário para ler um dado do arquivo de entrada não deverá ser considerado.

* Ao final o programa deverá chamar o programa unix gnuplot com o arquivo de tempos como parâmetro para que um gráfico dos tempos seja mostrado na tela. Para tanto esse arquivo deverá ser gerado na sintaxe do gnuplot, detalhada no manual do gnuplot. A chamada automática ao gnuplot vale meio ponto no trabalho. Chamada direta (ser ser via comando) usando a biblioteca do gnuplot vale um ponto.

* Boas técnicas de programação orientadas a objetos valem um ponto no trabalho

* O programa deverá também listar todos os nomes em ordem na tela.

* O programa deve permitir selecionar a arvore em tempo de execução..

Baixe os arquivos C++ em anexo. Suas classes de arvores deve, implementar as classe destas interfaces. Isso é  muito importante pois a avaliação do funcionamento da arvore será feito por estas classes. Você perderá pontos no trabalho se estas etapa não estiver correta, mesmo que sua arvore esteja.
