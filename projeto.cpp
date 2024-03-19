/*
----------------------------------------------------------------------|
 
 Projeto Prático:
 - Municípios de Minas Gerais                                                                  
 
 Integrantes:
 - Daniel de Jesus Moreira
 - João Pedro Lara Reis                                                                                                                                      
                                                                     
----------------------------------------------------------------------|
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream> 
using namespace std;

void interface() {
	cout<<"  ____    _         _                                "<< endl;                                                      
    cout<<" / ___|  (_)  ___  | |_    ___   _ __ ___     __ _   "<<endl;
    cout<<" \\___ \\  | | / __| | __|  / _ \\ | '_ ` _ \\   / _` | "<<endl;
    cout<<"  ___) | | | \\__ \\ | |_  |  __/ | | | | | | | (_| |  " <<endl;
    cout<<" |____/  |_| |___/  \\__|  \\___| |_| |_| |_|  \\__,_|   "<<endl;
    cout<<"      _             ____               _                 _  "<<endl;
    cout<<"   __| |   ___     / ___|   __ _    __| |   __ _   ___  | |_   _ __   ___  "<<endl;
    cout<<"  / _` |  / _ \\   | |      / _` |  / _` |  / _` | / __| | __| | '__| / _ \\ "<<endl;
    cout<<" | (_| | |  __/   | |___  | (_| | | (_| | | (_| | \\__ \\ | |_  | |   | (_) |"<<endl;
    cout<<"  \\__,_|  \\___|    \\____|  \\__,_|  \\__,_|  \\__,_| |___/  \\__| |_|    \\___/ "<<endl;
    cout<<endl<<endl;
    cout<<"            "<<"=[ Projeto de Sistema de Cadastro em Arquivos com Ordenacao    ]"<<endl;
    cout<<"+"<<"  "<<"--"<<" "<<"  "<<"--"<<"  "<<"=[ Versao 2.0                                                  ]"<<endl;
    cout<<"+"<<"  "<<"--"<<" "<<"  "<<"--"<<"  "<<"=[ Municipios de Minas Gerais                                  ]"<<endl;
    cout<<"+"<<"  "<<"--"<<" "<<"  "<<"--"<<"  "<<"=[ Daniel de Jesus Moreira e Joao Pedro Lara Reis              ]"<<endl;
	cout<<endl<<endl<<endl;
    cout<<"Digite o numero para realizar o procedimento desejado:"<<endl;
    cout<<endl<<"1. Ver Municipios"<<"                                       "<<"2. Ordernar Municipios por Ordem Alfabetica";
    cout<<endl<<"3. Ordernar Municipios por Ano de Fundacao"<<"              "<<"4. Inserir Municipio"<<endl;
    cout<<"5. Remover Municipio"<<"                                    "<<"6. Buscar Municipio (por nome)"<<endl;
    cout<<"7. Buscar Municipio (por ano de fundacao)"<<"               "<<"8. Sobrescrever Municipio"<<endl;
    cout<<"9. Salvar arquivo em outro CSV"<<"                          "<<"10. Lixeira"<<endl;
    cout<<"11. Quizz"<<endl;
    cout<<endl;
}

struct municipio {
	int identificador;
	char nome[50];
	char populacao[20];
	int anoFundacao;
	char mesoregiao[50];
};

//Gravar no Arquivo Binario
void arquivo_binario(municipio cidade[], int tamanho) {
	ofstream saida("cidades_binario.dat", ios::binary);
    saida.write(reinterpret_cast<const char*>(cidade), sizeof(municipio) * tamanho);
    saida.close();
}

//Ofstream (Escrever no Arquivo CSV)
void escrever(municipio cidade[], int tamanhoArquivo) {
	ofstream arquivo("projeto.csv");
	if (arquivo.is_open()) {	
			arquivo<<tamanhoArquivo<<"\n";
			for (int i=0; i < tamanhoArquivo; i++) {
				if (cidade[i].identificador == -1) {
					cidade[i].identificador = -1;
				} else cidade[i].identificador = i+1;
				
				arquivo<<cidade[i].identificador<<";"<<cidade[i].nome<<";"<<cidade[i].populacao<<";"<<cidade[i].anoFundacao<<";"<<cidade[i].mesoregiao<<";"<<endl;		
			}
		arquivo.close();
		}
	 else
	 { cout<<"Erro ao abrir o arquivo.";
	 
	 }
}

//Metodo para remover uma cidade permanente
void apagar(municipio* &cidade, int& tamanho) {
    int novoTamanho = 0;
    municipio* novo = new municipio[tamanho];
    int elementoRemover = -1;

    for (int i = 0; i < tamanho; i++) {
        if (cidade[i].identificador != elementoRemover) {
            novo[novoTamanho++] = cidade[i];
        }
    }
    delete[] cidade; 
    tamanho = novoTamanho; 
    cidade = novo;
}

//Metodo de Ordenação ShellSort para Ordenar em Ordem Alfabética
void shellSort(municipio cidade[], int tamanho) {	  
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            municipio aux = cidade[i];
            int j;
            for (j = i; j >= gap and strcmp(cidade[j - gap].nome, aux.nome) > 0; j -= gap) {
                cidade[j] = cidade[j - gap];
            }
            cidade[j] = aux;
        }
    }
}

//Metodo de Ordenação ShellSort para Ordenar por Ano de Fundação 
void shellSortAno(municipio cidade[], int tamanho) {    
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            municipio temp = cidade[i];
            int j;
            for (j = i; j >= gap and cidade[j - gap].anoFundacao > temp.anoFundacao; j -= gap) {
                cidade[j] = cidade[j - gap];
            }
            cidade[j] = temp;
        }
    }
}

//Metodo para realizar a Busca por nome
void busca(municipio cidade[],int tamanho){
    char pesquisa[50];
    bool achou = false;
    cout << "Digite o nome para a busca: ";
    cout<<endl;
    cin.ignore();
    cin.getline(pesquisa,50);
    
    for (int i=0; i<tamanho; i++){
		if(cidade[i].identificador != -1){
        if (strcmp(cidade[i].nome,pesquisa) == 0){
            achou = true;
            cout<<endl;
            cout<<"Posicao: "<<cidade[i].identificador;
			cout<<endl;
			cout<<"Nome: "<<cidade[i].nome<<endl<<"Populacao: "<<cidade[i].populacao<<endl<<"Ano de Fundacao: "<<cidade[i].anoFundacao<<endl<<"Mesorregiao: "<<cidade[i].mesoregiao<<endl<<endl;
		}
        }
    }
    if (!achou){
        cout<<"Municipio nao encontrado!" << endl;
    }
}

//Metodo de remover uma cidade ( PELA LOGICA, IDENTIFICADOR = -1)
void deletar(municipio cidade[],int tamanho){
    char pesquisa[50];
    bool achou = false;
    cout << "Digite o nome que deseja remover: ";
    cout<<endl;
    cin.ignore();
    cin.getline(pesquisa,50);
    
    int i = 0;
    int posicao;
	while (i < tamanho) {
		if(cidade[i].identificador != -1){
			if (strcmp(cidade[i].nome,pesquisa) == 0){
				achou = true;
				posicao = i;
			}
		}
		i++;
    }
    if(achou == true){
			cidade[posicao].identificador = -1;
			cout<<"Municipio apagado!" << endl;
		}
    
    if (!achou){
        cout<<"Municipio nao encontrado!" << endl;
    }
}

//Metodo para realizar a Busca por ano de Fundação
void buscaAno(municipio cidade[],int tamanho){
    int pesquisaAno;
    bool achou = false;
    cout << "Digite o ano de fundacao para a busca: ";
    cout<<endl;
    cin>>pesquisaAno;
    
    for (int i=0; i<tamanho; i++){
		if(cidade[i].identificador != -1){
        if (cidade[i].anoFundacao == pesquisaAno) {
            achou = true;
            cout<<endl;
            cout<<"Posicao: "<<cidade[i].identificador;
			cout<<endl;
			cout<<"Nome: "<<cidade[i].nome<<endl<<"Populacao: "<<cidade[i].populacao<<endl<<"Ano de Fundacao: "<<cidade[i].anoFundacao<<endl<<"Mesorregiao: "<<cidade[i].mesoregiao<<endl<<endl;
		}
        }
    }
    if (!achou){
        cout<<"Municipio nao encontrado!" << endl;
    }
}

int main() {
   
   interface();
   bool reiniciar = true;
   int tamanhoArquivo;
   
   //Ler dados do arquivo CSV
   ifstream arquivo("projeto.csv");
   
   if (arquivo) {
	  arquivo>>tamanhoArquivo;
	  arquivo.ignore();
	}
	  
	int capacidade = 70;
	municipio *cidade = new municipio[tamanhoArquivo];
 
	if (arquivo) {
		char pontoVirgula;
		for (int i = 0; i < tamanhoArquivo; i++) {
		arquivo>>cidade[i].identificador;
		arquivo>>pontoVirgula;
		arquivo.getline(cidade[i].nome,50,';');
		arquivo.getline(cidade[i].populacao,50,';');
		arquivo>>cidade[i].anoFundacao;
		arquivo>>pontoVirgula;
		arquivo.getline(cidade[i].mesoregiao,50,';');
		}
	}
	
	//Gravar em Binario
	arquivo_binario(cidade,tamanhoArquivo);
	fstream arquivo_binario("cidades_binario.dat", ios::binary | ios::in | ios::out);
        if (arquivo_binario.is_open()){
            //Contagem de caracteres
            arquivo_binario.seekg(0, arquivo_binario.end);
            streampos tamanho_binario = arquivo_binario.tellg();
            arquivo_binario.seekg(0, arquivo_binario.beg);

            //Quantidade de cidades
            int nRegistros = tamanho_binario / sizeof(municipio);

            //Alocação dos dados do arquivo binário em um vetor de registros
            municipio *cidades = new municipio[nRegistros];
            arquivo_binario.read((char*)(cidades), tamanho_binario);
       }

	//Reiniciar Procedimento
	while (reiniciar) {
	int procedimento;
	cin>>procedimento;

	// Procedimento para ver os Municípios: -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento == 1) {                                                
		int escolher;
		cout<<endl;
		cout<<"1. Ver todos os municipios"<<endl;
		cout<<"2. Ver um trecho do arquivo de municipios ordenados por Ordem Alfabetica (o arquivo sera ordenado)"<<endl;
		
		cin>>escolher;
		
		// Ver todos os municipios
		if (escolher == 1) {
			for (int i = 0; i < tamanhoArquivo; i++) {
				if(cidade[i].identificador != -1){
				cout<<cidade[i].identificador<<": ";
				cout<<endl;
				cout<<"Nome: "<<cidade[i].nome<<endl<<"Populacao: "<<cidade[i].populacao<<endl<<"Ano de Fundacao: "<<cidade[i].anoFundacao<<endl<<"Mesorregiao: "<<cidade[i].mesoregiao<<endl<<endl;
			}
		}
		}
		
		// Ver um trecho do arquivo de municipios ordenados por Ordem Alfabetica (o arquivo sera ordenado)
		if (escolher == 2) {
			int posInicial, posFinal;
			cout<<endl;
			cout<<"Escolha a posicao inicial do trecho (1 ate o Tamaho do Arquivo):  -> Tamanho do Arquivo: "<<tamanhoArquivo<<endl;
			cin>>posInicial;
			
			if (posInicial > 0 and posInicial < tamanhoArquivo) {
				cout<<"Escolha a posicao final do trecho: "<<endl;
				cin>>posFinal;
			}
			if (posFinal <= tamanhoArquivo and posFinal > posInicial) {
				
				shellSort(cidade, tamanhoArquivo);
				apagar(cidade, tamanhoArquivo);
				escrever(cidade, tamanhoArquivo);
				
				for (int i = posInicial-1; i < posFinal; i++) {
					if(cidade[i].identificador != -1){
					cout<<i+1<<": ";
					cout<<endl;
					cout<<"Nome: "<<cidade[i].nome<<endl<<"Populacao: "<<cidade[i].populacao<<endl<<"Ano de Fundacao: "<<cidade[i].anoFundacao<<endl<<"Mesorregiao: "<<cidade[i].mesoregiao<<endl<<endl;
				}
				}
			}
			else cout<<"Opcao Invalida!"<<endl;
		}
	}

	//Procedimento para ordenar municípios por ordem alfabetica. -------------------------------------------------------------------------------------------------------------------------------------------
	if(procedimento == 2){
		
	shellSort(cidade, tamanhoArquivo);
	apagar(cidade, tamanhoArquivo);
	escrever(cidade, tamanhoArquivo);
	
	cout<<endl;
	cout<<"Municipios ordenados com sucesso!";
	cout<<endl;
	}

	//Procedimento para ordenar municípios por ano de fundação. -------------------------------------------------------------------------------------------------------------------------------------------
	if(procedimento == 3){
	
	shellSortAno(cidade, tamanhoArquivo);
	apagar(cidade, tamanhoArquivo);
	escrever(cidade, tamanhoArquivo);
	
	cout<<endl;
	cout<<"Municipios ordenados com sucesso!";
	cout<<endl;
	}

	//Procedimento para buscar um Município (por nome): -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento == 6) {
	busca(cidade, tamanhoArquivo);
	}
	//Procedimento para buscar um Município (por ano de fundação): -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento == 7) {
	buscaAno(cidade, tamanhoArquivo);
	}

	//Procedimento para inserir um Município -------------------------------------------------------------------------------------------------------------------------------------------
	if(procedimento == 4){ 

	//Realocação dinâmica
	if (capacidade == tamanhoArquivo or capacidade < tamanhoArquivo) {
	municipio* novo = new municipio[capacidade+10];
	copy(cidade, cidade+tamanhoArquivo, novo);
	delete[] cidade;
	cidade = novo;
	capacidade += 10;
	} 

	municipio novoMunicipio;
	cin.ignore();
	cout << "Digite o nome do municipio: ";
	cin.getline(novoMunicipio.nome, 50);
	cout << "Digite a populacao do municipio: ";
	cin.getline(novoMunicipio.populacao, 50);
	cout << "Digite o ano de fundacao do municipio: ";
	cin >> novoMunicipio.anoFundacao;
	cin.ignore();
	cout << "Digite a mesorregiao do municipio: ";
	cin.getline(novoMunicipio.mesoregiao, 50);
	cout<<"Arquivo inserido com sucesso!"<<endl;
	
	novoMunicipio.identificador = tamanhoArquivo+1;
	cidade[tamanhoArquivo] = novoMunicipio;
	tamanhoArquivo++;
	
	escrever(cidade, tamanhoArquivo);
	arquivo_binario.seekg(0, ios::beg);
    arquivo_binario.write((char*)(cidade), sizeof(municipio) * tamanhoArquivo);

	}
	   
	//Procedimento para sobrescrever um Município removido -------------------------------------------------------------------------------------------------------------------------------------------
	if(procedimento == 8){
		bool achou = false;
		for(int i = 0; i<tamanhoArquivo and achou == false; i++){
			if(cidade[i].identificador == -1){
				cin.ignore();
				cout << "Digite o nome do municipio: ";
				cin.getline(cidade[i].nome, 50);
				cout << "Digite a populacao do municipio: ";
				cin.getline(cidade[i].populacao, 50);
				cout << "Digite o ano de fundacao do municipio: ";
				cin >> cidade[i].anoFundacao;
				cin.ignore();
				cout << "Digite a mesorregiao do municipio: ";
				cin.getline(cidade[i].mesoregiao, 50);
				cout<<"Arquivo inserido com sucesso!"<<endl;
				cidade[i].identificador = 0;
				achou = true;
				escrever(cidade, tamanhoArquivo);
			}
		}
		if (!achou) {
			cout<<"Nenhum municipio foi apagado!"<<endl;
			}
	}

	//Procedimento para remover um Município -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento == 5) {
			deletar(cidade, tamanhoArquivo);
			escrever(cidade, tamanhoArquivo);
	}
	
	//Fazer Arquivo em outro CSV -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento == 9) {
	ofstream arquivo("segundoArquivoCSV.csv");
	for (int i = 0; i < tamanhoArquivo; i++) {
	cidade[i].identificador = i+1;
	arquivo<<cidade[i].identificador<<";"<<cidade[i].nome<<";"<<cidade[i].populacao<<";"<<cidade[i].anoFundacao<<";"<<cidade[i].mesoregiao<<";"<<endl;
	}
	cout<<endl;
	cout<<"Arquivo salvo com sucesso!";
	cout<<endl;
	}
	
	//Lixeira (Arquivos apagados pela logica -1)
	if (procedimento == 10) {
		bool lixeira = false;
		for (int i = 0; i < tamanhoArquivo; i++) {
			if (cidade[i].identificador == -1) {
				cout<<cidade[i].identificador<<": ";
				cout<<endl;
				cout<<"Nome: "<<cidade[i].nome<<endl<<"Populacao: "<<cidade[i].populacao<<endl<<"Ano de Fundacao: "<<cidade[i].anoFundacao<<endl<<"Mesorregiao: "<<cidade[i].mesoregiao<<endl<<endl;
				lixeira = true;
				
				int opcao;
				cout<<"1. Restaurar um municipio"<<endl;
				cout<<"2. Voltar"<<endl;
				cin>>opcao;
				
				if (opcao == 1) {
					char nomeM[50];
					cin.ignore();
					cout<<"Digite o nome do municipio: "<<endl;
					cin.getline(nomeM, 50);
					bool restaura = false;
					for (int i = 0; i < tamanhoArquivo; i++) {
						if (cidade[i].identificador == -1 and strcmp(cidade[i].nome,nomeM) == 0) {
							cidade[i].identificador = tamanhoArquivo;
							cout<<"Municipio restaurado!"<<endl;
							restaura = true;
							escrever(cidade, tamanhoArquivo);
						}
					}
					if (!restaura) {
						cout<<"Municipio não encontrado"<<endl;
						}
				}
				if (opcao == 2) {
					reiniciar = true;
				}
			
			}
		}
		if (!lixeira) {
			cout<<"Lixeira vazia!"<<endl;
			}
	}
	
	if (procedimento == 11) {
		cout<<"Qual a cidade mais bonita de Minas Gerais?"<<endl;
		cout<<"1. Belo Horizonte"<<endl;
		cout<<"2. Lavras"<<endl;
		cout<<"3. Tiradentes"<<endl;
		cout<<"4. Ouro Preto"<<endl;
		cout<<"5. Sao Tome das Letras"<<endl;
		cout<<"6. Campo Belo"<<endl;
		int escolha;
		cin>>escolha;
		if (escolha == 6) {
			cout<<"Acertou! Parabens!"<<endl;
			}
		if (escolha == 1 or escolha == 2 or escolha == 3 or escolha == 4 or escolha == 5) {
			cout<<"Errou! A cidade mais bonita eh Campo Belo (sem clubismo)"<<endl;
			}
		if (escolha < 1 or escolha > 6) {
			 cout<<"Opcao invalida"<<endl;
			}
		}
	
	//Procedimentos inválidos -------------------------------------------------------------------------------------------------------------------------------------------
	if (procedimento < 1 or procedimento > 11) {
	cout <<
	" ____________________________________________________\n"
	"| ____                                               |\n"
	"|(_  _)__   ______   __                _______       |\n"
	"|(_   _)_)_((     )_(  ) __          _(  (    )__    |\n"
	"| (_(   ___)__(  (_     )  ))    ___(  (     )   )_  |\n"
	"| (  (  ) )_ _(          )    ) (__(     (   ) ___)) |\n"
	"|(( _ )  ) (    (    )     _)     (_ (     )  )_     |\n"
	"| (__    _(     (     ) )     ___    (_         )    |\n"
	"|    (___) (___       _)     ((__)     (____(____)   |\n"
	"|             __     __                              |\n"
	"|   _   _   _ \\ \\_.-'/_`.___                         |\n"
	"|   _- =_- =_[|     [      <)                        |\n"
	"|             `------------'                         |\n"
	"|                                                    |\n"
	"|____________________________________________________|\n"
	"|  ________________________________________________  |\n"
	"| |                                                | |\n"
	"| |            Procedimento Invalido!              | |\n"
	"| |________________________________________________| |\n"
	"|____________________________________________________|\n";
	cout<<endl;
	}

	cout<<"Deseja reiniciar a aplicacao? (s/n) ou (S/N): ";
	char resposta;
	cin>>resposta;

	if (resposta != 'S' && resposta != 's') {
	reiniciar = false;
	}
	else {
	reiniciar = true;
	cout<<endl<<endl<<endl<<endl;
	interface();
	}
	}
	 
	delete[] cidade;  
	return 0;
}
