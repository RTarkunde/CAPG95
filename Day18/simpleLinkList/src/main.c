#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <string.h>

typedef struct _node
{
	int empId ;
	char name[100];
	char last_name[100];
	struct _node *next;
} node;

int main(int argc, char** argv)
{
	//node *head ; 
	//head = malloc(sizeof(struct _node));
	FILE* fp = fopen("numbers.txt", "r");
	node *head;
	char lineBuffer[300];
	char* token ;

	head = malloc(sizeof(struct _node));
	node* iter = head;
	fgets(lineBuffer, 300, fp); 
    token = strtok (lineBuffer, ",");
    iter -> empId = atoi(token);

    token = strtok (NULL, ",");
    strcpy(iter -> name, token);

    token = strtok (NULL, ",");
    strcpy(iter -> last_name, token);

	while(fgets(lineBuffer, 300, fp) != NULL)
	{
		iter->next = malloc(sizeof(struct _node));
		token = strtok (lineBuffer, ",");
		iter -> next -> empId = atoi(token);

		token = strtok (NULL, ",");
		strcpy(iter -> next-> name, token);

		token = strtok (NULL, ",");
		strcpy(iter -> next-> last_name, token);
		iter = iter -> next;
	}
	iter -> next = NULL ;

	fclose(fp);

	int nodeNo = 1;
	node* iterator = head;	
	while(iterator != NULL)
	{
		printf("node%d empId and name is %d %s %s", nodeNo, iterator->empId, iterator->name, iterator->last_name);
		iterator = iterator->next;
		nodeNo++;
	}

	iterator = head;
	while(iterator != NULL)
	{
		node* temp = iterator->next;
		free(iterator);
		iterator = temp;
	}	

	return EXIT_SUCCESS;
}
