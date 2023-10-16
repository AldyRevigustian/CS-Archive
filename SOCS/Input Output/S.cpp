#include <stdio.h>
#include <string.h>

int main() {
    char a[101];

    scanf("%[^\n]", a);

    size_t len = strlen(a);
    if(len > 0 && a[len-1] == '\n') {
        a[len-1] = '\0';
    }

    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\",\"%s\");\n", a);
    printf("    return 0;\n");
    printf("}\n");

    return 0;
}