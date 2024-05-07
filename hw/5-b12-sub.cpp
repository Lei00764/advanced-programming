/* 2053932 软件 雷翔 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    for (int i = count1; i < count1 + count2; i++)
        s1[i] = s2[i - count1];
    s1[count1 + count2] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    int add = len < count2 ? len : count2;
    for (int i = count1; i < count1 + add; i++)
    {
        s1[i] = s2[i - count1];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count2 = 0;
    while (s2[count2] != '\0')
        count2++;
    for (int i = 0; i < count2; i++)
        s1[i] = s2[i];
    s1[count2] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count2 = 0;
    while (s2[count2] != '\0')
        count2++;
    int add = len < count2 ? len : count2;
    for (int i = 0; i < add; i++)
    {
        if (s2[i] == '\0')
            add++;
        else
            s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    int count = count1 < count2 ? count1 : count2;
    int i;
    for (i = 0; i < count; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    
    return s1[i] - s2[i]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    int count = count1 < count2 ? count1 : count2;
    int i;
    for (i = 0; i < count; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'A' && s2[i] <= 'Z')  // 都是大写
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'a' && s2[i] <= 'z')  // 一个大写 一个小写
        {
            if (s1[i] + 'a' - 'A' != s2[i])
                return s1[i] + 'a' - 'A' - s2[i];
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'A' && s2[i] <= 'Z')  // 一个小写 一个大写
        {
            if (s2[i] + 'a' - 'A' != s1[i])
            {
                return s1[i] - 'a' + 'A' - s2[i];
            }
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'a' && s2[i] <= 'z')  // 都为小写
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z')  // 一个为小写 另一个为其他符号
        {
            return s1[i] - s2[i];
        }
        else if (s2[i] >= 'a' && s2[i] <= 'z')  // 一个为小写 另一个为其他符号
        {
            return s1[i] - s2[i];
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z')  // 一个为大写 另一个为其他符号
        {
            return s1[i] + 'a' - 'A' - s2[i];
        }
        else if (s2[i] >= 'A' && s2[i] <= 'Z')  // 一个为大写 另一个为其他符号
        {
            return s1[i] - 'a' + 'A' - s2[i];
        }
    }
    return s1[i] - s2[i]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    int count = count1 < count2 ? count1 : count2;
    count = count > len ? len : count;
    int i;
    for (i = 0; i < count; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (count < len)
        return s1[i] - s2[i];
    else
        return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (s1[count1] != '\0')
        count1++;
    while (s2[count2] != '\0')
        count2++;
    int count = count1 < count2 ? count1 : count2;
    count = count > len ? len : count;
    int i;
    for (i = 0; i < count; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'A' && s2[i] <= 'Z')  // 都是大写
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'a' && s2[i] <= 'z')  // 一个大写 一个小写
        {
            if (s1[i] + 'a' - 'A' != s2[i])
                return s1[i] + 'a' - 'A' - s2[i];
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'A' && s2[i] <= 'Z')  // 一个小写 一个大写
        {
            if (s2[i] + 'a' - 'A' != s1[i])
            {
                return s1[i] - 'a' + 'A' - s2[i];
            }
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'a' && s2[i] <= 'z')  // 都为小写
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];
        }
        else if (s1[i] >= 'a' && s1[i] <= 'z')  // 一个为小写 另一个为其他符号
        {
            return s1[i] - s2[i];
        }
        else if (s2[i] >= 'a' && s2[i] <= 'z')  // 一个为小写 另一个为其他符号
        {
            return s1[i] - s2[i];
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z')  // 一个为大写 另一个为其他符号
        {
            return s1[i] + 'a' - 'A' - s2[i];
        }
        else if (s2[i] >= 'A' && s2[i] <= 'Z')  // 一个为大写 另一个为其他符号
        {
            return s1[i] - 'a' + 'A' - s2[i];
        }
    }
    if (count < len)
        return s1[i] - s2[i];
    else
        return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    for (int i = 0; i < count; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A';
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    for (int i = 0; i < count; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    for (int i = 0; i < count; i++)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (str[count1] != '\0')
        count1++;
    while (substr[count2] != '\0')
        count2++;
    int i;
    for (i = 0; i < count1 - count2 + 1; i++)
    {
        int tag = tj_strncmp(&str[i], substr, count2);
        if (tag == 0)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    int i;
    for (i = count - 1; i >= 0; i--)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count1 = 0, count2 = 0;
    while (str[count1] != '\0')
        count1++;
    while (substr[count2] != '\0')
        count2++;
    int i;
    for (i = count1 - count2; i >= 0; i--)
    {
        int tag = tj_strncmp(&str[i], substr, count2);
        if (tag == 0)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (str[count] != '\0')
        count++;
    for (int i = 0; i < count / 2; i++)
    {
        char item;
        item = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = item;
    }
    return 0; //return值可根据需要修改
}
