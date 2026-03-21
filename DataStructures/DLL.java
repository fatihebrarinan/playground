package DataStructures;

public class DLL {
    DLLNode first;
    DLLNode last;
    int size;

    public DLL() {
        first = null;
        last = null;
        size = 0;
    }
    
    public void addToFirst(Object data) {
        DLLNode newNode = new DLLNode();
        newNode.data = data;
        newNode.next = first;
        newNode.prev = null;
        if (first != null) {
            first.prev = newNode;
        }
        first = newNode;
        if (last == null) {
            last = newNode;
        }
        size++;
    }

    public void addToLast(Object data) {
        DLLNode newNode = new DLLNode();
        newNode.data = data;
        newNode.prev = last;
        newNode.next = null;
        if (last != null) {
            last.next = newNode;
        }
        last = newNode;
        if (first == null) {
            first = newNode;
        }
        size++;
    }
    
    public void addToIndex(int index, Object data) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        if (index == 0) {
            addToFirst(data);
        } else if (index == size) {
            addToLast(data);
        } else {
            DLLNode newNode = new DLLNode();
            newNode.data = data;
            DLLNode current = first;
            for (int i = 0; i < index - 1; i++) {
                current = current.next;
            }
            newNode.next = current.next;
            newNode.prev = current;
            current.next.prev = newNode;
            current.next = newNode;
            size++;
        }
    }

    public Object removeFromFirst() {
        if (first == null) {
            throw new NullPointerException("List is empty");
        }
        Object data = first.data;
        first = first.next;
        if (first != null) {
            first.prev = null;
        } else {
            last = null;
        }
        size--;
        return data;
    }

    public Object removeFromLast() {
        if (last == null) {
            throw new NullPointerException("List is empty");
        }
        Object data = last.data;
        last = last.prev;
        if (last != null) {
            last.next = null;
        } else {
            first = null;
        }
        size--;
        return data;
    }

    public Object removeFromIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        if (index == 0) {
            return removeFromFirst();
        } else if (index == size - 1) {
            return removeFromLast();
        } else {
            DLLNode current = first;
            for (int i = 0; i < index; i++) {
                current = current.next;
            }
            Object data = current.data;
            current.prev.next = current.next;
            current.next.prev = current.prev;
            size--;
            return data;
        }
    }

    public Object getFromIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        DLLNode current = first;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.data;
    }

    public void printList() {
        DLLNode current = first;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public void printListReverse() {
        DLLNode current = last;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.prev;
        }
        System.out.println();
    }

    public int getSize() {
        return size;
    }

    public class DLLNode {
        DLLNode next;
        DLLNode prev;
        Object data;
    }    

}
