#include "categoria.hpp"

#ifndef ALUNO_HPP
#define ALUNO_HPP

class Aluno : public Categoria
{
private:
    int _matricula;
    int _media;

public:
    Aluno(int id, const std::string nome, const std::string categoria, int matricula, int media);
};

#endif // ALUNO_HPP
