#include "../include/execute.h"

int tobin(int a, int b){
    int ans(0);
    while (a <= b){
        int binary = 0, remainder, product(1), answer(0), decimal(a);
        while (decimal != 0) {
            remainder = decimal % 2;
            binary = binary + (remainder * product);
            decimal = decimal / 2;
            product *= 10;
        }
        while (binary != 0){
            if (binary % 10 != 0)
                answer += 1;
            binary /= 10;
        }
        ans += answer;
        a += 1;
    }
    return ans;
}