#include <bits/stdc++.h>
using namespace std;


/*
  dadas duas listas (lista1 vai de inf até mid **** lista2 vai de mid+1 ate sup)
  ordena num vetor auxiliar e conta o nro de inversoes......
*/
long long merge (int *vet, int inf, int mid, int sup){
 	
	int i = inf;      // indice da lista 'A'
 	int j = mid+1;   // indeice da lista 'B'
 	// precisamos de um vetor aux para ordenar 
 	int k = 0;
 	int aux[sup-inf+1]; // o vetor auxiliar
 	
 	long long count = 0;

 	// Enquanto tem elementos em AMBAS as listas
 	while(i<=mid && j<=sup){
 		if (vet[i] <= vet[j])  
 			aux[k++] = vet[i++];
 		else{   // encontrei uma inversao
 			  aux[k++] = vet[j++];
 			  count = count + (mid-i +1);  // incrementa count com o tamanho do resto da lista 'A'
 		}
 	}

 	// copia os remanescentes de ambas as listas
 	// lista 'A'
 	while(i<=mid)
 		aux[k++] = vet[i++];

 	// lista 'B'
 	while(j<=sup)
 		aux[k++] = vet[j++];

 	// tem que atualizar o vetor original
 	for (int i = inf, k = 0; i <= sup; i++, k++)
 		vet[i] = aux[k];
 	return count;

}


long long inv(int *vet, int inf, int sup){
	// se a lista tem tam 1
	if (inf == sup)
		return 0;

	int mid = (inf+sup)/2;

	long long qtdesq = inv(vet, inf, mid);      //  T(n/2)
	long long qtddir = inv(vet, mid+1, sup);    // T(n/2)
	long long qtdmer = merge(vet, inf, mid, sup);


	return qtdesq + qtddir + qtdmer;
}


int main()
{
	
	int n;
	while(cin >> n){
        if(n == 0)
            break;

        int vet[n];

        for (int i = 0; i < n; ++i)
            cin >> vet[i];


        cout << inv(vet, 0, n-1) << endl;
    }

	return 0;
}