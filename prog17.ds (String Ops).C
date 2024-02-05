#include <stdio.h>
#include <stdlib.h>

int LENGTH(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void CONCAT(char *str1, char *str2) {
    int i = 0, j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

void SUBSTR(char str[], int pos, int len) {
    char sub[50];
    int slen = LENGTH(str);
    int p, j, max_ext;
    if (pos > slen) {
        printf("\n Invalid Position ");
        return;
    }
    max_ext = slen - pos + 1;
    if (len > max_ext) {
        printf("\n Invalid Substring Length");
        return;
    }
    p = pos - 1;
    for (j = 0; j < len; j++) {
        sub[j] = str[p];
        p++;
    }
    sub[j] = '\0';
    printf("\n Substring = %s", sub);
}

void REPLACE(char str[], char substr[], char replacestr[]) {
    char output[50];
    int i = 0, flag = 0, start = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == substr[j]) {
            if (flag)
                start = i;
            j++;
            if (substr[j] == '\0')
                break;
            flag = 1;
        } else {
            flag = start = j = 0;
        }
        i++;
    }
    if (substr[j] == '\0' && flag) {
        for (i = 0; i < start; i++)
            output[i] = str[i];
        for (j = 0; j < LENGTH(replacestr); j++) {
            output[i] = replacestr[j];
            i++;
        }
        for (j = start + LENGTH(substr); str[j] != '\0'; j++) {
            output[i] = str[j];
            i++;
        }
        output[i] = '\0';
        printf("Output : %s\n", output);
    } else {
        printf("%s is not a substring of %s\n", substr, str);
    }
}

int main() {
    char str1[50], str2[50], substr[50], repstr[50];
    int len, pos, ch;
    while (1) {
        printf("\n String Operations ");
        printf("\n 1.String Length");
        printf("\n 2.String Concatenation");
        printf("\n 3.Extracting Substring");
        printf("\n 4.Replace a String");
        printf("\n 5.Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        fflush(stdin); // Clear the input buffer
        switch (ch) {
        case 1:
            printf("\n Enter the String : ");
            gets(str1);
            printf("\n The Length of a String : %d", LENGTH(str1));
            break;
        case 2:
            printf("\n Enter the First String : ");
            gets(str1);
            printf("\n Enter the Second String : ");
            gets(str2);
            CONCAT(str1, str2);
            printf("\n Concatenated String : %s", str1);
            break;
        case 3:
            printf("\n Enter the string : ");
            gets(str1);
            printf("\n Enter the position of a Substring : ");
            scanf("%d", &pos);
            printf("\n Enter the Length of a Substring : ");
            scanf("%d", &len);
            SUBSTR(str1, pos, len);
            break;
        case 4:
            printf("Enter the String : ");
            gets(str1);
            printf("\n Enter the string to be removed : ");
            gets(substr);
            printf("\n Enter the string to be replaced : ");
            gets(repstr);
            REPLACE(str1, substr, repstr);
            break;
        case 5:
            exit(0);
        default:
            printf("\n Invalid Option ");
            break;
        }
    }
    return 0;
}

