import java.util.*;
import java.io.*;

public class Main {
    static int numOfProblems, numOfRelations;
    static ArrayList<ArrayList<Integer>> adjacencyList;
    static int[] inDegreeCount;
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        numOfProblems = Integer.parseInt(tokenizer.nextToken());
        numOfRelations = Integer.parseInt(tokenizer.nextToken());
        adjacencyList = new ArrayList<>();
        for (int i = 0; i <= numOfProblems; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        inDegreeCount = new int[numOfProblems+1];
        for (int i = 0; i < numOfRelations; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int a = Integer.parseInt(tokenizer.nextToken());
            int b = Integer.parseInt(tokenizer.nextToken());
            adjacencyList.get(a).add(b);
            inDegreeCount[b]++;
        }
        solveUsingTopologicalSort();
    }
    static void solveUsingTopologicalSort() {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        for (int i = 1; i <= numOfProblems; i++) {
            if (inDegreeCount[i] == 0) {
                priorityQueue.offer(i);
            }
        }
        while (!priorityQueue.isEmpty()) {
            int currProblem = priorityQueue.poll();
            System.out.print(currProblem + " ");
            for (int i = 0; i < adjacencyList.get(currProblem).size(); i++) {
                int nextProblem = adjacencyList.get(currProblem).get(i);
                inDegreeCount[nextProblem]--;
                if (inDegreeCount[nextProblem] == 0) {
                    priorityQueue.offer(nextProblem);
                }
            }
        }
    }
}
