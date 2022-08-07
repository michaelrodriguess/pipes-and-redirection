//	[0]->Nome do Programa
//	[1]->Nome do arquivo de input(infile)
//	[2]->Comando 1
//	[3]->Comando 2
//	[4]->Nome do arquivo de Output(outfile)
//	.\pipex infile cat rev outfile
//	   [0]   [1]   [2] [3]   [4]

// testando a funcao pipe conversando com a Funcao Fork.

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int pipefd[2];
	int pid;

	if(pipe(pipefd) == -1)
	{
		printf("Ocorreu um erro com a abertura do pipe\n");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		int x;
		printf("input a number: ");
		scanf("%d", &x);
		write(pipefd[1], &x, sizeof(int));
		close(pipefd[1]);
	}
	else 
	{
		close(pipefd[1]);
		int y;
		read(pipefd[0], &y, sizeof(int));
		close(pipefd[0]);
		printf("Esse dados veio do processo filho -> %d\n", y);
	}
	return (0);
}
