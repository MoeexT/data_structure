import java.util.Arrays;

public class QuickSort {

    private static int quickPass(int array[], int low, int high) {
        // hand-make
        int res[] = new int[high - low + 1];
        int x = array[low];
        int begin = 0, end = high - low;
        int temp = 0;

        for (int i = low + 1; i <= high; i++) {
            if (array[i] <= x)
                res[begin++] = array[i];
            else
                res[end--] = array[i];
        }
        res[begin] = x;
        for (int i = low; i <= high; i++) {
            array[i] = res[temp++];
        }
        return begin + low;
    }

    private static void quickSort(int array[], int low, int high) {
        if (low < high) {
            int pos = qKPass(array, low, high);
            qKSort(array, low, pos - 1);
            qKSort(array, pos + 1, high);
        }
    }

    private static int qKPass(int array[], int low, int high) {
        int x = array[low];

        while (low < high) {
            while (low < high && array[high] >= x)
                high--;

            if (low < high) {
                array[low] = array[high];
                low++;
            }
            while (low < high && array[low] < x)
                low++;

            if (low < high) {
                array[high] = array[low];
                high--;
            }
        }
        array[low] = x;
        return low;
    }

    private static void qKSort(int array[], int low, int high) {
        if (low < high) {
            int pos = quickPass(array, low, high);
            quickSort(array, low, pos - 1);
            quickSort(array, pos + 1, high);
        }
    }

    public static void main(String[] args) {
        long time1 = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            int array[] = {47, 45, 72, 27, 74, 56, 82, 43, 53, 23, 64, 24, 52,12,54,84,6354,135,546,44,181,661,848,351,315,1148,13184,11,844,44,24,15,12,15,21,5,115,151,152,12,35,84,841,9,15,13,15,165,651,155};
            qKSort(array, 0, array.length - 1);
        }

        long time2 = System.currentTimeMillis();

        for (int i = 0; i < 100000; i++) {
            int array2[] = {47, 45, 72, 27, 74, 56, 82, 43, 53, 23, 64, 24, 52,12,54,84,6354,135,546,44,181,661,848,351,315,1148,13184,11,844,44,24,15,12,15,21,5,115,151,152,12,35,84,841,9,15,13,15,165,651,155};
            quickSort(array2, 0, array2.length - 1);
        }
        long time3 = System.currentTimeMillis();

        System.out.println("quick-sort: " + (time3 - time2) + "ms, QKSort: " + (time2 - time1) + "ms");
    }
}
