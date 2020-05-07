package com.khacchung;

import java.util.Scanner;

public class Main {
    /**
     * SNTHH1 - Số nguyên tố họ hàng
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
                if (isPrimeNumber(n) && isPrimeNumber(n + 4)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
            t--;
        }
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
