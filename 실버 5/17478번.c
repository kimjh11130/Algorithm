#include <stdio.h>

void under(int n, char arr[]) {
    for (int i = 0; i < n * 4; i++) printf("_");
    printf("%s\n", arr);
}

int jagui(int n, int i) {
    under(i, "\"재귀함수가 뭔가요?\"");
    if (i == n) under(i, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
    else {
        under(i, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        under(i, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        under(i, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        jagui(n, i + 1);
    }
    under(i, "라고 답변하였지.");
}

int main() {
    int n;
    scanf("%d", &n);
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    jagui(n, 0);
}