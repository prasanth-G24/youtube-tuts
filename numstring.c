#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    char string[10];
    Node *left;
    Node *right;
};
char *alphabet[27]= {"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
Node* insert(int alpha_value, char substr[], int array[], int string_length, int array_length)
{
        if(alpha_value>26)
                return NULL;
        Node *temp = (Node*) malloc(sizeof(Node));
        char *tempstring = (char*) malloc(string_length+1);
        strcpy(tempstring,substr);
        strcat(tempstring,alphabet[alpha_value]);
        strcpy(temp->string,tempstring);
        if(array_length > 0)
        {
                alpha_value = array[0];
                int *subarray = &array[1];
                temp->left = insert(alpha_value, tempstring, subarray, strlen(tempstring), array_length-1);
                if(array_length>1)
                {
                        alpha_value = array[0]*10+array[1];
                        subarray = &array[2];
                        temp->right = insert(alpha_value, tempstring, subarray, strlen(tempstring), array_length-2);
                }
        }
}
void print(Node *root)
{
        if(root==NULL)
                return;
        else if(root->left==NULL && root->right==NULL)
        {
                puts(root->string);
        }
        else
        {
                print(root->left);
                print(root->right);
        }
}
void main()
{
        int digits;
        scanf("%d",&digits);
        int *array = (int*) malloc(sizeof(digits * sizeof(int)));
        for(int i=0;i<digits;i++)
                scanf("%d",&array[i]);
        Node *root = insert(0, "", array, 0, digits);
        print(root);
}
