#include <stdio.h>


int bitAnd(int x, int y) {
    int not_x_or_not_y = ~x | ~y;
    return ~not_x_or_not_y;
}


int getByte(int x, int n) {
    printf("%d %d\n" , n, n << 3);
    int y = x >> (n << 3);
    return 255 & y;
}

int logicalShift(int x, int n) {
    int is_neg = !((x >> 31) + 1) ;
    int balance = is_neg << 31;
    int mask = balance >> n << 1;
    return mask ^ (x >> n );
}

int leastBitPos(int x) {
  return (~x+1) & x;
}

int bang(int x) {
    int a = x >> 16 | x;
    int b = a >> 8 | a;
    int c = b >> 4 | b;
    int d = c >> 2 | c;
    int e = d >> 1 | d;
  return ~e & 1;
}

int isPositive(int x) {
    return (x >> 31)+ 1;
}


int divpwr2(int x, int n) {
     int minus_one = ~0;
     int non_divis = !!(~(minus_one << n) & x);
     int is_neg = !((x >> 31)+1);
     int a = is_neg & non_divis;
     printf("a : %d, non_div : %d, is_neg : %d\n", a, non_divis, is_neg);
     return (x >> n) + a;
}

int fitsBits(int x, int n) {
    int m = n + (~1 + 1); 
    int is_pos = !((x >> 31) & 1);
    int y = x + (1 << m);
    printf("m: %d, is_pos: %d, y: %d\n", m, is_pos, y);
    return !((y >> m)+ (~is_pos +1));
}

int isLessOrEqual(int x, int y) {
    int y_sign = (y >> 31) +1; // 1 == pos, 0 == neg.
    int x_sign = ~(x >> 31) +1; // 1 == neg, 0 == pos.
    int compare_sign = y_sign | x_sign; // give 1 if y_sign >= x_sign, give 0 otherwise. 
    int diff = y + (~x + 1);
    int is_diff_pos = (diff >> 31) + 1;
    printf("ys: %d, xs: %d, cs: %d, diff: %d, isdp: %d\n", y_sign,x_sign, compare_sign, diff, is_diff_pos);
    return is_diff_pos & compare_sign;
}

int isAsciiDigit(int x) {
    int offset = x + (~48 +1 );
    int diff = 9 +(~offset+1);
    int is_diff_pos = (diff >> 31) + 1;
    int is_offset_pos = (offset >> 31) + 1;
    printf("%d ,%d , %d ," ,diff , is_diff_pos, is_offset_pos);
    
  return is_diff_pos & is_offset_pos;
}
int main(){
	printf("%d\n" , isLessOrEqual(2147483647,-2147483648));

}
