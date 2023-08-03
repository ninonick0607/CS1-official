#include <string.h>
#include <stdio.h>

void consume_new_line()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void call_string_func1()
{
	char name[30];  
	printf("Enter your name: ");  
	consume_new_line();
	scanf("%s",name);
	printf("\n\tYour name is : %s\n",name);	
}

void call_string_func2()
{
	char name[30];  
	fprintf(stdout,"Enter your name: ");  
	consume_new_line();
	fscanf(stdin,"%s",name);
	fprintf(stdout,"\n\tYour name is : %s\n",name);	
}

void call_string_func3()
{
	char name[30];  
	puts("Enter your name: ");  
	consume_new_line();
	gets(name);
	printf("\tYour name is : ");
	puts(name);	
}

void call_string_func4()
{
	char name[30];  
	fputs("Enter your name: ",stdout);  
	consume_new_line();
	fgets(name, 30, stdin);
	printf("\tYour name is : ");
	fputs(name, stdout);	
}

int main(void)
{
	char c = '\0';
	do
	{
		printf("\nInput the method number as 1, 2, 3, 4 or q to exit\n");
		c = getchar();
		if (c == 'q')
			break;
		switch(c)
		{
			case '1':
				call_string_func1();
				break;
			case '2':
				call_string_func2();
				break;
			case '3':
				call_string_func3();
				break;
			case '4':
				call_string_func4();
				break;
			default:
				printf("Wrong input, please try again\n");
		}
	} while (1);
	return 1;
}