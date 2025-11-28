#include <iostream>
#include <vector>
using namespace std;

int apurar(vector<int> votos)
{
    int vencedor = 1;
    for (int i = 1; i < 6; i++)
    {
        if (votos[i] > votos[vencedor])
        {
            vencedor = i;
        }
    }
    return vencedor;
}

int encerrar(vector<int> votos, vector<string> nome, int total)
{
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "------ VOTACAO ENCERRADA ----" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;

    cout << "Numero total de votos: " << total << endl;
    cout << "Votos dos candidatos:" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << i << " - " << nome[i] << ": " << votos[i] << " voto(s)" << endl;
    }

    int vencedor = apurar(votos);

    cout << "O ganhador foi: " << nome[vencedor] << endl;
    cout << "Numero de votos do(a) ganhador(a): " << votos[vencedor] << endl;
}

int main()
{
    vector<string> candidatos = {"-", "Maria", "Jose", "Joao", "Pedro", "Julia"};
    vector<int> votos(6, 0);

    int escolha;
    int totalVotos = 0;

    while (true)
    {
        cout << "Lista de Candidatos:" << endl;
        cout << "1 - Maria" << endl;
        cout << "2 - Jose" << endl;
        cout << "3 - Joao" << endl;
        cout << "4 - Pedro" << endl;
        cout << "5 - Julia" << endl;
        cout << "Escolha o candidato ou 0 para encerrar: ";
        cin >> escolha;

        if (escolha > 0 && escolha < 6)
        {
            votos[escolha]++;
            totalVotos++;
        }
        else if (escolha == 0)
        {
            encerrar(votos, candidatos, totalVotos);
            break;
        }
        else
        {
            cout << "Tente uma opçao valida" << endl;
        }
    }
}