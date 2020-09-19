#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{
	char palavra[51];
} string;

typedef struct{
	char saida[51];
} saida;     //Para matrizes de strings

int main (){

	int casos, aux, tam;
	int maior, atual, i, j, k;

	scanf("%d", &casos);
	while (1){	

		if (casos == 0) break;

		aux = casos;
		string palavra[aux];
		saida textoSaida[aux];
		i = 0;

		while (casos--) scanf(" %[^\n]", palavra[i++].palavra); //Lê as entradas até o quebrador de linha

		i = 0;
		tam = aux;

		while (aux--){
			j = 0;
			k = 0;
			while (1){
				while (isalpha(palavra[i].palavra[j])) textoSaida[i].saida[k++] = palavra[i].palavra[j++];

				if (palavra[i].palavra[j] == '\0') break; //Se o caractere que fez o while parar foi o caractere de final, a string terminou, para-se o laço externo

				while (!isalpha(palavra[i].palavra[j])){	
					j++;
					if (palavra[i].palavra[j] == '\0') break;
				}

				if (palavra[i].palavra[j] == '\0') break; //Mesma ideia do comentario anterior

				textoSaida[i].saida[k++] = ' '; //separar uma palavra e outra;
			}

				textoSaida[i].saida[k] = '\0'; //Caractere nulo final da string
				i++;
		}	
				maior = 0;

				for(i = 0; i < tam; i++){
					atual = strlen(textoSaida[i].saida);
					if (atual > maior)
						maior = atual;
				}

		for (i = 0; i < tam; i++) printf("%*s\n", maior, textoSaida[i].saida); //Resposta justificada

		scanf("%d", &casos);
		if(casos != 0) printf("\n");
	}
    return 0;
}			