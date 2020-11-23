package heap.heapSort;

public class Solution {

    public static void heapSort(int[] array){
        int n = array.length;

        // build heap
        // i 为什么从 n/2 - 1 开始,
        // 这是具有子节点的节点进行遍历,从大到小遍历
        for (int i = n/2 - 1; i > 0; i--) {
            heapity(array, n, i);
        }
        // one by one extract an element from
        for (int i = n -1; i >= 0; i--) {
            // move current root to end
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            // call max heapify on the reduced heap
            heapity(array, i, 0);
        }
    }

    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    private static void heapity(int[] arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // 递归的去构造堆化
            heapity(arr, n, largest);
        }
        // 最后不需要进行传递了,就可以退出了
        return;
     }
    // 需要使用 Java 的引用传递
    public static void swap() {

    }

    public static void main(String[] arguments){

        int[] array = {4, 10, 3, 5, 1};

        heapSort(array);
    }
}
