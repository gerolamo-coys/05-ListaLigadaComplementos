#include <iostream>
#include <cstdlib>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

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
        cout << "Menu Lista Ligada Ordenada" << endl << endl;
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

    NO* atual = primeiro;
    NO* anterior = NULL;

    // Encontra a posicao correta para manter a ordem crescente.
    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Nao permite valores duplicados.
    if (atual != NULL && atual->valor == novo->valor) {
        cout << "Esse elemento ja existe na lista.\n";
        free(novo);
        return;
    }

    // Insere no inicio ou depois do anterior.
    if (anterior == NULL) {
        primeiro = novo;
    }
    else {
        anterior->prox = novo;
    }

    // Liga o novo no ao restante da lista.
    novo->prox = atual;

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

        // Como a lista esta ordenada, o valor nao pode aparecer depois.
        if (aux->valor > numero) {
			break;
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

    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se chegou ao fim ou passou do valor, ele nao existe.
    if (atual == NULL || atual->valor > numero) {
        cout << "ELEMENTO NAO ENCONTRADO.\n";
        return;
    }

    // Remove o primeiro no ou liga o anterior ao proximo.
    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido.\n";
}
