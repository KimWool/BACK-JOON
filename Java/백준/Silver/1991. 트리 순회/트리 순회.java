import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static Map<Character, Node> tree = new HashMap<>();

    static class Node {
        char value;
        char left;
        char right;
        Node(char value, char left, char right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static StringBuilder pre = new StringBuilder();
    static StringBuilder in = new StringBuilder();
    static StringBuilder post = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char node = st.nextToken().charAt(0);
            char left = st.nextToken().charAt(0);
            char right = st.nextToken().charAt(0);
            tree.put(node, new Node(node, left, right));
        }
        preorder('A');
        inorder('A');
        postorder('A');
        System.out.println(pre.toString());
        System.out.println(in.toString());
        System.out.println(post.toString());
    }

    static void preorder(char node) {
        if (node == '.') return;
        pre.append(node);
        preorder(tree.get(node).left);
        preorder(tree.get(node).right);
    }

    static void inorder(char node) {
        if (node == '.') return;
        inorder(tree.get(node).left);
        in.append(node);
        inorder(tree.get(node).right);
    }

    static void postorder(char node) {
        if (node == '.') return;
        postorder(tree.get(node).left);
        postorder(tree.get(node).right);
        post.append(node);
    }
}