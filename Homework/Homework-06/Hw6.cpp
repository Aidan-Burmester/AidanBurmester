#include <iostream>

// Function to find numbers that appear in both arrays 

void findMatches(const int a[], size_t sizeA, const int b[], size_t sizeB)
{
    for(size_t i = 0; i < sizeA; ++i)
    {
        for(size_t j = 0; j < sizeB; ++j)
        {
            if(a[i] == b[j])
            {
                std::cout << a[i] << " ";
                break; 
                // prevent duplicate prints 
            }
        }
    }
}

int main()
{
    int data[]  {1,3,6,7,9};
    int data1[] {5,3,3,11,0};   

    // get array size 

    size_t size = sizeof(data) / sizeof(data[0]);

    // Swap the data between arrays 

    for(size_t i = 0; i < size; ++i)
    {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    // Print swapped arrays 

    std::cout << "data: ";
    for(size_t i = 0; i < size; ++i)
        std::cout << data[i] << " ";

    std::cout << "\ndata1: ";
    for(size_t i = 0; i < size; ++i)
        std::cout << data1[i] << " ";

    // Find matching numbers 

    std::cout << "\nMatching numbers: ";
    findMatches(data, size, data1, size);

    std::cout << std::endl;

    return 0;
}