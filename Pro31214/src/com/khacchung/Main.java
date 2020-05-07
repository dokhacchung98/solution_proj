package com.khacchung;

import java.util.Scanner;

/**
 * SNT11 - Số nguyên tố max
 */
public class Main {

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
                int result = getPrimeNumber(n);
                System.out.println(result);
            }
            t--;
        }
    }

    private static int getPrimeNumber(int n) {
        for (int i = n; i >= 2; i--) {
            if (isPrimeNumber(i)) {
                return i;
            }
        }
        return 0;
    }

    private static boolean isPrimeNumber(int k) {
        if (k == 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(k); i++) {
            if (k % i == 0) {
                return false;
            }
        }
        return true;
    }
}
