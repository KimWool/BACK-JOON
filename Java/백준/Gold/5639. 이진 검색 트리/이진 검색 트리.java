import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left, right;
        Node(int value) {
            this.value = value;
        }
    }

    static void insert(Node root, int value) {
        if (value < root.value) {
            if (root.left == null) {
                root.left = new Node(value);
            } else {
                insert(root.left, value);
            }
        } else {
            if (root.right == null) {
                root.right = new Node(value);
            } else {
                insert(root.right, value);
            }
        }
    }

    static void postorder(Node root, StringBuilder sb) {
        if (root == null) return;
        postorder(root.left, sb);
        postorder(root.right, sb);
        sb.append(root.value).append("\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        Node root = null;
        while ((input = br.readLine()) != null && !input.isEmpty()) {
            int value = Integer.parseInt(input);
            if (root == null) {
                root = new Node(value);
            } else {
                insert(root, value);
            }
        }
        StringBuilder sb = new StringBuilder();
        postorder(root, sb);
        System.out.print(sb);
    }
}