#include <string>

#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

class Categoria
{
private:
    int _id;
    std::string _nome;
    std::string _categoria;

public:
    Categoria(int id, const std::string nome, const std::string categoria);
};

#endif
