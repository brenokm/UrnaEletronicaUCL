#include <iostream>
#include <vector>
using namespace std;

void crud(vector<string> &nomes, vector<int> &votos)
/*Create Read Delete sem update*/
{
    string nome, escolha;
    int escolhaCRD, numero;

    cout << "deseja cadastrar, excluir ou listar?" << endl;
    cout << "1 - Cadastrar" << endl;
    cout << "2 - Excluir" << endl;
    cout << "3 - Listar" << endl;
    cout << "Escolha uma opcao:";
    cin >> escolhaCRD;

    if (escolhaCRD == 1)
    {
        while (true)
        {
            cout << "Informe o nome do(a) canditato(a)" << endl;
            cin >> nome;
            nomes.push_back(nome);
            votos.push_back(0);
            cout << "deseja cadastrar outro candidato?(S/N)" << endl;
            cin >> escolha;
            if (escolha == "SIM" || escolha == "Sim" || escolha == "sim" || escolha == "S" || escolha == "s")
            {
                continue;
            }
            else if (escolha == "NAO" || escolha == "Nao" || escolha == "nao" || escolha == "N" || escolha == "n")
            {
                return;
            }
            else
            {
                cout << "escolha uma opcao valida" << endl;
                continue;
            }
        }
    }
    else if (escolhaCRD == 2)
    {
        while (true)
        {

            cout << "---------------------------------" << endl;
            cout << "---------------------------------" << endl;
            cout << "--------EXCLUIR CANDIDATO--------" << endl;
            cout << "---------------------------------" << endl;
            cout << "---------------------------------" << endl;
            for (int i = 0; i < nomes.size(); i++)
            {
                cout << i + 1 << " - " << nomes[i] << endl;
            }
            cout << "Informe NUMERO do(a) canditato(a) que deseja excluir" << endl;
            cin >> numero;
            numero = numero - 1;
            if (numero >= 0 && numero < nomes.size())
            {
                nomes.erase(nomes.begin() + numero);
                votos.erase(votos.begin() + numero);
            }

            cout << "deseja excluir outro(a) candidato(a)?(S/N)";
            cin >> escolha;
            if (escolha == "SIM" || escolha == "Sim" || escolha == "sim" || escolha == "S" || escolha == "s")
            {
            }
            else if (escolha == "NAO" || escolha == "Nao" || escolha == "nao" || escolha == "N" || escolha == "n")
            {
                return;
            }
            else
            {
                cout << "escolha uma opcao valida" << endl;
            }
        }
    }
    else if (escolhaCRD == 3)
    {
        while (true)
        {
            for (int i = 0; i < nomes.size(); i++)
            {
                cout << i + 1 << " - " << nomes[i] << endl;
            }
            return;
        }
    }
}

int apurar(vector<string> &nomes, vector<int> &votos)
{
    {
        int vencedor = 0;
        for (int i = 1; i < nomes.size(); i++)
        {
            if (votos[i] > votos[vencedor])
            {
                vencedor = i;
            }
        }
        return vencedor;
    }
}

int votacao(vector<string> &nomes, vector<int> &votos)
{

    int totalVotos = 0, escolha;

    while (true)
    {
        cout << "----------------------------" << endl;
        cout << "------votacao iniciada------" << endl;
        cout << "----------------------------" << endl;
        for (int i = 0; i < nomes.size(); i++)
        {
            cout << i + 1 << " - " << nomes[i] << endl;
        }
        cout << "Escolha o candidato ou 0 para encerrar: ";
        cin >> escolha;

        if (escolha > 0 && escolha <= nomes.size())
        {
            escolha = escolha - 1;
            votos[escolha]++;
            totalVotos++;
        }
        else if (escolha == 0)
        {
            string senha;
            cout << "Digite a senha para encessar a votacao:";
            cin >> senha;
            if (senha == "abc123")
            {
                cout << "votacao encerrada" << endl;
                int resultado = apurar(nomes, votos);

                cout << "O(A) ganhador(a) é" << nomes[resultado] << endl;
                cout << "numero de votos do(a) ganhador(a): " << votos[resultado] << endl;

                break;
            }
        }
        else
        {
            cout << "Tente uma opçao valida" << endl;
        }
    }
}

main()
{

    vector<int> votos;
    vector<string> nomes;

    while (true)
    {

        int escolha;
        cout << "----------------------------" << endl;
        cout << "1 - Cadastrar candidatos" << endl;
        cout << "2 - Inicar votacao" << endl;
        cout << "----------------------------" << endl;
        cout << "Escolha uma opcao:";
        cin >> escolha;

        if (escolha == 1)
        {
            crud(nomes, votos);
            /*cout<<"funcionou voltar para o main";*/
        }
        else if (escolha == 2)
        {
            if (nomes.empty())
            {
                cout << "A lista de candidatos tem menos de 2 candidatos." << endl;
            }
            else
            {
                votacao(nomes, votos);
            }
        }

        else
        {
            cout << "escolha uma opcao valida" << endl;
        }
    }
}
