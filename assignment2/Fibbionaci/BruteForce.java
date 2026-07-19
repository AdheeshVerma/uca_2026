import java.util.*;

public class BruteForce {

    public static int nthFibio(int n) {
        if (n <= 2)
            return 1;
        return nthFibio(n - 1) + nthFibio(n - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        int value = 0;
        int n = sc.nextInt();
        for (int i = 1; i < n; i++) {
            value = nthFibio(i);
            if (value > n)
                break;
            if (value % 2 == 0)
                sum += value;
        }
        System.out.println(sum);
    }
}