#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void mergeArrays(vector<int>&  array1, vector<int>&  array2, int sizearray1, int sizearray2,vector<int>& array3  )
{

    int i = 0, j = sizearray2-1;

    while (i<sizearray1 && j >=0 )
    {
        if (array1[i] < array2[j])
            array3.push_back(array1[i++]);
        else
            array3.push_back(array2[j--]);

    }


    while (i < sizearray1)
       array3.push_back(array1[i++]);

    while (j >=0 ){
        array3.push_back(array2[j--]);
    }

}

int binarySearch(vector<int>& array3, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (array3[mid] == x)
            return mid;

        if (array3[mid] > x)
            return binarySearch(array3, l, mid - 1, x);


        return binarySearch(array3, mid + 1, r, x);
    }

    return -1;
}

int main()
{
	vector<int> array1;
	int sizearray1;
    vector<int> array2;
	int sizearray2;

    ifstream inputFile1("Array1.txt");

    if (inputFile1.good())
     {
        int current_number = 0;
        while (inputFile1>> current_number)
        	array1.push_back(current_number);

        inputFile1.close();  // Close the file.

        sizearray1 =array1.size();

    }else {
        cout << "Error in reading file!";
        exit(0);
    }

    ifstream inputFile2("Array2.txt");

     if (inputFile2.good())
     {

        int current_number = 0;
        while (inputFile2>> current_number)
        	array2.push_back(current_number);

        inputFile2.close();

        sizearray2 =array2.size();

    }else {
        cout << "Error in reading file!";
        exit(0);
    }

 int x;
 cout << "Give the number you want to find";
 cin >> x;

    vector<int>  array3;
     mergeArrays(array1,array2,sizearray1,sizearray2,array3);

    int sizearray3 =array3.size();

    cout << "The new combine: ";
        for (int count = 0; count < sizearray3 ; count++){
            cout << array3[count] << " ";
        }
        cout << endl;

  int result = binarySearch(array3, 0, sizearray3 - 1, x);
  (result == -1) ? cout << "Element is not present in array False"
                   : cout << "True Element is present at index " << result;
 return 0;
}