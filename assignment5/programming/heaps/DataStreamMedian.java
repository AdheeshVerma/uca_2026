import java.util.PriorityQueue;

class MedianFinder {
    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;

    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>((a, b) -> b - a);
    }

    public void balance(PriorityQueue<Integer> minHeap, PriorityQueue<Integer> maxHeap) {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.offer(minHeap.poll());
        }
    }

    public void addNum(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek())
            maxHeap.offer(num);
        else
            minHeap.offer(num);

        balance(minHeap, maxHeap);
    }

    public double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (minHeap.peek() + maxHeap.peek()) / 2.0;
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.peek();
        } else {
            return maxHeap.peek();
        }
    }
}

public class DataStreamMedian {
    public static void main(String[] args) {

        MedianFinder obj = new MedianFinder();

        obj.addNum(5);
        System.out.println("Median: " + obj.findMedian());

        obj.addNum(10);
        System.out.println("Median: " + obj.findMedian());

        obj.addNum(15);
        System.out.println("Median: " + obj.findMedian());

        obj.addNum(20);
        System.out.println("Median: " + obj.findMedian());

        obj.addNum(3);
        System.out.println("Median: " + obj.findMedian());
    }
}