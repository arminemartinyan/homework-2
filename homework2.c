// // ex 3-3

// #include <stdio.h>
// #include <ctype.h>

// void expand(const char s1[], char s2[]) {
//     int i = 0, j = 0;
//     char start, end;

//     while (s1[i] != '\0') {
//         if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
//             start = s1[i-1];
//             end = s1[i+1];
//             if (isalnum(start) && isalnum(end) && start < end) {
//                 i++;
//                 while (start < end) {
//                     s2[j++] = ++start; 
//                 }
//             } else {
//                 s2[j++] = s1[i++]; 
//             }
//         } else {
//             s2[j++] = s1[i++];
//         }
//     }
//     s2[j] = '\0'; 
// }

// int main() {
//     char s1[] = "a-z0-9-";
//     char s2[100];

//     expand(s1, s2);
//     printf("Expanded string: %s\n", s2);

//     return 0;
// }

// // ex 3-2
// #include <stdio.h>

// void escape(char s[], const char t[]) {
//     int i, j = 0;

//     for (i = 0; t[i] != '\0'; i++) {
//         switch (t[i]) {
//             case '\n':
//                 s[j++] = '\\';
//                 s[j++] = 'n';
//                 break;
//             case '\t':
//                 s[j++] = '\\';
//                 s[j++] = 't';
//                 break;
//             case '\\':
//                 s[j++] = '\\';
//                 s[j++] = '\\';
//                 break;
//             default:
//                 s[j++] = t[i];
//                 break;
//         }
//     }
//     s[j] = '\0';
// }

// void unescape(char s[], const char t[]) {
//     int i, j = 0;

//     for (i = 0; t[i] != '\0'; i++) {
//         if (t[i] == '\\' && t[i+1] != '\0') { 
//             switch (t[i+1]) {
//                 case 'n':
//                     s[j++] = '\n';
//                     i++; 
//                     break;
//                 case 't':
//                     s[j++] = '\t';
//                     i++; 
//                     break;
//                 case '\\':
//                     s[j++] = '\\';
//                     i++; 
//                     break;
//                 default:
//                     s[j++] = t[i];
//                     break;
//             }
//         } else {
//             s[j++] = t[i];
//         }
//     }
//     s[j] = '\0';
// }

// int main() {
//     char t[] = "Hello\tWorld\nThis is a test\\escape.";
//     char s[100], u[100];

//     escape(s, t);
//     printf("Escaped string: %s\n", s);

//     unescape(u, s);
//     printf("Unescaped string: %s\n", u);

//     return 0;
// }

// // ex 3-5
// #include <stdio.h>
// #include <string.h>

// void reverse(char s[]) {
//     int i, j;
//     char temp;
    
//     for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
//         temp = s[i];
//         s[i] = s[j];
//         s[j] = temp;
//     }
// }

// void itob(int n, char s[], int b) {
//     int i = 0, sign;
//     unsigned int num;
    
//     if (b < 2 || b > 36) { 
//         s[i++] = '?'; 
//         s[i] = '\0';
//         return;
//     }

//     sign = n;
//     num = (n < 0) ? -n : n;
 
//     do {
//         int remainder = num % b;
//         s[i++] = (remainder > 9) ? (remainder - 10) + 'A' : remainder + '0';
//         num /= b;
//     } while (num > 0);
    
  
//     if (sign < 0 && b == 10) {
//         s[i++] = '-';
//     }
    
//     s[i] = '\0'; 
//     reverse(s);  
// }

// int main() {
//     char buffer[100];

//     itob(255, buffer, 16);  
//     printf("255 in hexadecimal: %s\n", buffer);

//     itob(-255, buffer, 10); 
//     printf("-255 in base 10: %s\n", buffer);

//     itob(255, buffer, 2); 
//     printf("255 in binary: %s\n", buffer);

//     return 0;
// }
