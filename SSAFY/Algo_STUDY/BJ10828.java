package Algo_STUDY;

import java.util.Scanner;

public class BJ10828 {
    static Scanner sc;
    static int N;
    static int[] stack;
    static int top = -1, size = 0;
    public static void main(String args[]) {
        sc = new Scanner(System.in);

        solution();

        sc.close();
    }

    public static void solution() {
        N = sc.nextInt();
        stack = new int[N];

        String cmd;
        int num;

        for(int cnt = 0; cnt < N; cnt++) {
            cmd = sc.next();

            switch (cmd) {
            case "push":
                num = sc.nextInt();
                stack[++top] = num;
                size++;
                break;

            case "pop":
                System.out.println(stack[top--]);
                size--;
                break;

            case "size":
                System.out.println(size);
                break;

            case "empty":
                if(size > 0) {
                    System.out.println(0);
                } else {
                    System.out.println(1);
                }
                break;

            case "top":
                if(size == 0) {
                    System.out.println(-1);
                } else {
                    System.out.println(stack[top]);
                }
                break;

            default:
                break;
            }
        }

    }
}