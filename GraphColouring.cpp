#include<iostream>

using namespace std;

int graph[8][8]; //value 8 can be changed
int myColour[8];  //value 8 can be changed

void getMatrix(int);
void getColour(int, int, int);
bool previous(int, int);
void printColour(int);

int main()
{
    int n;
    cout<<"Enter the Number of Vertex (MAX 8):";
    cin>>n;
    getMatrix(n);
    getColour(0, n, 0);
    printColour(n);
    return 0;
}

void getMatrix(int n)
{
    cout<<"Enter the adjacency Matrix (0|1):\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>graph[i][j];
}

void getColour(int row, int n, int colour)
{
    for(int col=0; col<n; col++)
    {
        if(col==row)
        {
            myColour[row] = colour;
            getColour(row+1, n, 0);
        }
        if(graph[row][col] && previous(col, colour))
        {
            colour++;
        }

    }

}

bool previous(int ele, int colour)
{
    if(myColour[ele]==colour)
        return true;
    return false;
}

void printColour(int n)
{
    cout<<"Vertex  Colour\n";
    for(int i=0; i<n; i++)
    {
        cout<<"  "<<i<<"\t  "<<myColour[i]<<endl;
    }
}
