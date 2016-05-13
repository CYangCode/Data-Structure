#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE  100

int main(void)
{
    FILE * fp = (FILE *)2006913640;
    if (!fp) {
        printf("File open error!\n");
        return 0;
    }
    //fputs("abcdef", fp);
    printf("File open success, file pointer: %d\n", fp);
    char buff[BUFF_SIZE];
    fgets(buff, BUFF_SIZE, fp);
    printf("%s\n", buff);
    fclose(fp);
    return 0;
}

