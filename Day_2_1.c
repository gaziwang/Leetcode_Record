#include <stdbool.h>
int x  = 123;

/*第一种方法*/
// bool isPalindrome(int x) {
//     if (x<0) return false;
//     int original = x;
//     int reversed = 0;
//     while (x >0){
//         reversed = reversed*10 + x%10;
//         x = x/10;
//     }
//     if(reversed == original ){
//         return true;    
//     }else{  
//         return false;
//     }
// }
/*第二种方法*/
bool isPalindrome2(int x) {
    if (x < 0) return false;
    
    char str[20];
    sprintf(str, "%d", x);
    
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    
    return true;
}
// 方法3：半数反转法（最优解）
bool isPalindrome3(int x) {
    // 负数和以0结尾的正数（除了0本身）不是回文数
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // x == reversed 处理偶数位情况
    // x == reversed / 10 处理奇数位情况
    return x == reversed || x == reversed / 10;
}

// 方法4：递归法
int getReverseHelper(int x, int reversed) {
    if (x == 0) return reversed;
    return getReverseHelper(x / 10, reversed * 10 + x % 10);
}

bool isPalindrome4(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    
    int reversed = getReverseHelper(x, 0);
    return x == reversed;
}

// 方法5：数组存储法
bool isPalindrome5(int x) {
    if (x < 0) return false;
    
    int digits[10];  // 假设最多10位数
    int count = 0;
    
    // 特殊处理0
    if (x == 0) return true;
    
    // 提取每一位数字
    while (x > 0) {
        digits[count++] = x % 10;
        x /= 10;
    }
    
    // 检查是否回文
    for (int i = 0; i < count / 2; i++) {
        if (digits[i] != digits[count - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

// 方法6：数学计算法（获取位数后比较）
int getDigitCount(int x) {
    int count = 0;
    while (x > 0) {
        count++;
        x /= 10;
    }
    return count;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isPalindrome6(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    
    int digitCount = getDigitCount(x);
    
    for (int i = 0; i < digitCount / 2; i++) {
        int leftDigit = (x / power(10, digitCount - 1 - i)) % 10;
        int rightDigit = (x / power(10, i)) % 10;
        
        if (leftDigit != rightDigit) {
            return false;
        }
    }
    
    return true;
}

