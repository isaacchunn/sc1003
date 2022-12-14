//
//  Tut3.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 17/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COL 4
#define SIZE 10
#define MINMAXSIZE 5

void question1(void);
void question2(void);
void question3(void);
void question4(void);
void question5(void);
void display(int* ar, int size);
void display2d(int ar[][SIZE], int rowSize, int colSize);

enum QUESTIONS
{
    QUESTION1 = 0,
    QUESTION2,
    QUESTION3,
    QUESTION4,
    FIND_MIN_MAX_2D,
    MAX_QUESTIONS
};

int main()
{
    srand(time(NULL));
    enum QUESTIONS questions = QUESTION2;
    switch (questions)
    {
        case QUESTION1:
            question1();
            break;
        case QUESTION2:
            question2();
            break;
        case QUESTION3:
            question3();
            break;
        case QUESTION4:
            question4();
            break;
        case FIND_MIN_MAX_2D:
            question5();
            break;
        default:
            break;
    }
    
    /*
    char arr[2][2] = {{'d','e'},
                    {'h','f'}};
    int l,m;
    for(l=0; l < 2; l++)
    {
        for (m=0; m<2; m++)
        {
            printf("%c ", arr[l][m]);
        }
        printf("\n");
    }
    
    
    int b,o;
    for(b = 0; b < 2; ++b)
    {
        for (o = 0; o < 2; ++o)
        {
            printf("%p, %c\n",*(arr+b)+o, *(*(arr+b)+o));
        }
    }
    putchar('\n');
    printf("d%p, %c\n", arr, *(*(arr+0)+0));
    printf("%p, %c\n", *(arr+1), *(*(arr+0)+0));
    putchar('\n');
    printf("%p, %c\n", arr, *(*(arr+0)+0));
    printf("%p, %c\n", *(arr+0)+1, *(*(arr+0)+1));
    printf("%p, %c\n", *(arr+1) + 0,*(*(arr+1)+0));
    printf("%p, %c\n", *(arr+1)+1, *(*(arr+1)+1));
    putchar('\n');
    printf("%p, %c\n", &arr[0][0],arr[0][0]);
    printf("%p, %c\n", &arr[0][1],arr[0][1]);
    printf("%p, %c\n", &arr[1][0],arr[1][0]);
    printf("%p, %c\n", &arr[1][1],arr[1][1]);
     */
    return 0;
}
/******************************************************************************/
/*!
\brief
Function for question 1.
\exception None
\return None
*/
/******************************************************************************/
void question1(void)
{
    //Function prototype
    void add1(int ar[], int size);
    
    int array[ROWS][COL];
    int row,col;
    
    for (row =0; row < ROWS; row++) //Rows
    {
        for (col= 0; col < COL; col++) //Cols
        {
            scanf("%d", &array[row][col]);
        }
    }
    printf("Array[0] = %d ", *array[0]);
    
    //Adds 1 to every col in a row.
    for (row = 0; row < ROWS; row++)
    {
        add1(array[0],ROWS* COL);
    }
    
    //Prints...
    for(row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%10d", array[row][col]);
        }
        putchar('\n');
    }
}
/******************************************************************************/
/*!
\brief
Function for question 2
\exception None
\return None
*/
/******************************************************************************/
void question2(void)
{
    void collectDistribution(int * numberList, int * rangeList, int size);
    void printHistogram(int * distribution, int size);
    /*Write a program which will draw the histogram for n integers from 0 to 99.  N is input by
    the user.  Each of the n numbers will be generated by calling rand() % 100.  The program
    will consist of two functions (i) to collect the frequency distribution of the numbers (ii) to
    print the histogram.  An example histogram is shown here.*/
    //Get the user's input first
    int num, i;
    printf("Enter histogram number? [Up to 100]: "); // dk what to put tbh

    //Set some limits on histogram numbers.
   
    scanf("%d", &num);
    while(0 <= num && num >100)
    {
        printf("That input was too high. Input again.");
        scanf("%d", &num);
    }
    
    //Randomly generate and store in a list. Hard cap 100 to get by integer constants for now not gonna do malloc
    int numberList[100];
    //Construct a 1d array that stores it in order.
    //There are 10 ranges , 0-9, 10-19..
    int rangeList[10];
    //Initialize all to 0.
    for (i = 0; i < 10; ++i)
        rangeList[i] = 0;
    
    //Randomise a list of numbers and store in numberList
    for (i =0; i < num; ++i)
    {
        numberList[i] = rand() % 100;
    }
    //Display the current numberList
    //display(numberList, num);
    //Collect the distribution
    collectDistribution(numberList, rangeList, num);
    //display(rangeList,10);
    //Then we print the histogram
    printHistogram(rangeList, 10);
  
}
/******************************************************************************/
/*!
\brief
Function for question 3
\exception None
\return None
*/
/******************************************************************************/
void question3(void)
{
    void tranpose2D(int ar[][SIZE], int rowSize, int colSize);
    
    int ar[SIZE][SIZE], rowSize,colSize;
    int i,j;
    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0;i<rowSize; i++)
        for (j =0; j <colSize; j++)
            scanf("%d", &ar[i][j]);
    printf("transpose2D(): \n");
    tranpose2D(ar, rowSize, colSize);
    display2d(ar,rowSize,colSize);
}
/******************************************************************************/
/*!
\brief
Function for question 4
\exception None
\return None
*/
/******************************************************************************/
void question4(void)
{
    void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
    
    int ar[SIZE][SIZE], rowSize,colSize;
    int i,j;
    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0;i<rowSize; i++)
        for (j =0; j <colSize; j++)
            scanf("%d", &ar[i][j]);
    reduceMatrix2D(ar, rowSize, colSize);
    printf("reduceMatrix(): \n");
    display2d(ar,rowSize,colSize);
}
/******************************************************************************/
/*!
\brief
Function for question 5

\param x1: reference to x-coordinate of 1st point
\param y1: reference to y-coordinate of 1st point
\param x2: refernece to x-coordinate of 2nd point
\param y2: reference to y-coordinate of 2nd point
\exception None
\return None
*/
/******************************************************************************/
void question5(void)
{
    void findMinMax2D(int ar[MINMAXSIZE][MINMAXSIZE], int *min, int *max);
    
    int A[5][5];
    int i, j, min, max;
    
    printf("Enter the matrix data (%dx%d): \n", MINMAXSIZE, MINMAXSIZE);
    for (i =0; i < 5; i++)
    {
        for(j= 0; j < 5; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    findMinMax2D(A, &min, &max);
    printf("min = %d\nmax = %d", min, max);
}

/******************************************************************************/
/*!
\brief
Adds 1 to every index in the array up to size.
\param ar[]: input int array
\param size: size of input ar
\exception None
\return None
*/
/******************************************************************************/
void add1(int ar[], int size)
{
    int k = 0;
    for (k= 0; k < size; k++)
    {
        printf("%d", ar[k]);
        ar[k]++;
    }
}
/******************************************************************************/
/*!
\brief
Displays the elements of an int array up to user input size

\param ar: input int array
\param size: user input size of array
\exception None
\return None
*/
/******************************************************************************/
void display(int * ar, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        (i != size- 1) ? printf("%d,",ar[i]) : printf("%d",ar[i]);
    }
    putchar('\n');
}

/******************************************************************************/
/*!
\brief
Reads numberList up to size, and collects the distribution of numbers and plots it back into rangeList

\param numberList: numberList
\param rangeList: rangeList
\param size: size
\exception None
\return None
*/
/******************************************************************************/
void collectDistribution(int * numberList, int * rangeList, int size)
{
    int n, currentNo;
    //Loop through to find range.
    for (n = 0; n < size; ++n)
    {
        //Take / 10 of the numbers.
        currentNo = numberList[n] / 10;
        //We then plus this to the range.
        rangeList[currentNo]+=1;
    }
}
/******************************************************************************/
/*!
\brief
Prints a histogram like shape according to distribution and size

\param distribution: distribution array
\param size: size of distribution array 
\exception None
\return None
*/
/******************************************************************************/
void printHistogram(int * distribution, int size)
{
    int i, j;
    //Take in the distribution array and print accordingly.
    for (i = 0; i < size; ++i)
    {
        //Print the current range first
        printf("%d %c %d\t|", i * size, '-',  (i * 10) + (size-1));
        for (j = 0; j < distribution[i]; ++j)
        {
            printf("*");
        }
        //Enter new line
        putchar('\n');
    }
}
/******************************************************************************/
/*!
\brief
Transposes a 2D array and returns 

\param ar: 2d array to transpose
\param rangeList: number of rows
\param size: number of cols
\exception None
\return None
*/
/******************************************************************************/
void tranpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    //Diagonal lines are always consistent.
    int x,y, temp;
    for (x = 1; x < rowSize; ++x)
    {
        for (y = 0; y < x; ++y)
        {
            temp = ar[x][y];
            ar[x][y] = ar[y][x];
            ar[y][x] = temp;
        }
    }
}

/******************************************************************************/
/*!
\brief
Prints out the elements of a 2D array ar.

\param ar: input array
\param rowSize: number of rows
\param colSize: number of cols
\exception None
\return None
*/
/******************************************************************************/
void display2d(int ar[][SIZE], int rowSize, int colSize)
{
    int l,m;
    for(l=0; l < rowSize; l++)
    {
        for (m=0; m<colSize; m++)
        {
            printf("%d ", ar[l][m]);
        }
        printf("\n");
    }
}
/******************************************************************************/
/*!
\brief
Reduces a 2d matrix and creates a upper triangular matrix. Loss function.

\param ar: input array
\param rowSize: number of rows
\param colSize: number of cols
\exception None
\return None
*/
/******************************************************************************/
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    /*To convert an upper triangluar matrix, the amount of Zeros is i-1.
    That would mean that for example 4 by 4
     4 3 8 6        27 3 8 6
     9 0 6 5 ->>     0 9 6 5
     5 1 2 4         0 0 5 4
     9 8 3 7         0 0 0 7  , there are  n-1 zeros in 1st col, n-2... etc etc..
    */
    
    //Given an array, we find the sum of up to n col for each row to create this triangular matrix.
    int row, col, sum, currentRow;
    currentRow = 0;
    //Loop through the array through col col
    for (col =0; col < colSize; ++col)
    {
        //Reset sum to 0 each time.
        sum = 0;
        for (row = col; row < rowSize; ++row)
        {
            sum += ar[row][col];
            //Set value to be 0 to maek it upper triangular.
            ar[row][col] = 0;
        }
        ar[currentRow][col] = sum;
        currentRow ++;
    }
}

/******************************************************************************/
/*!
\brief
Finds the min and max values of a given 2D array

\param ar: input array
\param min: address of min value
\param max: address of max value
\exception None
\return None
*/
/******************************************************************************/
void findMinMax2D(int ar[MINMAXSIZE][MINMAXSIZE], int *min, int *max)
{
    int i, j;
    //Set min and max to the first index of ar.
    *min = **ar;
    *max = **ar;
    //Do it by indexing and pointer constants
    //Indexing
    for (i = 0; i <MINMAXSIZE; ++i)
    {
        for (j = 0; j < MINMAXSIZE; ++j)
        {
            //Compare min and max against current value.
            if (*min > ar[i][j])
                *min = ar[i][j];
            else if (*max < ar[i][j])
                *max = ar[i][j];
        }
    }
}