#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <chrono> 
#include "props.hpp"

// Swap
void swapper(int *a, int *b)
{
  int tmp = *a; // temp var is a
  *a = *b; // a is b
  *b = tmp; // b is temp
}

// Pivot partition
int pivotPartition(std::vector<int> vec, int start, int end)
{
  int pivot = vec[end];
  // Rightmost element is pivot
  int i = start -1; // Pointer for greater element
  // Traverse array elements and compare with pivot element
  for (int j = start; j < end; j++)
  {
    if (vec[j] <= pivot)
    {
      i++; // If element smaller than pivot is found, swap it with the greater element
      swapper(&vec[i], &vec[j]);
    }
  }
  swapper(&vec[i+1], &vec[end]); // Swap pivot with the greater element at i

  return (i+1); // Return the index of the pivot
}

// Quicksort
void quicksort(std::vector<int> vec, int start, int end)
{
  if (start < end) // If there is anything to sort
  {
    int pIndex = pivotPartition(vec, start, end); // Find the pivot index

    quicksort(vec, start, pIndex - 1); // Recursive call to the left of the pivot
    quicksort(vec, pIndex + 1, end); // Recursive call to the right of the pivot
  }
}

std::vector<int> makeLines()
{
  std::vector<int> madeLines;
  for(int i = 0; i < vecSize; i++) 
  {
  madeLines.push_back(i+1);
  }
  return madeLines;
}

std::vector<int> shuffler(std::vector<int> vec)
{
  int siz = vec.size();
  for (int i = 0; i < siz - 1; i++)
    {
        int j = i + rand() % (siz - i);
        std::swap(vec[i], vec[j]);
    }
  return vec;  
}


int main()
{
  std::vector<int> Lines;

  Lines = makeLines();

  Lines = shuffler(Lines);

  for (int i = 0; i < Lines.size(); i++)
  {
    std::cout << Lines[i] << std::endl;
  }

  std::cout << "============================" << std::endl;
 
  quicksort(Lines, 0, Lines.size() - 1);

  for (int i = 0; i < Lines.size(); i++)
  {
    std::cout << Lines[i] << std::endl;
  }
}























/*
int window_height = 1000;
int window_width = 1000;


int lineWidth = 1;


int Sizer = floor(window_width / lineWidth);

std::vector<int> Lines;
int States[3];
int vecSize = Lines.size();

template <typename S>
std::ostream& operator<<(std::ostream& os,
                    const std::vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

void swapper(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int pivotPartition (std::vector<int> vec, int start, int end)
{
    int pivot = arr[end);
    int i = (start - 1);  

    for (int j = start; j <= end- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j) <= pivot)
        {
            i++;    // increment index of smaller element
            swapper(&arr[i), &arr[j));
        }
    }
    swapper(&arr[i + 1), &arr[end));
    return (i + 1);
}
// Make lines function
void makeLines(std::vector<int> vec)
{
  // Generate increasingly taller lines to end of screen
  for (int i = 0; i <= vecSize; i++)
  {
      vec.push_back(lineWidth*i);
  }
}

void randomizeLines(std::vector<int>)
{
  shuffle(std::begin(Lines), std::end(Lines), std::default_random_engine{});
}

void quickSort(std::vector<int> vec, int start, int end)
{
    if (start < end)
    {
    int pi = pivotPartition(vec, start, end);
    quickSort(vec, start, pi - 1);
    quickSort(vec, pi + 1, end);
    }
}

int main()
{
    makeLines(Lines);
    randomizeLines(Lines);
    quickSort(Lines, 0, vecSize - 1); 
    std::cout << Lines << std::endl;
}
*/