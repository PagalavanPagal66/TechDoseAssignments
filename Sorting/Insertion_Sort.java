// Insertion sort in Java

import java.util.Arrays;

class Main {

  public static void main(String args[]) {
    int[] data = { 9, 5, 1, 4, 3 ,7};
     int size = array.length;
    for (int i = 1; i < size; i++) {
      int key = array[step];
      int j = i - 1;
      while (j >= 0 && key < array[j]) {
        array[j + 1] = array[j];
        --j;
      }
      array[j + 1] = key;
    }
    System.out.println("Sorted Array in Ascending Order: ");
    System.out.println(Arrays.toString(data));
  }
}