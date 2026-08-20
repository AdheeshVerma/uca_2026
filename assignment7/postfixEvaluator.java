import java.util.*;

public class postfixEvaluator {

    public static int evaluator(String expression) {
        String[] tokens = expression.split(" ");
        Stack<Integer> stk = new Stack<>();
        for (String c : tokens) {
            if (c.equals("+")) {
                int r1 = stk.pop();
                int r2 = stk.pop();
                stk.push(r1 + r2);
            } else if (c.equals("-")) {
                int r1 = stk.pop();
                int r2 = stk.pop();
                stk.push(r2 - r1);
            } else if (c.equals("*")) {
                int r1 = stk.pop();
                int r2 = stk.pop();
                stk.push(r1 * r2);
            } else if (c.equals("/")) {
                int r1 = stk.pop();
                int r2 = stk.pop();
                stk.push(r2 / r1);
            } else {
                stk.push(Integer.parseInt(c));
            }
        }
        return stk.pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expression = sc.nextLine();
        System.out.println(evaluator(expression));
    }
}