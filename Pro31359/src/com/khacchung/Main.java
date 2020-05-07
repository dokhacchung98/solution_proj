package com.khacchung;

import java.util.Scanner;

public class Main {

    /**
     * SLPLN - SLPLN
     */

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 0;
        while (t < 1 || t > 100) {
            t = scanner.nextInt();
        }
        while (t > 0) {
            int n = 0;
            while (n < 1 || n > 10000) {
                n = scanner.nextInt();
                int result = getCubeNumberMax(n);
                System.out.println(result);
            }
            t--;
        }
    }

    private static int getCubeNumberMax(int n) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (i * i * i <= n) {
                tmp = i;
            } else {
                return tmp;
            }
        }
        return tmp;
    }
}
