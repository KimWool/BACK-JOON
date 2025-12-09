import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        TreeMap<String, Node> children = new TreeMap<>();
    }

    static void print(Node node, int depth) {
        for (String key : node.children.keySet()) {
            for (int i = 0; i < depth; i++) System.out.print("--");
            System.out.println(key);
            print(node.children.get(key), depth + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Node root = new Node();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            Node current = root;
            for (int j = 0; j < K; j++) {
                String str = st.nextToken();
                current.children.putIfAbsent(str, new Node());
                current = current.children.get(str);
            }
        }

        print(root, 0);
    }
}