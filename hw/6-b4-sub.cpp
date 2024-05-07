/* 2053932 ��� ���� */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    int count = 0;
    char* p = (char*)str;
    while (*p != '\0')
    {
        count++;
        p++;
    }
    return count;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL || s2 == NULL)
        return s1;
    int len = tj_strlen(s1);
    char* p1 = &s1[len];
    char* p2 = (char*)s2;
    while (*p2 != '\0')
        *p1++ = *p2++;
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL || s2 == NULL)
        return s1;
    int count1 = tj_strlen(s1);
    int count2 = tj_strlen(s2);
    int add = count2 > len ? len : count2;
    char* p1 = &s1[count1];
    char* p2 = (char*)s2;
    for (int i = 0; i < add; i++)
        *p1++ = *p2++;
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL)
        return s1;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    while (*p2 != '\0')
        *p1++ = *p2++;
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL)
        return s1;
    int count = tj_strlen(s2);
    int add = count > len ? len : count;
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    for (int i = 0; i < add; i++)
        *p1++ = *p2++;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 >= 'a' && *p1 <= 'z' && *p2 >= 'a' && *p2 <= 'z')  // ��Сд
        {
            if (*p1 != *p2)
                return *p1 - *p2;
        }
        else if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'A' && *p2 <= 'Z') // ����д
        {
            if (*p1 != *p2)
                return *p1 - *p2;
        }
        else if (*p1 >= 'a' && *p1 <= 'z' && *p2 >= 'A' && *p2 <= 'Z')  // һ����д һ��Сд
        {
            if (*p1 - 'a' + 'A' != *p2)
                return *p1 - 'a' + 'A' - *p2;
        }
        else if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'a' && *p2 <= 'z')  // һ��Сд һ����д
        {
            if (*p1 + 'a' - 'A' != *p2)
                return *p1 + 'a' - 'A' - *p2;
        }
        else if (*p1 >= 'a' && *p1 <= 'z' || *p2 >= 'a' && *p2 <= 'z')  // һ��ΪСд һ��Ϊ�����ַ�
            return *p1 - *p2;
        else if (*p1 >= 'A' && *p1 <= 'Z')  // һ��Ϊ��д һ��Ϊ�����ַ�
            return *p1 + 'a' - 'A' - *p2;
        else if (*p2 >= 'A' && *p2 <= 'Z')
            return *p1 - *p2 - 'a' + 'A';
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    int count1 = tj_strlen(s1);
    int count2 = tj_strlen(s2);
    int count = count1 < count2 ? count1 : count2;
    count = count > len ? len : count;
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    for (int i = 0; i < count; i++)
    {
        if (*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    if (count < len)
        return *p1 - *p2;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    int count1 = tj_strlen(s1);
    int count2 = tj_strlen(s2);
    int count = count1 < count2 ? count1 : count2;
    count = count > len ? len : count;
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    for (int i = 0; i < count; i++)
    {
        if (*p1 >= 'a' && *p1 <= 'z' && *p2 >= 'a' && *p2 <= 'z')  // ��Сд
        {
            if (*p1 != *p2)
                return *p1 - *p2;
        }
        else if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'A' && *p2 <= 'Z') // ����д
        {
            if (*p1 != *p2)
                return *p1 - *p2;
        }
        else if (*p1 >= 'a' && *p1 <= 'z' && *p2 >= 'A' && *p2 <= 'Z')  // һ����д һ��Сд
        {
            if (*p1 - 'a' + 'A' != *p2)
                return *p1 - 'a' + 'A' - *p2;
        }
        else if (*p1 >= 'A' && *p1 <= 'Z' && *p2 >= 'a' && *p2 <= 'z')  // һ��Сд һ����д
        {
            if (*p1 + 'a' - 'A' != *p2)
                return *p1 + 'a' - 'A' - *p2;
        }
        else if (*p1 >= 'a' && *p1 <= 'z' || *p2 >= 'a' && *p2 <= 'z')  // һ��ΪСд һ��Ϊ�����ַ�
            return *p1 - *p2;
        else if (*p1 >= 'A' && *p1 <= 'Z')  // һ��Ϊ��д һ��Ϊ�����ַ�
            return *p1 + 'a' - 'A' - *p2;
        else if (*p2 >= 'A' && *p2 <= 'Z')
            return *p1 - *p2 - 'a' + 'A';
        p1++;
        p2++;
    }
    if (count < len)
        return *p1 - *p2;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return str;
    char* p = (char*)str;
    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
            *p -= 'a' - 'A';
        p++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return str;
    char* p = (char*)str;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            *p += 'a' - 'A';
        p++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    int index = 1;
    char* p = (char*)str;
    while (*p != '\0')
    {
        if (*p == ch)
            return index;
        index++;
        p++;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    int index = 1;
    char* p = (char*)str;
    int count1 = tj_strlen(str);
    int count2 = tj_strlen(substr);
    while (*p != '\0')
    {
        int tag = tj_strncmp(p, substr, count2);
        p++;
        if (tag == 0)
            return index;
        index++;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    char* p = (char*)str;
    while (*p != '\0')
        p++;
    p--;
    int count = tj_strlen(str);
    for (int i = count; i > 0; i--)
    {
        if (*p == ch)
            return i;
        p--;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    char* p = (char*)str;
    while (*p != '\0')
        p++;
    p--;
    int count1 = tj_strlen(str);
    int count2 = tj_strlen(substr);
    for (int i = count1; i >= 0; i--)
    {
        int tag = tj_strncmp(p, substr, count2);
        if (tag == 0)
            return i;
        p--;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return str;
    char* pfront = str, *ptail = str;
    while (*ptail != '\0')
        ptail++;
    ptail--;  // ��ptailָ�����һ���ַ�
    while (pfront < ptail)
    {
        char temp = *pfront;
        *pfront = *ptail;
        *ptail = temp;
        pfront++;
        ptail--;
    }
    return str;
}
