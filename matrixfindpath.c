#include <stdio.h>
#include <stdlib.h>
int countPath=0;
void traverse(int**,int,int,int,int);
void main()
{
        int row,col;
        int **array;
        scanf("%d %d",&row,&col);
        array = (int**) malloc(sizeof(int)*row);
        for(int i=0;i<row;i++)
                array[i] = (int*) malloc(sizeof(int)*col);
        for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                        scanf("%d",&array[i][j]);
        traverse(array,row,col,0,0);
        printf("Total no.of paths= %d\n",countPath);
}
void traverse(int **array,int maxRow,int maxCol,int currRow, int currCol)
{
        if(currRow >= maxRow || currCol >= maxCol)
                return;
        else if(array[currRow][currCol] == 0)
                return;
        else if(currRow == (maxRow-1) && currCol == (maxCol-1))
        {
                countPath+=1;
                return;
        }
        else
        {
                traverse(array,maxRow,maxCol,currRow,currCol+1);
                traverse(array,maxRow,maxCol,currRow+1,currCol);
        }
}
