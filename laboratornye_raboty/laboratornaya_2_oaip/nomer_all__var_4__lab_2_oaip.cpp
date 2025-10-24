#include <iostream>
#include <cstring>

using namespace std;

// ___________________________________| № 1
int count_b_in_end(char *ptr)
{
    int count_b = 0;

    while (*ptr != '\0')
    {
        if (*ptr == ' ' && *(ptr - 1) == 'b')
        {
            ++count_b;
        }

        ++ptr;
    }

    return count_b;
}

// ___________________________________| № 2
int find_the_longest_word(char *ptr)
{
    int cur_len = 0;
    int max_len = 0;

    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            if (cur_len > max_len)
            {
                max_len = cur_len;
            }
            
            cur_len = 0;
        }
        else
        {
            ++cur_len;
        }

        ++ptr;
    }

    if (cur_len > max_len)
    {
        max_len = cur_len;
    }

    return max_len;
}

// ___________________________________| № 3
int count_d_in_last_word(char *ptr)
{
    char *ptr_len = ptr;
    int str_len = 0;
    int count_d = 0;

    while (*ptr_len != '\0')
    {
        ++str_len;
        ++ptr_len;
    }

    --str_len;

    while (*(ptr + str_len) != ' ')
    {
        if (*(ptr + str_len) == 'd')
        {
            ++count_d;
        }

        --str_len;

        if (str_len == 0)
        {
            break;
        }
    }

    return count_d;
}

// ___________________________________| № 4
void to_upper(char *ptr)
{
    while (*ptr != '\0')
    {
        char cur_simbol = ' ';
        if (*ptr == tolower(*ptr))
        {
            cur_simbol = toupper(*ptr);
        }

        cout << cur_simbol;

        ++ptr;
    }

    cout << endl;
}

// ___________________________________| № 5
int count_coincidences(char *ptr)
{
    int count_con = 0;
    int cur_word_len = 0;

    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            if (*(ptr - cur_word_len + 1) == *(ptr - 2))
            {
                ++count_con;
            }

            cur_word_len = 0;
        }
        else
        {
            ++cur_word_len;
        }

        ++ptr;
    }

    return count_con;
}

// ___________________________________| № 6
void find_longest_substr(char *ptr)
{
    char substr[] = "";
    while (*ptr != '\0')
    {
        char str1[100] = "";
        if (*ptr == ' ')
        {

        }
        else
        {
            strncpy(str1, ptr, 1);
        }

        cout << str1 << endl;

        ++ptr;
    }
}

int main()
{
    char myString[] = "stem cob flower leaf shrub bulb root herb branch tree";
    char *ptrMyString = myString;

    // № 1
    cout << "Количество слов, оканчивающихся на b, равно: " << count_b_in_end(ptrMyString) << endl;

    // № 2
    cout << "Самое длинное имеет длину: " << find_the_longest_word(ptrMyString) << endl;

    // № 3
    cout << "Количество букв d в последнем слове строки равно: " << count_d_in_last_word(ptrMyString) << endl;

    // № 4
    to_upper(ptrMyString);

    // № 5
    cout << "Количество слов, у которых совпадает второй и предпоследний символ, равно: " << count_coincidences(ptrMyString) << endl;

    // № 6
    find_longest_substr(ptrMyString);

    return 0;
}