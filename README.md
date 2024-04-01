

# Sistema de Cadastro de Municípios em Minas Gerais

![Interface](https://github.com/jpedroreiss/projetoc-/assets/78040348/3882d375-8ddb-4fa7-aba0-8bd761e3a44d)

##  📚 Descrição

Este é um projeto em C++ que implementa um Sistema de Cadastro de Municípios em Minas Gerais. Utiliza estruturas de dados e funcionalidades para gerenciar informações sobre diferentes municípios, incluindo identificador, nome, população, ano de fundação e mesorregião.

### Estrutura do Registro

- **Identificador:** Inteiro único para cada município.
- **Nome:** Sequência de caracteres representando o nome do município.
- **População:** Sequência de caracteres representando a população do município.
- **Ano de Fundação:** Inteiro indicando o ano de fundação do município.
- **Mesorregião:** Sequência de caracteres representando a mesorregião do município.

### Funcionalidades Principais

- `interface()`: Exibe uma interface gráfica inicial com opções para o usuário.
- `arquivo_binario()`: Grava os dados dos municípios em um arquivo binário ("cidades_binario.dat").
- `escrever()`: Escreve os dados dos municípios em um arquivo CSV ("projeto.csv").
- `deletar()`: Remove logicamente um município, marcando seu identificador como -1.
- `apagar()`: Remove permanentemente um município da lixeira.
- `shellSort()`: Implementa o algoritmo de ordenação ShellSort para ordenar os municípios em ordem alfabética.
- `shellSortAno()`: Implementa o algoritmo de ordenação ShellSort para ordenar os municípios por ano de fundação.
- `busca()`: Realiza uma busca sequencial por nome de município e exibe suas informações se encontrado.
- `buscaAno()`: Realiza uma busca sequencial por ano de fundação e exibe as informações dos municípios encontrados.

Essa formatação deixa os tópicos mais destacados e facilita a leitura do conteúdo.

### Funcionalidades Adicionais

- **Lixeira:** Municípios removidos podem ser restaurados da lixeira.
- **Quizz:** Inclui um quiz simples para interação lúdica do usuário.
- **Salvar em Outro Arquivo CSV:** Possibilidade de salvar os dados dos municípios em outro arquivo CSV.

##   Funcionamento do Código

1. **Leitura do Arquivo CSV:** Inicia com a leitura do arquivo CSV "projeto.csv" contendo dados sobre os municípios.
2. **Gravação em Arquivo Binário:** Os dados são gravados em um arquivo binário ("cidades_binario.dat").
3. **Interface Inicial:** Exibe uma interface gráfica com opções para o usuário.
4. **Estrutura Principal (Loop da 'main'):** Execução principal ocorre dentro de um loop que permite ao usuário realizar diversas operações.
5. **Liberação de Memória e Encerramento:** Encerra o código liberando a memória alocada e retorna 0.

##  Conclusão

O projeto proporcionou uma experiência prática valiosa na implementação de operações de leitura, escrita, ordenação e manipulação de registros em arquivos binários, reforçando conceitos fundamentais da linguagem C++. Além disso, destacou a importância do trabalho em equipe para formular melhor o código.

![Até Mais](https://github.com/jpedroreiss/projeto/assets/78040348/1d487132-f11e-4768-b87f-f77696b3a4de)
