/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * <p>
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */

package min_stack_155;

import java.util.Arrays;

public class MinStack {
    // 使用数组的形式,实现了一个很粗糙的min stack
    // 感觉使用数组的形式, 虽然速度快一点,但是实现起来很粗糙.
    int min;
    int size = 1;
    boolean isFirst = true;
    int top;
    int[] stack;
    int MAX = 1024;
    int[] minStack;
    int minTop;
    int minSize = 1;
    int minMAX = 512;


    public MinStack() {
        top = -1;
        stack = new int[MAX];
        minTop = -1;
        minStack = new int[MAX / 2];
    }

    public void push(int x) {
        // 动态扩展数组
        if (top == MAX - 1) {
            size++;
            int[] tmp = new int[MAX * size];
            Arrays.copyOf(tmp, MAX);
            MAX = MAX * size;
            stack = tmp;
        }
        top++;
        stack[top] = x;
        // 动态拓展数组
        if (minTop == minMAX - 1) {
            minSize++;
            int[] tmp = new int[minMAX * minSize];
            Arrays.copyOf(tmp, minMAX * minSize);
            minMAX = minMAX * size;
            minStack = tmp;
        }

        if (isFirst) {
            minTop++;
            minStack[minTop] = x;
            isFirst = false;
        } else {
            if (minStack[minTop] > x) {
                minTop++;
                minStack[minTop] = x;
            }
        }

    }

    public void pop() {
        if (stack[top] == minStack[minTop]) {
            top--;
            minTop--;
        } else {
            top--;
        }
    }

    public int top() {
        if (top == -1) {
            return 0;
        }
        return stack[top];
    }

    public int getMin() {
        if (minTop == -1) {
            new Exception("the min is no exist!");
            return 0;
        }
        return minStack[minTop];
    }
}
