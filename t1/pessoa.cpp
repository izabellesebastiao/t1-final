#include "pessoa.hpp"

bool cadastro(string filename, const vector<pessoaPF> &listPF, const vector<pessoaPJ> &listPJ)
{
    ofstream filewriter(filename);
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i<listPF.size(); i++)
    {
        pessoaPF p = listPF.at(i);
        filewriter << "1" << endl << p.nome << endl << p.nomeMae << endl << p.CPF << endl << p.endereco << endl << p.telefone << endl;
    }

    for(size_t i=0; i<listPJ.size(); i++)
    {
        pessoaPJ p = listPJ.at(i);
        filewriter << "2" << endl << p.razaoSocial << endl << p.cnpj << endl << p.endereco << endl << p.telefone << endl << p.capitalSocial << endl;
    }

    filewriter.close();

    return true;
}

bool LoadDatabase(string filename, vector<pessoaPF> &listPF, vector<pessoaPJ> &listPJ, vector<string> &listCadast)
{
    ifstream filereader(filename);
    if(!filereader.is_open()) return false;

    string tmp;
    while(getline(filereader, tmp))
    {
        if(tmp=="1")
        {
            pessoaPF p;
            getline(filereader, p.nome);
            getline(filereader, p.nomeMae);
            getline(filereader, p.CPF);
            getline(filereader, p.endereco);
            getline(filereader, p.telefone);

            listPF.push_back(p);
            continue;
        }
        if(tmp=="2")
        {
            pessoaPJ p;
            getline(filereader, p.razaoSocial);
            getline(filereader, p.cnpj);
            getline(filereader, p.endereco);
            getline(filereader, p.telefone);
            getline(filereader, tmp);
            p.capitalSocial = stoi(tmp);

            listPJ.push_back(p);
            continue;
        }
    }

    filereader.close();
    return true;
}
bool removerPF(string filename, float cadastroPF, vector<pessoaPF> &listPF)
{
    ifstream removPF(filename);

    if(cadastroPF <listPF.size())
    {
        listPF.erase(listPF.begin()+cadastroPF);
    }
    else
    {
        cout << "cadastro nao encontrado" <<endl;

    }
    removPF.close();

        return true;
}
bool removerPJ(string filename, float cadastroPJ, vector<pessoaPJ> &listPJ)
{
    ifstream removPJ(filename);
    if(cadastroPJ<listPJ.size())
    {
        listPJ.erase(listPJ.begin()+cadastroPJ);
    }
    else
    {
        cout <<"cadastro nao encontrado"<<endl;

    }

    removPJ.close();
        return true;

}
bool lista(string filename, vector<pessoaPF> &listPF, vector<pessoaPJ> &listPJ, vector<string> &listCadast)
{
    ifstream filereader(filename);

    string var;
    while(getline(filereader, var))
    {
        if(var=="1")
            {
                pessoaPF l;
                getline(filereader, l.nome);
                listCadast.push_back(l.nome);

                continue;
            }
            if(var=="2")
            {
                pessoaPJ j;
                getline(filereader, j.razaoSocial);
                listCadast.push_back(j.razaoSocial);

                continue;
            }
}
        filereader.close();
        return true;

    }

