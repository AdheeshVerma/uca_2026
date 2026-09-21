public class ReverseLL {
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

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + "->");
            head = head.next;
        }
        System.out.println("null");
    }

    static Node reverse(Node head) {
        if (head == null || head.next == null)
            return head;
        Node last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }

    public static void main(String[] args) {
        int[] list = { 1, 2, 3, 4, 5 };
        Node head = createLinkedList(list);
        Node reverseHead = reverse(head);
        printList(reverseHead);
    }
}
