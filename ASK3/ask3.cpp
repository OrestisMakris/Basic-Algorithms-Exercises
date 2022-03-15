#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int left(int i)  //This function returns the left element of the heap.
{
    return (2*i+1);
}

int right(int i) //This function returns the right element of the heap.
{
    return (2*i+2);
}

void swapelements(int &x ,int &y) {//This function is used for swapping elements in this program
    int temp ;

    temp=x;
    x=y;
    y=temp;
}

int Heapify_down(int i , vector<int> &heap) 
{
    int L = left(i);
    int R = right(i);
    int Small;
    Small = i;
    int heapifysize;
    heapifysize = heap.size();

    if (L < heapifysize && heap[L]< heap[i])
    {
        Small= L;

    }
    if (L < heapifysize && heap[R]< heap[Small])
    {
        Small= R;
    }
    if (Small != i)
    {
        swapelements(heap[i] , heap[Small]);
        Heapify_down(Small , heap);
    }

}

int main()
{
	vector<int> heap;
	int heapsize1;

    ifstream inputFile("Heap.txt");        // Input file stream object


    if (inputFile.good())    // Check if file exists and then open it.
     {

        int current_number = 0;
        while (inputFile >> current_number)
        	heap.push_back(current_number); //and stores them in a vector

        inputFile.close();

        heapsize1=heap.size();
    }else {
        cout << "Error in reading file!";
        exit(0);
    }

    cout<<"The minimum value of the Minheap is: "<<heap[0]<<endl; // in the given minheap the minimum value is on the root of the heap tree

    swapelements(heap[0],heap[heapsize1-1]); //swap between the first and the last element of the vector (that contains the elements of the heap)

    heap.pop_back(); //Removes the last element of the vector.

    int i = Heapify_down(0, heap); //we call the function heapify_down to restructure our vector to represent a minheap. We pass the value zero witch is the index we want to start the application of the algorithm and the heap.


    cout << "The vector array after the heapify down algorithm is: ";
    for (int count = 0; count < heapsize1-1; count++){
       cout << heap[count] << " ";
    }
    cout << endl;
    cout<<"The last position of the swapped element is " <<i<<endl;

}
