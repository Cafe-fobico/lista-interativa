#include <iostream>
#include <cstdlib>
#include <locale>
using namespace std;
struct pessoa{
string nome;
int id;
};
void imprime_Lista(pessoa *pontSeq, int tamLista){
for(int i=0;i<tamLista; i++){
cout <<i<<"-Nome:"<< pontSeq[i].nome << endl;
cout << "ID:"<< pontSeq[i].id << endl;
}
}
void insere_Inicio(pessoa *&pontSeq, int *tamLista, string nome, int id){
if(*tamLista == 0){
pessoa *novaLista=new pessoa[1];
novaLista[0].nome=nome;
novaLista[0].id=id;
pontSeq=novaLista;

}else{

pessoa *novaLista=new pessoa[*tamLista+1];
novaLista[0].nome=nome;
novaLista[0].id=id;
for(int i=0; i< *tamLista; i++){
novaLista[i+1].nome=pontSeq[i].nome;
novaLista[i+1].id=pontSeq[i].id;
}
pontSeq=novaLista;
}
*tamLista=*tamLista+1;
}
void insere_Fim(pessoa *&pontSeq, int *tamLista, string nome, int id){
pessoa *novaLista=new pessoa[*tamLista+1];
for(int i=0;i<*tamLista; i++){
novaLista[i].nome=pontSeq[i].nome;
novaLista[i].id=pontSeq[i].id;
}
novaLista[*tamLista].nome=nome;
novaLista[*tamLista].id=id;
pontSeq=novaLista;
*tamLista=*tamLista+1;
}
void insere_Posicao(pessoa *&pontSeq, int *tamLista, string nome, int id, int
posicao){
pessoa *novaLista=new pessoa[*tamLista+1];
for(int i=0; i< posicao; i++){
novaLista[i].nome=pontSeq[i].nome;
novaLista[i].id=pontSeq[i].id;
}
novaLista[posicao].nome=nome;
novaLista[posicao].id=id;
for(int i=posicao+1; i< *tamLista+1; i++){
novaLista[i].nome=pontSeq[i-1].nome;
novaLista[i].id=pontSeq[i-1].id;
}
pontSeq=novaLista;
*tamLista=*tamLista+1;
}
void remove_Inicio(pessoa *&pontSeq, int *tamLista){
pessoa *novaLista=new pessoa[*tamLista-1];
for(int i=1; i< *tamLista; i++){
novaLista[i-1].nome=pontSeq[i].nome;
novaLista[i-1].id=pontSeq[i].id;
}
cout << "Registro removido com sucesso!\n\n";
pontSeq=novaLista;
*tamLista=*tamLista-1;
}
void remove_Fim(pessoa *&pontSeq, int *tamLista){
pessoa *novaLista=new pessoa[*tamLista-1];
for(int i=1; i< *tamLista-1; i++){
novaLista[i].nome=pontSeq[i].nome;
novaLista[i].id=pontSeq[i].id;
}
cout << "Registro removido com sucesso!\n\n";
pontSeq=novaLista;
*tamLista=*tamLista-1;
}
void remove_Posicao(pessoa *&pontSeq, int *tamLista, int posicao){
pessoa *novaLista=new pessoa[*tamLista-1];
for(int i=1; i< *tamLista-1; i++){
if(i<posicao){
novaLista[i].nome=pontSeq[i].nome;
novaLista[i].id=pontSeq[i].id;
}else{
novaLista[i].nome=pontSeq[i+1].nome;
novaLista[i].id=pontSeq[i+1].id;
}
}
cout << "Registro removido com sucesso!\n\n";
pontSeq=novaLista;
*tamLista=*tamLista-1;
}
string busca_Nome(pessoa *&pontSeq, int *tamLista, int id){
string nome ="Nao encontrado\n";
for(int i=0; i< *tamLista; i++){
if(pontSeq[i].id == id){
nome=pontSeq[i].nome;
}
}
return nome;
}
void sair(){
cout << "Encerrando o programa..." << endl;
cout << "\n\n\n";
}
int main()
{
setlocale(LC_ALL,"Portuguese");
int opcao, tamLista;
string nome;
int id, posicao;
pessoa *pontSeq;
cout << "Informe o tamanho de elementos da lista: ";
cin >> tamLista;
pessoa *listaSeq=new pessoa[tamLista];
pontSeq=listaSeq;
do{
cout <<"-------------------------------------"<<endl;
cout <<"MENU"<< endl;
cout << "------------------------------------"<<endl;
cout << "1. BUSCAR ELEMENTO "<< endl;
cout << "2. INSERIR ELEMENTO NO INICIO DA LISTA "<< endl;
cout << "3. INSERIR ELEMENTO NO FINAL DA LISTA "<< endl;
cout << "4. INSERIR ELEMENTO NA POSIÇÃOXDA LISTA" << endl;
cout << "5. REMOVER ELEMENTO NO INICIO DA LISTA"<< endl;
cout << "6. REMOVER ELEMENTO NO FINAL DA LISTA" << endl;
cout << "7. REMOVER ELEMENTO NA POSIÇÃOXDA LISTA"<<endl;
cout << "8. MOSTRAR LISTA"<< endl;
cout << "0. SAIR"<< endl;
cout <<"-------------------------------------"<<endl;
cin >> opcao;

switch(opcao){
case 0:
sair();
break;
case 1:
if(tamLista == 0){
cout << "Lista vazia!!";
}else{
cout << "Informe o ID:\n";
cin >> id;
cout << "Nome: "<< busca_Nome(pontSeq, &tamLista, id);
break;
case 2:
cout << "NOME: ";
cin.ignore();
getline(cin,nome);
cout<<"ID: ";
cin >> id;
insere_Inicio(pontSeq, &tamLista, nome, id);
break;
case 3:
cout << "NOME: ";
cin.ignore();
getline(cin,nome);
cout << "ID: ";
cin >> id;
if(tamLista == 0){
insere_Inicio(pontSeq, &tamLista, nome, id);
}else{
insere_Fim(pontSeq, &tamLista, nome, id);
}
break;
case 4:
cout << "NOME: ";
cin.ignore();
getline(cin,nome);
cout << "ID: ";
cin >> id;
cout << "POSICAO: ";
cin >> posicao;
if(posicao == 0){
insere_Inicio(pontSeq, &tamLista, nome, id);
}else if(posicao == tamLista){
insere_Fim(pontSeq, &tamLista, nome, id);
}else{
insere_Posicao(pontSeq, &tamLista, nome, id, posicao);
}
break;
case 5:
if(tamLista == 0){
cout << "Lista vazia!!\n\n";
}else{
remove_Inicio(pontSeq, &tamLista);
}
break;
case 6:
if(tamLista == 0){
cout << "Lista vazia!!";
}else{
remove_Fim(pontSeq, &tamLista);
}
break;
case 7:
if(tamLista == 0){
cout << "Lista vazia!!\n";
}else{
cout << "Informe a posicao:\n";
cin >> posicao;
if(posicao == 0){
remove_Inicio(pontSeq, &tamLista);
}else if(posicao == tamLista-1){
remove_Fim(pontSeq, &tamLista);
}else{
remove_Posicao(pontSeq, &tamLista, posicao);
}
}
break;
case 8:
imprime_Lista(pontSeq,tamLista);
break;
default:
cout << "Opção Invalida"<< endl;
}
}
}while(opcao != 0);
return 0;
}
