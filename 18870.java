import java.util.*;

class Main {
    public static int getDistance(String a, String b, String c) {
        int distance = 0;
        for (int i = 0; i < 4; i++) {
            if (a.charAt(i) != b.charAt(i))
                distance++;
            if (b.charAt(i) != c.charAt(i))
                distance++;
            if (c.charAt(i) != a.charAt(i))
                distance++;
        }
        return distance;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        for (int t = 0; t < testCases; t++) {
            int numStudents = scanner.nextInt();
            HashMap<String, Integer> mbtiMap = new HashMap<>();
            for (int i = 0; i < numStudents; i++) {
                String mbtiType = scanner.next();
                mbtiMap.put(mbtiType, mbtiMap.getOrDefault(mbtiType, 0) + 1);
            }
            int answer = -1;
            List<String>[] mbtiSets = new ArrayList[2];
            mbtiSets[0] = new ArrayList<>();
            mbtiSets[1] = new ArrayList<>();
            for (Map.Entry<String, Integer> entry : mbtiMap.entrySet()) {
                String mbtiKey = entry.getKey();
                int mbtiValue = entry.getValue();
                if (mbtiValue >= 3) {
                    answer = 0;
                } else {
                    mbtiSets[mbtiValue - 1].add(mbtiKey);
                    if (mbtiValue == 2)
                        mbtiSets[0].add(mbtiKey);
                }
            }
            if (answer == 0) {
                System.out.println(answer);
            } else {
                List<Integer> distances = new ArrayList<>();
                for (int a = 0; a < mbtiSets[0].size() - 2; a++) {
                    for (int b = a + 1; b < mbtiSets[0].size() - 1; b++) {
                        for (int c = b + 1; c < mbtiSets[0].size(); c++) {
                            distances.add(getDistance(mbtiSets[0].get(a), mbtiSets[0].get(b), mbtiSets[0].get(c)));
                        }
                    }
                }
                if (mbtiSets[1].size() == 0) {
                    int minDistance = Collections.min(distances);
                    System.out.println(minDistance);
                } else {
                    for (String a : mbtiSets[1]) {
                        for (String c : mbtiSets[0]) {
                            if (!a.equals(c))
                                distances.add(getDistance(a, a, c));
                        }
                    }
                    int minDistance = Collections.min(distances);
                    System.out.println(minDistance);
                }
            }
        }
    }
}
