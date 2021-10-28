#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define n   10
#define bool   short
#define true   1
#define false  0

int array[n];
int i;
int j;

void swap(int i, int j) {
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
}

// Sorting Algorithm SelectionSort
void selectionSort() {
   for (i = 0; i < (n - 1); i++) {
      int indice = i;
      for (j = (i + 1); j < n; j++){
         if (array[indice] > array[j]){
            indice = j;
         }
      }
      swap(indice, i);
   }
}

//Produces an array of random numbers.
void random_numbers() {
   for (i = 0; i < n; i++) {
      array[i] = rand() % 10;
   }
}

//Show elements of an array
void show_array() {
   printf("[ ");

   for (i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }

   printf("] \n");
}

int main() {
   
   random_numbers();

   //Show array elements before sorting
   show_array();

   selectionSort();

   //Show array elements after sorting
   show_array();
}
