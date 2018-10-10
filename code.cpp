#include <iostream>
#include <queue>


using namespace std;

struct Fila{
		queue <int> fila;
		
		int ChamadasAtendidasPelaCentral = 0;
		int ChamadasAtendidasPeloDiretor = 0;
		int ChamadasAtendidasPelaAdm = 0;
		int ChamadasAtendidasPeloGerente = 0;
		
		int ChamadasPerdidasNaCentral = 0;
		int ChamadasPerdidasNoDiretor = 0;
		int ChamadasPerdidasNaAdm = 0;
		int ChamadasPerdidasNoGerente = 0;   
	};
	
	bool ListaVazia(Fila *chama){
		cout << "Fila vazia ? >>>  " << chama->fila.empty() << endl<< endl;
	}

	void ChamadasNaFila(Fila *Chama, int ChamadaNaFila){
		Chama->fila.push(ChamadaNaFila);
	}

	int QuantidadeElementos(Fila *chama){
		return chama->fila.size();
	}

	void MostraInicioDaFila(Fila *chama){
    	cout << "Inicio da fila: " << chama->fila.front() << endl << endl;
	}
	
	void LiberaChamadaDaFila(Fila *chama){
		if(ListaVazia(chama)){
			cout << "Nenhum Chamada na Fila" << endl <<endl;
			return;
		}
		else{
    		cout << chama->fila.front() << "   <<<  Liberado da fila!" << endl << endl;
    		chama->fila.pop();
    	}
	}

	void Diretor(Fila *chama){
		string diretor, Cliente, Telefonista;
		
		cout << "A ENCAMINHAR CHAMADA PARA O DIRETOR" << endl << endl;
		cout << "A Chamar Diretor... " << endl << endl;
		cin >> diretor;
		fflush(stdin);
		
		if(toupper(diretor == "ocupado")){
			cout << "COMANDO DE VOZ AUTOMATICO: Diretor esta numa outra chamada, nao e possivel encaminhar a chamada" << endl << endl;
			chama->ChamadasPerdidasNoDiretor++;
		}
		else{
			while(toupper(diretor != "sim") && toupper(diretor != "nao")){
				cout << "Diretor Falando: " << endl <<endl;
				cin >> diretor;
				fflush(stdin);
				cout << "Telefonista da Central Falando: " << endl << endl;
				cin >> Telefonista;
				fflush(stdin);
			}
			if(toupper(diretor == "sim")){
			
				cout << "Chamada em linha: " << chama->fila.front() << endl << endl;	
				while(toupper(Cliente != "obrigado")){
				
					cout << "Diretor Falando: " << endl << endl;
					cin >> diretor;
					fflush(stdin);
					cout << "Cliente Falando: " << endl << endl;
					cin >> Cliente;
					fflush(stdin);
					chama->ChamadasAtendidasPeloDiretor++;
				}
			}
			else if(toupper(diretor == "nao")){
				cout << "Telefonista da Central Falando com cliente: " << endl << endl;
				cin >> Telefonista;
				fflush(stdin);
				cout << "Cliente Falando: " << endl << endl;
				cin >> Cliente;
				fflush(stdin);
				chama->ChamadasAtendidasPeloDiretor++;
			}
				LiberaChamadaDaFila(chama);
				cout << "\nFim da chamada." << endl << endl;
				cout << endl << "PRIMEIRA CHAMADA NA FILA ATENDIDA PELA CENTRAL" << endl << endl;
		}
	}
	
	void Administracao(Fila *chama){
		string Administrador, Cliente, Telefonista;
		
		cout << endl << "A ENCAMINHAR CHAMADA PARA ADMINISTRACAO" << endl << endl;
		cout << "A Chamar Administrador... " << endl << endl;
		cin >> Administrador;
		fflush(stdin);
		
		if(toupper(Administrador == "ocupado")){
			cout << "COMANDO DE VOZ AUTOMATICO: Administrador esta numa outra chamada, nao e possivel encaminhar a chamada" << endl << endl;
			chama->ChamadasPerdidasNaAdm++;
		}
		else{
			while(toupper(Administrador != "sim") && toupper(Administrador != "nao")){
				cout << "Administrador Falando: " << endl << endl;
				cin >> Administrador;
				fflush(stdin);
				cout << "Telefonista da Central Falando: " << endl << endl;
				cin >> Telefonista;
				fflush(stdin);
			}
			if(toupper(Administrador == "sim")){
				cout << "Chamada em linha: " << chama->fila.front() << endl << endl;
		
				while(toupper(Cliente != "obrigado")){
				
					cout << "Administrador Falando: " << endl << endl;
					cin >> Administrador;
					fflush(stdin);
					cout << "Cliente Falando: " << endl << endl;
					cin >> Cliente;
					fflush(stdin);
					chama->ChamadasAtendidasPelaAdm++;
				}
			}
			else if(toupper(Administrador == "nao")){
				cout << "Telefonista da Central Falando com cliente: " << endl << endl;
				cin >> Telefonista;
				fflush(stdin);
				cout << "Cliente Falando: " << endl << endl;
				cin >> Cliente;
				fflush(stdin);
				chama->ChamadasAtendidasPeloDiretor++;
			}
		}
		LiberaChamadaDaFila(chama);
		cout << "\nFim da chamada."<< endl << endl;
		cout << endl << "PRIMEIRA CHAMADA NA FILA ATENDIDA PELA CENTRAL" << endl << endl;
	}
	
	void Gerente(Fila *chama){
		string gerente, Cliente, Telefonista;
		
		cout << endl << "A ENCAMINHAR CHAMADA PARA O GERENTE" << endl << endl;
		
		cout << "A Chamar Gerente... " << endl << endl;
		cin >> gerente;
		fflush(stdin);
		if(toupper(gerente == "obrigado")){
				cout << "COMANDO DE VOZ AUTOMATICO: Gerente esta numa outra chamada, nao e possivel encaminhar a chamada" << endl << endl;
				chama->ChamadasPerdidasNoGerente++;
		}
		else{
			while(toupper(gerente != "sim") && toupper(gerente != "nao")){
				cout << "Gerente Falando: " << endl << endl;
				cin >> gerente;
				fflush(stdin);
				cout << "Telefonista da Central Falando: " <<endl << endl;
				cin >> Telefonista;
				fflush(stdin);
			}
			if(toupper(gerente == "sim")){
				cout << "\nChamada em linha: " << chama->fila.front() << endl << endl;
			
				while(toupper(Cliente != "obrigado")){
					cout << "Gerente Falando: " << endl << endl;
					cin >> gerente;
					fflush(stdin);
					
					cout << "Cliente Falando: " << endl << endl;
					cin >> Cliente;
					fflush(stdin);
					chama->ChamadasAtendidasPeloGerente++;
				}
			}
			else if(toupper(gerente == "nao")){
				cout << "Telefonista da Central Falando com cliente: " << endl << endl;
				cin >> Telefonista;
				fflush(stdin);
				cout << "Cliente Falando: " << endl << endl;
				cin >> Cliente;
				fflush(stdin);
				chama->ChamadasAtendidasPeloDiretor++;
			}
		}
		LiberaChamadaDaFila(chama);
		cout << "\nFim da chamada."<<endl << endl;
		cout << endl << "PRIMEIRA CHAMADA NA FILA ATENDIDA PELA CENTRAL" << endl << endl;
	}
	
	void CentralAtendimento(Fila *chama){
			string Telefonista, Cliente;
			system("cls");
			cout << " Central de Atendimento a Chamar... " << endl << endl;
			cin >> Telefonista;
			fflush(stdin);
		
			if(toupper(Telefonista == "ocupado")){
				cout <<"O numero da central esta noutra ligacao!" << endl << endl;
				chama->ChamadasPerdidasNaCentral++;
			}
			else{
				cout << endl << "PRIMEIRA CHAMADA NA FILA ATENDIDA PELA CENTRAL" << endl << endl;
				while(toupper(Cliente != "obrigado")){
					cout << "\nEm atendimento: " << chama->fila.front() << endl << endl;
					cout << "Telefonista da Central Falando: " << endl << endl;
					cin >> Telefonista;
					fflush(stdin);
					cout << "Cliente: " << endl << endl;
					cin >> Cliente;
					fflush(stdin);
					system("cls")
					if(toupper(Cliente == "diretor")){
						chama->ChamadasAtendidasPelaCentral++;
						cout << "Telefonista da Central Falando: " << endl << endl;
						cin >> Telefonista;
						fflush(stdin);
						Diretor(chama);
					}
					else if(toupper(Cliente == "Administracao")){
						chama->ChamadasAtendidasPelaCentral++;
						cout << "Telefonista da Central Falando: " << endl << endl;
						cin >> Telefonista;
						fflush(stdin);
						Administracao(chama);
					}
					else if(toupper(Cliente == "gerente")){
						chama->ChamadasAtendidasPelaCentral++;
						cout << "Telefonista da Central Falando: " << endl << endl;
						cin >> Telefonista;
						fflush(stdin);
						Gerente(chama);
					}
				}
					chama->ChamadasAtendidasPelaCentral++;
			}
				LiberaChamadaDaFila(chama);
				cout << "\nFim da chamada."<<endl << endl;
	}
	
	void Quantidade(Fila *chama){
		cout << "\nChamadas atendidas pela Central: " <<chama->ChamadasAtendidasPelaCentral << "\tChamadas perdidas: " << chama->ChamadasPerdidasNaCentral << endl << endl;
		cout << "Chamadas atendidas pelo Diretor: " <<chama->ChamadasAtendidasPeloDiretor << " \tChamadas perdidas: " << chama->ChamadasPerdidasNoDiretor << endl << endl;
		cout << "Chamadas atendidas pela Administracao: "<< chama->ChamadasAtendidasPelaAdm <<"\tChamadas perdidas: " << chama->ChamadasPerdidasNaAdm <<endl << endl;
		cout << "Chamadas atendidas pelo Gerente: " <<chama->ChamadasAtendidasPeloGerente << "\tChamadas perdidas: " << chama->ChamadasPerdidasNoGerente << endl << endl;
	}	

int main(){
	Fila chama;
	int ChamadaNaFila, x;
	int opc = -1;
   
   while(opc != 0){
       system("cls");
	    cout << "\t--- INFORME UMA DAS OPCOES ABAIXO ---" << endl;
		cout << "0  - Sair" << endl;
		cout << "1  - Testar se Fila esta Vazia" << endl;
       	cout << "2  - Insere um Numero (Chamada) no final da Fila" << endl;
       	cout << "3  - Consultar Quantidade de Chamadas na fila" << endl;
       	cout << "4  - Verificar o numero(Chamada) que esta no inicio da Fila" << endl;
       	cout << "5  - Remover um Numero(ou chamada) no Inicio da fila\n" << endl;
       	cout << "6  - Central de Atendimeto\n" << endl;
       	cout << "7  - Consultar Quantidadede chamadas atendidas e perdidas" << endl << endl;
       	
       	cout<< "Digite a opcao >>>   ";
       	cin>> opc;
	       switch(opc){
		   		case 0: exit(0); break;
	       	
	       		case 1: ListaVazia(&chama); break;
	       	
				case 2: cout<< "\nNumero na fila >>> ";
					cin>> ChamadaNaFila;
					ChamadasNaFila(&chama, ChamadaNaFila); break;
			
				case 3: x = QuantidadeElementos(&chama); 
					cout << "Quantidade de chamadas na FIla: " << x <<endl;	break;
					
				case 4: MostraInicioDaFila(&chama); break;
			
				case 5: LiberaChamadaDaFila(&chama); break;
			
				case 6: CentralAtendimento(&chama); break;
				
				case 7: Quantidade(&chama);
	       }
			system("pause");
		}
	}
	