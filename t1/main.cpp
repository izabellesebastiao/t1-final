#include "pessoa.hpp"
#define DEBUG false

int main()
{
    vector<pessoaPF> listPF;
    vector<pessoaPJ> listPJ;
    vector<string> listCadast;

    LoadDatabase("Database.dat", listPF, listPJ, listCadast);

    pessoaPF x;
    pessoaPJ y;

    char option;

    if(DEBUG)
    {

    //cout<<"option:" <<endl;
    //cout<<"1. Add PF"<<endl;
    //cout<<"2. Add PJ" << endl;
    //cout<<"3. Remove PF by Index" << endl;
    //cout<<"4. Remove PJ by Index" << endl;
    //cout<<"5. Print Names in Ascending Order" <<endl;
    //cout<<"6. Exit" <<endl;
    //cout<<"Digite o numero da option desejada:"<<endl;
    }

    while(1)
    {
        cin>>option;
        switch(option)
        {
        case '1':
            {
                //cout <<"CADASTRO DE PESSOA FISICA:" <<endl;
                //cout <<"Nome completo:";
                cin.ignore();
                getline (cin, x.nome);
                //cout <<"Nome da mae:";
                getline (cin, x.nomeMae);
                //cout <<"CPF:" <<endl;
                getline (cin, x.CPF);
                //cout <<"Endereco:";
                getline (cin, x.endereco);
                //cout <<"Telefone:";
                getline (cin, x.telefone);

                listPF.push_back(x);

                break;
            }
        case '2':
            {
                //cout <<"CADASTRO DE PESSOA JURUDICA:" <<endl;
                //cout <<"Razao Social:";
                cin.ignore();
                getline (cin, y.razaoSocial);
                //cout <<"CNPJ:";
                getline (cin, y.cnpj);
                //cout <<"Endereco:";
                getline (cin, y.endereco);
                //cout <<"telefone:";
                getline (cin, y.telefone);
                //cout <<"Capital Social:";
                cin >> y.capitalSocial;

                listPJ.push_back(y);

                break;
            }
        case '3':
            {
               //cout <<"REMOVER CADASTRO DE PESSOA FISICA:" <<endl;
                int cadastroPF;
                cin>>cadastroPF;

                removerPF("Database.dat", cadastroPF, listPF);
                break;
            }
             case '4':
            {
               //cout <<"REMOVER CADASTRO DE PESSOA JURIDICA:" <<endl;
                int cadastroPJ;
                cin >>cadastroPJ;

                removerPJ("Database.dat", cadastroPJ, listPJ);
                break;
            }
             case '5':
                {
                    //cout <<"lista de nomes:" <<endl;

                   lista("Database.dat", listPF, listPJ, listCadast);

                    sort(listCadast.begin(), listCadast.end());
                    for(size_t i=0; i<listCadast.size(); i++)
                    {
                        cout<< listCadast.at(i) <<endl;
                    }
                    listCadast.erase(listCadast.begin(), listCadast.end());
                    break;

                }
             case '6':
                 {

                return true;
                 }
                 default:
                {
                    continue;
                }
        }
        cadastro("Database.dat", listPF, listPJ);
    }
    return 0;
}
