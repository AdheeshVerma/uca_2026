class Node {
    Node next;
    int data;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListSearch {
    static Node createLinkedList(int[] arr) {
        if (arr.length == 0)
            return null;
        Node head = new Node(-1);
        Node tempHead = head;
        for (int i : arr) {
            Node node = new Node(i);
            tempHead.next = node;
            tempHead = tempHead.next;
        }
        return head.next;
    }

    static boolean searchList(Node list1, Node list2) {
        if (list1 == null && list2 == null)
            return true;
        if (list1 == null || list2 == null)
            return false;
        Node movingHead = list2;
        Node listHeadCheck = list1;
        while (movingHead != null) {
            if (movingHead.data == listHeadCheck.data) {
                while (movingHead != null && listHeadCheck != null && movingHead.data == listHeadCheck.data) {
                    System.out.println("List 1 at " + listHeadCheck.data + " List 2 at " + movingHead.data);
                    movingHead = movingHead.next;
                    listHeadCheck = listHeadCheck.next;
                }
                if (listHeadCheck == null)
                    return true;
                else if (movingHead == null)
                    return false;
                else {
                    listHeadCheck = list1;
                }
            }
            movingHead = movingHead.next;
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr1 = { 1, 2 };
        int[] arr2 = { 1, 2, 1, 2, 3, 4 };
        Node list1 = createLinkedList(arr1);
        Node list2 = createLinkedList(arr2);
        if (searchList(list1, list2))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}