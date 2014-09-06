/*	
	not yet submitted
	main prints "Case #: 37" regardless of input.
	print_tree  returns "((null) x (null))" regardless of input.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int matrix_number;
	struct tree* left;
	struct tree* right;
} tree;

tree* new_node(void);

int MUL[10][10];
int PCE[10][10];
int M[10][2];

int foo(int start, int end, tree* ptr);
void free_branch(tree* ptr);
char* print_tree(tree* ptr);
void prep_GLB(void);

void main(){
	int N;
	int count;
	int casenum;
	casenum = 1;
	scanf("%d",&N);
	while(N){
		tree* ptr;
		char* output;
		printf("29\n");
		prep_GLB();
		ptr = new_node();
		printf("31\n");
		printf("Case %d: ",casenum++);
		for(count = 0; count < N; count++){
			scanf("%d",&M[count][1]);
			scanf("%d",&M[count][2]);
		}
		printf("37\n");
		foo(0,N,ptr);
		printf("39\n");
		output = print_tree(ptr);
		printf("41\n");
		printf("%s\n",output);
		free(output);
		printf("44\n");
		free_branch(ptr);
		printf("46\n");
		scanf("%d",&N);
	}
}

int foo(int start, int end, tree* ptr){
	if(start==end){
		if(ptr!=NULL) ptr->matrix_number = start++;
		return(0);
	}
	if(ptr!=NULL){
		printf("57\n");
		ptr->left = new_node();
		printf("59\n");
		ptr->right = new_node();
		printf("61\n");
	}
	if(MUL[start][end]>=0){
		printf("64\n");
		foo(start,PCE[start][end],ptr->left); //Infinite loop here.
		printf("66\n");
		foo(PCE[start][end]+1,end,ptr->right);
		printf("68\n");
		return(MUL[start][end]);
	unsigned int i, j, min, curr, place;
	place = 0;
	min--;
	for(i = start; i < end; i++){
		printf("74\n");
		curr = foo(start,i,NULL) + foo(i+1,end,NULL) + M[start][1]*M[i][2]*M[end][2];
		printf("76\n");
		if(curr<min){ 
			min = curr;
			place = i;
		}
	}
	if(ptr!=NULL){
		printf("83\n");
		foo(start,place,ptr->left);
		printf("85\n");
		foo(place+1,end,ptr->right);
		printf("87\n");
	       }
	MUL[start][end] = min;
	PCE[start][end] = place;
	return(min);
	}
}
	
char* print_tree(tree* ptr){
	char* S;
	printf("97\n");
	S = (char*)malloc(sizeof(char)*100);
	printf("99\n");
       if(ptr->matrix_number){
	       sprintf(S,"A%d",ptr->matrix_number);
	       return(S);
       }
       if(ptr->left!=NULL&&ptr->right!=NULL){
	       char* L;
	       char* R;
	       printf("107\n");
	       L = print_tree(ptr->left);
	       printf("109\n");
	       R = print_tree(ptr->right);
	       printf("111\n");
	       sprintf(S,"(%s x %s)",L,R);
	       free(L);
	       printf("114\n");
	       free(R);
	       printf("116\n");
	       return(S);
       }
       if(ptr->left!=NULL){
	       char* L;
	       printf("121\n");
	       L = print_tree(ptr->left);
	       printf("123\n");
	       sprintf(S,"(%s",L);
	       free(L);
	       printf("126\n");
	       return(S);
       }
       if(ptr->right!=NULL){
	       printf("130\n");
	       char* R;
	       R = print_tree(ptr->right);
	       printf("133\n");
	       sprintf(S,"%s)",R);
	       free(R);
	       printf("136\n");
	       return(S);
       }
}


tree* new_node(void){
	tree* ptr;
	printf("144\n");
	ptr = (tree*)malloc(sizeof(tree));
	printf("146\n");
	ptr->matrix_number = 0;
	ptr->left = NULL;
	ptr->right = NULL;
	return(ptr);
}

void free_branch(tree* ptr){
	printf("154\n");
	if(ptr!=NULL){
		printf("156\n");
		free_branch(ptr->left);
		printf("158\n");
		free_branch(ptr->right);
		printf("160\n");
		free(ptr);
		printf("162\n");
	}
}

void prep_GLB(void){
	int i, j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			MUL[i][j] = -1;
			PCE[i][j] = -1;
		}
	}
}
