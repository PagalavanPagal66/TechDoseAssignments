// Bubble sort in Java

import java.util.Arrays;

class Main {
  public static void main(String args[]) {
      
    int[] data = { 50,7,20,1,45,47,27 };
      int size = array.length;
    for (int i = 0; i < size - 1; i++)
      for (int j = 0; j < size - i - 1; j++)
        if (array[j] > array[j + 1]) {
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
    
    System.out.println("Sorted Array:");
    System.out.println(Arrays.toString(data));
  }
}