#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Candidate
{
    char name[20];
    int cnt;
}Candidate;

int main()
{
    int candidates_num = 0, vate_num = 0;
    while (~scanf("%d", &candidates_num))
    {
        Candidate *can = (Candidate *)malloc(sizeof(Candidate) * candidates_num);
        for (int i = 0; i < candidates_num; i++)
        {
            scanf("%s", can[i].name);
            can[i].cnt = 0;
        }
        scanf("%d", &vate_num);
        char temp[20] = {'\0'};
        int invalid = 0;
        for (int i = 0; i < vate_num; i++)
        {
            scanf("%s", temp);
            int flag = 0;
            for (int j=0; j<candidates_num;j++){
                if (strcmp(temp,can[j].name) == 0)
                {
                    can[j].cnt++;
                    flag = 1;
                }
            }
            if (!flag) invalid++;
        }
        for (int i=0; i<candidates_num; i++)
        {
            printf("%s : %d\n",can[i].name, can[i].cnt);
        }
        printf("Invalid : %d\n",invalid);
        free(can);
    }
    return 0;
}
