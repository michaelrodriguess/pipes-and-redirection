#include <stdio.h>
#include <unistd.h>
// testando a funcao fork
int main(int argc, char **argv)
{
	int contador;
	contador = 1;
	//int id = fork();
		printf("Retorno filho: %i\n", ++contador);
	//if (id != 0)
		printf("Retorno pai: %i\n", --contador);
	return (0);

}
