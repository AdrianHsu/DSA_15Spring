#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "avl.h"

#define MAX_STRLEN 150 //128 as MAX

void  preorder_integer_avl(const struct avl_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", (char *)node->avl_data);
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL)
	{
		putchar('(');
		preorder_integer_avl(node->avl_link[0]);
		putchar(',');
		preorder_integer_avl(node->avl_link[1]);
		putchar(')');
	}
}
int dic_compare(const void *pa, const void *pb, void * param)
{
	const char* str1 = (const char*)pa;
	const char* str2 = (const char*)pb;	

	const int str1_len = strlen(str1);
	const int str2_len = strlen(str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	int i = 0;
	while(1)
	{
		if(i == str1_len && i == str2_len)
			return 0;

		if(i == str1_len)
			return -1;
		else if(i == str2_len)
			return +1;

		if(str1[i] < str2[i])
			return +1;
		else if(str1[i] > str2[i])
			return -1;
		else
			i++;
	}
	printf("ERROR\n");
	return 0;

}

/*int int_compare(const void *pa, const void *pb, void * param)
{
	int a = *(const int*)pa;
	int b = *(const int*)pb;
	if(a < b) return -1;
	else if (a > b)return +1;
	else return 0;
}*/

int main(){
	
	struct avl_table *tree ;
	tree = avl_create(dic_compare , NULL, NULL);
	
	char S1 [MAX_STRLEN];
	while(scanf("%s", S1) == 1)
	{
		void** p = avl_probe(tree, S1);
	}
	preorder_integer_avl(tree->avl_root);
	puts("");
	return 0 ;
}