import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Member {
    int age;
    String name;

    public Member(int age, String name) {
        this.age = age;
        this.name = name;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        List<Member> members = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int age = scanner.nextInt();
            String name = scanner.next();
            members.add(new Member(age, name));
        }

        members.sort(Comparator.comparingInt((Member member) -> member.age));

        for (Member member : members) {
            System.out.println(member.age + " " + member.name);
        }
    }
}
