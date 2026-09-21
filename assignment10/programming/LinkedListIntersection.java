class Node {
    Node next;
    int data;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListIntersection {

    static Node getIntersectionNode(Node headA, Node headB) {
        Node tempA = headA;
        Node tempB = headB;
        while (tempA != tempB) {
            tempA = tempA == null ? headB : tempA.next;
            tempB = tempB == null ? headA : tempB.next;

        }
        return tempA;
    }

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + "->");
            head = head.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node list1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        Node list2 = new Node(5);
        Node node21 = new Node(6);
        Node node22 = new Node(7);
        list1.next = node2;
        node2.next = node3;
        node3.next = node4;
        list2.next = node21;
        node21.next = node22;
        node22.next = node2;
        System.out.println("Nodes intersect at");
        Node intersection = getIntersectionNode(list1, list2);
        printList(intersection);
    }

}
