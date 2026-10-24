#include <iostream>
#include <cstdlib>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op = 0;

    while (op != 7) {
        system("cls"); // Comando para Windows
        cout << "Menu Lista Ligada" << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case 1: inicializar(); break;
            case 2: exibirQuantidadeElementos(); break;
            case 3: exibirElementos(); break;
            case 4: buscarElemento(); break;
            case 5: inserirElemento(); break;
            case 6: excluirElemento(); break;
            case 7: return;
            default: cout << "Opcao invalida.\n"; break;
        }

        system("pause"); // Comando para Windows
    }
}

void inicializar()
{
    NO* aux = primeiro;

    while (aux != NULL) {
		        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    ultimo = NULL;
    cout << "Lista inicializada.\n";
}

void exibirQuantidadeElementos()
{
    int nElementos = 0;
    NO* aux = primeiro;

    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }

    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia.\n";
        return;
    }

    cout << "Elementos:\n";
    NO* aux = primeiro;

    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento()
{
    NO* novo = (NO*)malloc(sizeof(NO));

    if (novo == NULL) {
        cout << "Erro ao alocar memoria.\n";
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
    }
    else {
        ultimo->prox = novo;
        ultimo = novo;
    }

    cout << "Elemento inserido.\n";
}

void buscarElemento()
{
    int numero;
    cout << "Digite o elemento que deseja buscar: ";
    cin >> numero;

    NO* aux = primeiro;

    while (aux != NULL) {
        if (aux->valor == numero) {
            cout << "ELEMENTO ENCONTRADO.\n";
            return;
        }
        aux = aux->prox;
    }

    cout << "ELEMENTO NAO ENCONTRADO.\n";
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia.\n";
        return;
    }

    int numero;
    cout << "Digite o elemento que deseja excluir: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO.\n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    if (atual == ultimo) {
        ultimo = anterior;
    }

    free(atual);

    if (primeiro == NULL) {
        ultimo = NULL;
    }

    cout << "Elemento excluido.\n";
}
