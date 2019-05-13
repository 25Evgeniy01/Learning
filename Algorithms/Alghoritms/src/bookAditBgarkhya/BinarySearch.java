package bookAditBgarkhya;

public class BinarySearch {

	public static void main(String[] args) {
		int[] array = {1, 3, 5, 7, 9};
		System.out.print(binaryS(array, 1));
	}
	
	public static int binaryS(int[] array, int item) {
		int low = 0;
		int high = array.length - 1;
		int mid, guess;
		
		while (low <= high) {
			mid = (low + high) / 2;
			guess = array[mid];
			if (guess == item) return mid;
			if (guess > item) high = mid - 1; 
			else low = mid + 1;
		}
		return -1;
	}

}
