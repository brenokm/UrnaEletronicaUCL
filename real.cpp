#include <iostream>
using namespace std;
#include <vector>

int acharVencedor(vector<int> votos)
{
    int maior = votos[1];
    int indiceVencedor = 1;

    for (int i = 1; i < 6; i++)
    {
        if (votos[i] > maior)
        {
            maior = votos[i];
            indiceVencedor = i;
        }
    }
    return indiceVencedor;
}

main()
{
    vector<string> candidatos = {"-", "Maria", "Jose", "Joao", "Pedro", "Julia"};
    vector<int> votos(6, 0);
    int escolha, totalVotos = 0;

    while (true)
    {
        cout << "Lista de Candidatos:\n";
        cout << "1 - Maria\n";
        cout << "2 - Jose\n";
        cout << "3 - Joao\n";
        cout << "4 - Pedro\n";
        cout << "5 - Julia\n";
        cout << "Escolha o candidato ou 0 para encerrar: ";
        cin >> escolha;

        if (escolha > 0 && escolha < 6)
        {
            votos[escolha]++;
            totalVotos++;
        }
        else if (escolha == 0)
        {
            break;
        }
        else
        {
            cout << "Opcao invalida! Tente novamente.\n";
            main();
        }
    }

    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "------votacao encerrada------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;

    cout << "Numero total de votos: " << totalVotos << endl;
    cout << "Votos dos candidatos: " << endl;
    for (int i = 1; i < 6; i++)
    {
        cout << i << " - " << candidatos[i] << ": " << votos[i] << " voto(s)" << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;

    int maior = 0;
    int numerovencedor = 0;

    int vencedor = acharVencedor(votos);

    cout << "O ganhador foi: " << candidatos[vencedor] << endl;
    cout << "Numero de votos: " << votos[vencedor] << endl;
}

