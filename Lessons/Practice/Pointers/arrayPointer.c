void display ( int *q, int row, int col )
{
	int i, j ;
	for (i = 0 ; i < row ; i++ )
	{
		for (j = 0 ; j < col ; j++ )  
			printf("%d ",q[i*col+j]); //*(q+i*col+j)
		printf ( "\n" ) ;
	}
	printf ("\n" ) ;
}

int main(void)
{
	int a[3][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 6},
		{3, 4, 5, 7}} ;
		
	int numCols = sizeof(a[0]) / sizeof(int);
	int numRows = sizeof(a) / sizeof(a[0]);
	
	printf("numRows : %d\n", numRows);
	printf("numCols : %d\n", numCols);

	printf("Data:\n");
	display ( a[0], numRows, numCols ) ;
	print ( a, numRows, numCols ) ;
	
	return 1;
}

print (int q[][4], int row, int col)
{
	int i, j;
	for (i=0;i<row;++i)
	{
		for (j=0;j<col;++j)
		{
			printf("%d ",q[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
