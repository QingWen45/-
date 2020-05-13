#include <stdio.h>
#include <stdlib.h>

int is_negative = 0;

//��ȡ�������������������ȼ�1
char* get_num(char *str, int *n, int strlen)
{
    int count = 0,i;
    char cha;
    do
    {
        cha = getchar();
        if(count >= strlen)
        {
            str = (char*)realloc(str, sizeof(char*) * (++strlen));
        }
        count ++;
        str[count - 1] = cha;
    }
    while (cha != '\n'); //����س�ʱ��ֹ����
    if (str[0]=='-') //����Ϊ����ʱ�Ĵ���
    {
        if(is_negative == 0)
            is_negative = 1;
        else
            is_negative = 0;

        for(i=0;i<count;i++)
        {
            str[i]=str[i+1];
        }
        count--;
    }
    *n = count;
    return str;
}

//���ַ���ת��Ϊ��������
void str_to_arr(char *s, int *a, int n)
{
    int i,j;
    a[0] = n -1 ;
    for(i=1, j=n-1; i<n;i++,j--)-1
    {
        a[j] = s[i-1] - 48; //48Ϊ0��ASCII����
    }
}

//���������
void print_int(int *a, int n)
{
    int i=n-1;
    while (a[i] == 0) i--; //ȥ������ǰ�����0
    for(;i>0;i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

//�˷�����
void multiply_arr(int *a, int *b, int *c, int n1, int n2)
{
    int i,j,k,temp=0, n3 = n1 + n2 + 1;
    c[0] = n3;
    //��ʼ���������
    for(i=1;i<n3;i++) c[i] = 0;

    for(i=1;i<n1;i++)
        for(j=1;j<n2;j++)
        {
            k = i+j-1;
            c[k] += a[i] * b[j];
        }

    //��λ����
    for(i=1;i<n3;i++)
    {
        c[i] += temp;
        temp = c[i] / 10;
        c[i] %= 10;
    }
}


int main()
{
    int strlenth = 5; //Ĭ�ϳ���
    int count1, count2;

    printf("�������һ������:\n");
    char *str1 = (char*)calloc(strlenth, sizeof(char*)); //��ȡ��һ������
    str1 = get_num(str1, &count1, strlenth); //��ȡ��һ����������

    printf("������ڶ�������:\n");
    char *str2 = (char*)calloc(strlenth, sizeof(char*)); //��ȡ�ڶ�������
    str2 = get_num(str2, &count2, strlenth); //��ȡ�ڶ�����������

    int a[count1], b[count2], fin[count1 + count2 + 1]; //����������һ����

    str_to_arr(str1, a, count1);
    str_to_arr(str2, b, count2); //������ת��Ϊ������

    multiply_arr(a,b,fin,count1,count2);

    printf("���������Ļ�Ϊ:\n");
    if(is_negative == 1) printf("-");
    print_int(fin, count1 + count2);

    free(str1); //�ͷ��ڴ�
    free(str2);
    return 0;
}