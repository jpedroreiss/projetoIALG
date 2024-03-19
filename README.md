# Projeto em C++
## Sistema de Cadastro de Municípios em Minas Gerais

![interface](https://github.com/jpedroreiss/projetoc-/assets/78040348/3882d375-8ddb-4fa7-aba0-8bd761e3a44d)

### 1 Introdução
O código em questão constitui um Sistema de Cadastro de Municípios em Minas Gerais, implementado em C++. Ele utiliza estruturas de dados e funcionalidades para gerenciar informações sobre diferentes municípios, como identificador, nome, população, ano de fundação e mesorregião.

#### 1.1 Descrição das estruturas utilizadas

#### 1.1.1 Estrutura do Registro

O código utiliza o registro município para representar as informações de cada município. Essa estrutura é composta pelos seguintes campos:

identificador: Inteiro que identifica exclusivamente cada município.
nome: Sequência de caracteres (char) representando o nome do município.
população: Sequência de caracteres (char) representando a população do município.
anoFundacao: Inteiro indicando o ano de fundação do município.
mesorregiao: Sequência de caracteres (char) representando a mesorregião do município.

#### 1.1.2 Funções Principais

interface(): Exibe uma interface gráfica inicial, apresentando opções para o usuário.
arquivo_binario(): Grava os dados dos municípios em um arquivo binário chamado "cidades_binario.dat".
escrever(): Escreve os dados dos municípios em um arquivo CSV chamado "projeto.csv".
deletar(): Remove logicamente um município, alterando seu identificador para -1.
apagar(): Remove permanentemente um município que foi deletado pela lógica.
shellSort(): Implementa o algoritmo de ordenação ShellSort para ordenar os municípios em ordem alfabética.
shellSortAno(): Implementa o algoritmo de ordenação ShellSort para ordenar os municípios por ano de fundação.
busca(): Realiza uma busca sequencial por nome de município e exibe suas informações se encontrado.
buscaAno(): Realiza uma busca sequencial por ano de fundação e exibe as informações dos municípios encontrados.
main(): Implementa a lógica principal do programa, permitindo ao usuário escolher diversas operações como visualizar, ordenar, buscar, inserir, sobrescrever, remover e salvar em outro arquivo CSV.

#### 1.1.3 Funcionalidades adicionais

Lixeira: Municípios removidos podem ser restaurados da "lixeira" por meio de uma opção específica, e também pode ser visto quais municípios estão na lixeira.
Quizz: Inclui um quiz simples ao final, proporcionando uma interação mais lúdica ao usuário.
Salvar em um outro arquivo CSV: É possível salvar em outro arquivo CSV os dados dos municípios.

### 2 FUNCIONAMENTO DO CÓDIGO

#### 2.1 Leitura do arquivo CSV 

A execução inicia com a leitura de um arquivo CSV denominado "projeto.csv". Esse arquivo contém dados sobre o tamanho do arquivo e dos municípios, como identificador, nome, população, ano de fundação e mesorregião. A leitura é realizada por meio da biblioteca.

#### 2.2 Gravação em Arquivo Binário

Os dados lidos do arquivo CSV são, em seguida, gravados em um arquivo binário chamado "cidades_binario.dat" por meio da função arquivo_binario().

#### 2.3 Interface Inicial

Após a leitura e gravação inicial, o sistema exibe uma interface gráfica para o usuário, apresentando as opções disponíveis.

#### 2.4 Estrutura Principal (Loop da 'main')

A execução principal ocorre dentro de um loop que permite ao usuário realizar diversas operações, como visualizar, ordenar, buscar, inserir, sobrescrever e remover municípios. Além disso, também há opções como a lixeira, salvar arquivo em outro CSV e o quizz. Sendo assim, o loop é controlado pela variável reiniciar.

#### 2.5 Liberação da Memória e Encerramento

O código encerra liberando a memória alocada dinamicamente para o vetor de estruturas cidade e retorna 0.

### 3 CONCLUSÃO

O projeto proporcionou uma experiência prática valiosa na implementação de operações de leitura, escrita, ordenação e manipulação de registros em arquivos binários, reforçando conceitos fundamentais da linguagem C++. Foi bastante importante para aprimorar a capacidade de adaptação, criatividade e raciocínio. Além disso, fornecendo uma experiência conjunta de trabalho, destacando a importância do trabalho e raciocínio em equipe para formular melhor o código.

![ate mais](https://github.com/jpedroreiss/projeto/assets/78040348/1d487132-f11e-4768-b87f-f77696b3a4de)


