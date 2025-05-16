package RecursionsTests;

public class FibonacciFinder {
    
    public static void main(String[] args) {
        int n = 100; // Example input
        int result = fibonacci(n);
        System.out.println(n + "th Fibonacci number is: " + result);
    }
    public static int fibonacci(int n) {
        if (n <= 2) {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
}
