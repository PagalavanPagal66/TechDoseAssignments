
import java.util.Arrays;
  public static void main(String args[]) {
    int[] data = {6,234,2,4,6 };
     int size = array.length;

    for (int step = 0; step < size - 1; step++) {
      int min_idx = step;

      for (int i = step + 1; i < size; i++) {
        if (array[i] < array[min_idx]) {
          min_idx = i;
        }
      }
      int temp = array[step];
      array[step] = array[min_idx];
      array[min_idx] = temp;
    }
    System.out.println("Sorted Array in Ascending Order: ");
    System.out.println(Arrays.toString(data));
  }
}