import java.util.*;

public class Optimized {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int sum = 0;

        int a = 2;
        int b = 8;

        while (a <= n) {
            sum += a;

            int c = 4 * b + a;

            a = b;
            b = c;
        }

        System.out.println(sum);
    }
}