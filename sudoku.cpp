// Felipe Lages de Lima
// Github Felps-LDL

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << "x = " << x << endl;
#define ll long long
#define pii pair<int, int> 
#define piii pair<int, pair<int,int>>
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MAXN 600
 
using namespace std;

int sudoku[9][9];

bool possivel(int linha, int coluna, int valor)
{
    // Varia pela linha e pela coluna procurando pelo valor pra ver se pode ou não ser inserido
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][coluna] == valor || sudoku[linha][i] == valor) return false;
    }

    int linha_inicial = linha - linha % 3, coluna_inicial = coluna - coluna % 3;

    // Varia pelo quadrante procurando pelo valor pra ver se pode ou não ser inserido
    for (int i = linha_inicial; i < linha_inicial + 3; i++)
    {
        for (int j = coluna_inicial; j < coluna_inicial + 3; j++)
        {
            if (sudoku[i][j] == valor) return false;
        }
    }

    return true;
}

bool solution(int linha, int coluna)
{
    // Algoritmo que vai preenchendo os quadrados o máximo que conseguir e retornará falso caso não seja uma solução correta

    // Se tiver na última coluna então devemos verifica se existe próxima linha para pular, se não existir então retornará true, pois conseguimos nossa solução correta!
    if (coluna == 9)
    {
        if (linha == 8) return true;

        linha++;
        coluna = 0;
    }

    // Já existe um valor nesse quadrado
    if (sudoku[linha][coluna] != 0) return solution(linha, coluna + 1);

    for (int valor = 1; valor <= 9; valor++)
    {
        if (possivel(linha, coluna, valor))
        {
            sudoku[linha][coluna] = valor;
            if (solution(linha, coluna + 1)) return true; // se o valor tiver no quadrado correto retorna true

            sudoku[linha][coluna] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Digite os valores do sudoku:\n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) cin >> sudoku[i][j];
    }

    solution(0, 0);

    cout << "Resposta: \n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) cout << sudoku[i][j];
        cout << endl;
    }

    return 0;
}
