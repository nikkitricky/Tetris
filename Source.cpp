#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//just used to generate the random seed 
int size = 10;
int findend1(int arr[10][10], int row, int col){
	while (arr[row][col] != 0){
		col++;
	}
	return col - 1;
}
int findend0(int arr[10][10], int row, int col){
	while (arr[row][col] != 1){
		col++;
	}
	return col-1;
}
void rowdown(int arr[10][10], int row, int col){
	for (int i = row; row > 0; row--){
		arr[row][col] = arr[row - 1][col];
	}
	arr[row][col] = 1;
}
void slip(int arr[10][10], int row, int col){
	int end;
	if (arr[row][col]==0)
	end = findend0(arr, row, col);
	if (arr[row][col] == 1)
		end = findend1(arr, row, col);
	//printf("========%d=======", end);
	for (int i = col; i <= end; i++){
		printf("%d---------%d\n", row, i);
		rowdown(arr, row, i);
	}
}
void switcher(int arr[10][10], int row, int col){
	if (arr[row][col] == 0)
		arr[row][col] = 1;
	else
		arr[row][col] = 0;
}
int shrinker(int arr[10][10]){
	bool flag = true;
	for (int i = 0; i < size; i++){
		if (arr[0][i] == 0 || arr[i][0]== 0){
			flag=false;
		}
	}
	if (flag==true){
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				arr[i][j] = arr[i][j + 1];
			}
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				arr[i][j] = arr[i+1][j];
			}
		}
		return size - 1;
	}
	return size;
}
int main(){
	int row,col;
	int arr[10][10];
	srand(time(NULL));
	
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < 13; j++){
			arr[i][j] =  rand() % 2;
		}
	}
	while (size != 1){
		printf("Your matrix is: \n");
		for (int i = 0; i < size; i++){
			printf("%d--> ", i);
			for (int j = 0; j < size; j++){
				printf("%d  ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\nOptions:\n1)Slip row\n2)switch a value\n Enter your choice:");
		int choice = 0;
		scanf("%d", &choice);
		switch (choice){
		case 1:
			printf("Enter the row and column numbers of starting cell where you want to slip the column part,\nrow: ");
			scanf("%d", &row);
			while (row >= size){
				printf("Enter value less than %d", size);
				scanf("%d", &row);
			}
			printf("\ncolumn: ");
			scanf("%d", &col);
			while (col >= size){
				printf("Enter value less than %d", size);
				scanf("%d", &col);
			}
			slip(arr, row, col);
			break;
		case 2:
			printf("Enter the row and column numbers of cell where you want to switch its value,\nrow: ");
			scanf("%d", &row);
			while (row >= size){
				printf("Enter value less than %d", size);
				scanf("%d", &row);
			}
			printf("\ncolumn: ");
			scanf("%d", &col);
			while (col >= size){
				printf("Enter value less than %d", size);
				scanf("%d", &col);
			}
			switcher(arr, row, col);
			break;
		default: printf("Enter valid option!!!\n");
			break;
		}
		size=shrinker(arr);
		system("cls");
	}
	system("pause");
	return 0;
}