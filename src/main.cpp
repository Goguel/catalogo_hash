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
            std::cin.ignore();
            std::getline(std::cin, livro->nome);
            std::cout << "Digite o autor do livro: ";
            std::getline(std::cin, livro->autor);
            hm.inserir(livro);

            std::cout << "Livro inserido com sucesso!"
                      << std::endl
                      << std::endl;

            break;
        }
        case 3:
            int chave;
            std::cout << "Digite o ID do livro a ser buscado: ";
            std::cin >> chave;
            No<Livro> *resultado = hm.buscar(chave);
            if (resultado != nullptr)
            {
                std::cout << "Livro encontrado: "
                          << "ID: " << resultado->chave
                          << ", Nome: " << resultado->valor->nome
                          << ", Autor: " << resultado->valor->autor
                          << ", Categoria: " << resultado->valor->categoria
                          << std::endl;
                break;
            }
        case 4:
            std::cout << "Digite o ID do livro a ser removido: ";
            std::cin >> chave;
            hm.remover(chave);
            std::cout << "Livro removido com sucesso!"
                      << std::endl
                      << std::endl;
            break;
        case 5:
            std::cout << "Digite o ID do livro a ser editado: ";
            std::cin >> chave;
            No<Livro> *noLivro = hm.buscar(chave);
            if (noLivro == nullptr)
            {
                std::cout << "Livro não encontrado!" << std::endl;
                break;
            }
            Livro *livroEditado = new Livro();
            livroEditado->id = noLivro->chave;
            std::cout << "Digite o novo nome do livro: ";
            std::cin.ignore();
            std::getline(std::cin, livroEditado->nome);
            std::cout << "Digite o novo autor do livro: ";
            std::getline(std::cin, livroEditado->autor);
            break;
        case 6:
            std::cout << "Saindo do programa..." << std::endl;
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
