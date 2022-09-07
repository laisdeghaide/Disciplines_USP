#include <bits/stdc++.h>
using namespace std;


#define MAX 8
int rows[8]; // guarda a linha que cada rainha ocupa na coluna de 0-7
int results[20]; // resultado de todos os possiveis 20 tabuleiros
int scores[8][8]; // pontação do tabuleiro
int total_score, sum;

// verifica se a rainha a ser colocada nao conflita com as que ja existem
bool valid(int row, int col){
	for (int i=0; i<col; i++) { 
        if (rows[i] == row || (abs(rows[i]-row) == abs(i-col)))
			return false;
    }
		
	return true;
}


void backtracking(int col){
	// se já passei por todas as colunas..
    if (col == MAX) {
		total_score = max(total_score, sum);
        return;
    }

    else {
		//para todas as linhas
		for (int row=0; row<MAX; row++)
			if (valid(row, col)){
				rows[col] = row;
                sum += scores[row][col];
				backtracking(col+1);

                rows[col] = -1;
                sum -= scores[row][col];
			}
	}
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                cin >> scores[i][j];
            }
        }

        total_score = 0, sum = 0;
        backtracking(0);

        cout << setw(5) << setiosflags(ios::right) << total_score << endl;
    }

    return 0;
}