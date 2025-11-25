import java.io.*;
import java.util.*;

public class Main {
    static int[] inorder, postorder;
    static int[] idxMap;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        inorder = new int[n];
        postorder = new int[n];
        idxMap = new int[100001];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            inorder[i] = Integer.parseInt(st.nextToken());
            idxMap[inorder[i]] = i;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            postorder[i] = Integer.parseInt(st.nextToken());
        }

        buildPreorder(0, n - 1, 0, n - 1);
        bw.flush();
    }

    static void buildPreorder(int inStart, int inEnd, int postStart, int postEnd) throws IOException {
        if (inStart > inEnd || postStart > postEnd) return;

        int root = postorder[postEnd];
        bw.write(root + " ");

        int rootIndex = idxMap[root];
        int leftSize = rootIndex - inStart;

        buildPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
        buildPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
    }
}