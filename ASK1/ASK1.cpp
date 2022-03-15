#include <iostream>
#include <fstream> // To use ifstream
#include <vector>

using namespace std;


int main()
{
	vector<int> numbers;
	int i;

    ifstream inputFile("input.txt");        // Input file stream object


    if (inputFile.good())    // Check if file exists and then open it.
     {

        int current_number = 0;
        while (inputFile >> current_number)    // reads data from file stores the data in an array
        	numbers.push_back(current_number); //and stores them in a vector

        inputFile.close();  // Close the file.


        // Display the numbers read:
        i=numbers.size();
        cout << "The numbers are: ";
        for (int count = 0; count < i; count++){
           cout << numbers[count] << " ";
        }
        cout << endl;

    }else {
        cout << "Error in reading file!";
        exit(0);
    }

    int min =0;
    int max=0;
    min = numbers[0];
    max = numbers[0];
    int  min1;
    int  max1;
    for (int counter = 0; counter < i; counter++){
     if(numbers[counter]>max){
        max = numbers[counter];
        max1 = counter;

     }else if(numbers[counter]<min){
         min = numbers[counter];
        min1 = counter;
     }
    }

     numbers[max1]= numbers[i-1];
     numbers[i-1]= max;
     numbers[min1]= numbers[0];
     numbers[0]=min;

// stores the numbers in txt file using output file stram object
    ofstream outputfile;
    outputfile.open ("output.txt");
    for (int count = 0; count < i; count++){
    outputfile << numbers[count] << " ";
    }
    outputfile.close(); //close output file

    return 0;
}
