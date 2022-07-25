#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int id = fork();
	if (id == 0)
		fork();
	if (id == 0)
		printf("hello2\n");
	return (0);

}
