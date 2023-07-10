import java.util.*;

public class Main {
    static class MyStack {
        private ArrayList<Integer> stack;

        public MyStack() {
            this.stack = new ArrayList<>();
        }

        public void push(int item) {
            this.stack.add(item);
        }

        public int pop() {
            if (this.stack.size() == 0) {
                throw new NoSuchElementException();
            }
            return this.stack.remove(this.stack.size() - 1);
        }

        public int peek() {
            if (this.stack.size() == 0) {
                throw new NoSuchElementException();
            }
            return this.stack.get(this.stack.size() - 1);
        }

        public boolean isEmpty() {
            return this.stack.size() == 0;
        }
    }

    static String compressedStr;
    static int[] matchingClosingParenthesisIndex;

    static int uncompress(int startIndex, int endIndex) {
        int uncompressedLength = 0;

        for (int i = startIndex; i < endIndex; i++) {
            if (compressedStr.charAt(i) == '(') {
                int repeatNum = compressedStr.charAt(i - 1) - '0';
                uncompressedLength += repeatNum * uncompress(i + 1, matchingClosingParenthesisIndex[i]) - 1;
                i = matchingClosingParenthesisIndex[i];
                continue;
            }
            uncompressedLength++;
        }

        return uncompressedLength;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        compressedStr = sc.next();
        matchingClosingParenthesisIndex = new int[compressedStr.length()];

        MyStack stack = new MyStack();

        for (int i = 0; i < compressedStr.length(); i++) {
            if (compressedStr.charAt(i) == '(') {
                stack.push(i);
            } else if (compressedStr.charAt(i) == ')') {
                matchingClosingParenthesisIndex[stack.peek()] = i;
                stack.pop();
            }
        }

        System.out.println(uncompress(0, compressedStr.length()));
    }
}
