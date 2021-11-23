#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct pessoaPF
{
    string nome;
    string nomeMae;
    string CPF;
    string endereco;
    string telefone;
};

struct pessoaPJ
{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};

bool cadastro(string filename, const vector<pessoaPF> &listPF, const vector<pessoaPJ> &listPJ);

bool LoadDatabase(string filename, vector<pessoaPF> &listPF, vector<pessoaPJ> &listPJ, vector<string> &listCadast);

bool removerPF(string filename, float cadastroPF, vector<pessoaPF> &listPF);//case3
bool removerPJ(string filename, float cadastroPJ, vector<pessoaPJ> &listPJ);//case4

bool lista(string filename, vector<pessoaPF> &listPF, vector<pessoaPJ> &listPJ, vector<string> &listCadast);


#endif

