import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static class User{
        int age;
        String name;

        User(int age, String name){
            this.age = age;
            this.name = name;
        }
    }

    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N;
        try {
            N = Integer.parseInt(br.readLine()); //전체 사람의 수
            User[] users = new User[N];
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int age = Integer.parseInt(input[0]);
                String name = input[1];
                users[i] = new User(age, name);
            }

            Arrays.sort(users, Comparator.comparingInt(u -> u.age));

            for (User u : users) {
                System.out.println(u.age + " " + u.name);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}