import java.util.*;

public class balancedParenthesis {
    public static boolean balancedParenthesis(String expression) {
        Stack<Character> stk = new Stack<>();
        for (char c : expression.toCharArray()) {
            if (c == '[' || c == '(' || c == '{')
                stk.push(c);
            else if (!stk.isEmpty() && ((c == ']' && stk.peek() == '[') || (c == ')' && stk.peek() == '(')
                    || (c == '}' && stk.peek() == '{'))) {
                stk.pop();
            } else
                stk.push(c);
        }
        return stk.isEmpty();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expression = sc.nextLine();
        System.out.println(balancedParenthesis(expression));
    }
}
