#include <string>

#pragma once

struct Livro
{
    int id;
    std::string nome;
    std::string categoria = "Livro";
    std::string autor;
};
