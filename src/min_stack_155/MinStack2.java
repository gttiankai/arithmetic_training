package min_stack_155;


import java.util.Stack;

/**
 * 学了一种非常好的奇技淫巧
 * <p>
 * 使用差值的方式
 *
 * 这种方式有一个不好的地方,就是 long类型的设定,因为涉及到加减法操作,所以如果是在int值的最大值的时候,就会出现问题
 */
public class MinStack2 {
    private Stack<Long> stack;
    private long min;

    public MinStack2() {
        stack = new Stack<Long>();
    }

    public void push(int x) {
        if (stack.empty()) {
            stack.push(0L);
            min = x;
        } else {
            stack.push(x - min);
            if (x < min) {
                min = x;
            }
        }
    }

    public void pop() {
        if (stack.empty()) {
            return;
        }
        long value = stack.pop();
        if (value < 0) {
            min = min - value;
        }
    }

    public int top() {
        long value = stack.peek();
        if (value < 0) {
            return (int) min;
        } else {
            return (int) (min + value);
        }
    }

    public int getMin() {
        return (int) min;
    }
}
