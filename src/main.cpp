#include <iostream>
#include "../include/hash_map.hpp"
#include "../include/livro.hpp"
#include "../include/no.hpp"

void exibirOpcoes();

int main()
{
    HashMap hm = HashMap();
    int opcao;

    std::cout << "Boas vindas ao gerenciador de livros!" << std::endl;

    while (true)
    {
        exibirOpcoes();
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            hm.listar();
            break;
        case 2:
        {
            Livro *livro = new Livro();
            std::cout << "Digite o nome do livro: ";
            std::getline(std::cin, livro->nome);
            std::cout << "Digite o autor do livro: ";
            std::getline(std::cin, livro->autor);
            hm.inserir(livro);

            break;
        }
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            return 0;
        default:
            std::cout << "Opção inválida, escolha uma das opções abaixo:" << std::endl;
        }
    }

    return 0;
}

void exibirOpcoes()
{
    std::cout << "Escolha uma opcao:" << std::endl;
    std::cout << "1. Visualizar os livros" << std::endl;
    std::cout << "2. Inserir livro" << std::endl;
    std::cout << "3. Buscar livro" << std::endl;
    std::cout << "4. Remover livro" << std::endl;
    std::cout << "5. Editar livro" << std::endl;
    std::cout << "6. Sair" << std::endl;
}
