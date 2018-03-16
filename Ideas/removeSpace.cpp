#include <cstdio>
#include <cstring>

char sqence[100005];
int main() {
    while (1) {
        scanf("%s", sqence);
        FILE* filehead = fopen("/Users/basasuya/ACM/Ideas/removeSpaceText.txt", "r+");
        fseek(filehead, 0, SEEK_END);
        int len = std::strlen(sqence);
        for (int i = 0; i < len; ++i) {
            if (sqence[i] != ' ')
                fprintf(filehead, "%c", sqence[i]);
        }
        //    fprintf(filehead, "\n");
        fclose(filehead);
    }
}