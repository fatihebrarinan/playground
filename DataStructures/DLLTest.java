package DataStructures;

public class DLLTest {
    public static void main(String[] args) {
        DLL dll = new DLL();
        dll.addToFirst(1);
        dll.addToLast(2);
        dll.addToLast(3);
        dll.addToIndex(1, 4);
        
        // Print the list
        dll.printList();
        // Expected output: 1 4 2 3

        dll.removeFromFirst();
        dll.removeFromLast();
        dll.removeFromIndex(1);
        // Print the list
        dll.printList();
        // Expected output: 4
    }
}
