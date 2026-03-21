package SearchSortAlgs;

public class SortAlgs {
    public void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            // Find the smallest element in the unsorted array
            int smallest = i;
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] < arr[smallest]) {
                    smallest = j;
                }
            }

            // Swap the found smallest element with the first element of the unsorted array
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }

    public void myInsertionSort(int[] arr) {
        int seperator = 1;
        for (int i = seperator; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    // Swap arr[i] and arr[j]
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            seperator++;
        }
    }
    
}
