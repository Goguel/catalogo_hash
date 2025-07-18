#include <iostream>
#include <limits>
#include "../include/hash_map.hpp"
#include "../include/livro.hpp"
#include "../include/no.hpp"

void exibirOpcoes();

int main()
{
    HashMap hm;
    int opcao;

    std::cout << "Boas vindas ao gerenciador de livros!" << std::endl;

    while (true)
    {
        exibirOpcoes();
        std::cin >> opcao;

        if (std::cin.fail())
        {
            std::cout << "\nEntrada invalida. Por favor, digite um numero.\n"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
        {
            hm.listar();
            break;
        }
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
        {
            int id_busca;
            std::cout << "Digite o ID do livro a ser buscado: ";
            std::cin >> id_busca;

            No<Livro> *resultado = hm.buscar(id_busca);

            if (resultado != nullptr)
            {
                std::cout << "\n--- Livro Encontrado ---" << std::endl;
                std::cout << "ID: " << resultado->chave << std::endl;
                std::cout << "Nome: " << resultado->valor->nome << std::endl;
                std::cout << "Autor: " << resultado->valor->autor << std::endl;
                std::cout << "------------------------" << std::endl;
            }
            else
            {
                std::cout << "\nLivro com ID " << id_busca << " nao encontrado." << std::endl
                          << std::endl;
            }
            break;
        }
        case 4:
        {
            int id_remover;
            std::cout << "Digite o ID do livro a ser removido: ";
            std::cin >> id_remover;
            hm.remover(id_remover);
            break;
        }
        case 5:
        {
            int id_editar;
            std::cout << "Digite o ID do livro a ser editado: ";
            std::cin >> id_editar;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            hm.editar(id_editar);
            break;
        }
        case 6:
        {
            std::cout << "Saindo do programa..." << std::endl;
            return 0;
        }
        default:
        {
            std::cout << "\nOpcao invalida, tente novamente.\n"
                      << std::endl;
            break;
        }
        }
    }
    return 0;
}

void exibirOpcoes()
{
    std::cout << "\nEscolha uma opcao:" << std::endl;
    std::cout << "1. Visualizar os livros" << std::endl;
    std::cout << "2. Inserir livro" << std::endl;
    std::cout << "3. Buscar livro" << std::endl;
    std::cout << "4. Remover livro" << std::endl;
    std::cout << "5. Editar livro" << std::endl;
    std::cout << "6. Sair" << std::endl;
    std::cout << "> ";
}
