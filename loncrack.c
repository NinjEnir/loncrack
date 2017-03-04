#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 25

int main(int argc, char *argv[])
{
	FILE *arq;
	arq = fopen(argv[1],"r");

	// declarando as variáveis - vetores
	char senha[BUFF + 50];
	char salt[BUFF];
	char comp[BUFF + 75];
	char tmp[BUFF + 75];
	char *p, *p1, *p2;
	char *result;

	// o hash vai ser armazenado em comp
	printf("Digite o Hash completo\n");
	scanf("%s", comp);

    strncpy(tmp, comp, BUFF+75);

    p = strtok(tmp, "$");
    p1 = p;
    p = strtok(NULL, "$");
    p2 = p;
    sprintf(salt, "$%s$%s$", p1, p2);

	int f = 0;

	while(fscanf(arq, "%s", &senha) != EOF) {
		result = (char *) crypt(senha, salt);
			if (strcmp(comp,result)==0)
			{
				printf("Senha encontrada: %s \n", senha);
				int f = 1;
				return(0);
			}
			else
			{
				printf("Testando.. %s \n", senha);
			}
	}

	if(f==0)
	{
		printf("Senha não encontrada..\n");
	}
}
