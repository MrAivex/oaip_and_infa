#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

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
string find_longest_substr(string str)
{
    string cur_str = "";
    vector<string> arr;
    for (char s : str)
    {
        if (s != ' ')
        {
            cur_str = cur_str + s;
        }
        else
        {
            arr.insert(arr.end(), cur_str);
            cur_str = "";
        }
    }

    arr.insert(arr.end(), cur_str);

    string max_substr = "";

    // for (string word1 : arr)
    // {
        // for (string word2 : arr)
        // {
        //     if (word1 != word2)
        //     {
        //         for (int i = 0; i < word1.length(); ++i)
        //         {
        //             for (int j = i; j < word1.length(); ++j)
        //             {
        //                 string word_part = word1.substr(i, j);
        //                 if (word2.find(word_part) != string::npos && word_part.length() > max_substr.length())
        //                 {
        //                     max_substr = word_part;
        //                 }
        //             }  
        //         }
        //     }
        //     else
        //     {
                
        //     }
        // }

        for (int elem = 0; elem < arr.size() - 1; ++elem)
        {
            string word1 = arr.at(elem);
            string word2 = arr.at(elem + 1);
            for (int i = 0; i < word1.length(); ++i)
                {
                    for (int j = i; j < word1.length(); ++j)
                    {
                        string word_part = word1.substr(i, j + 1);
                        if (word2.find(word_part) != string::npos && word_part.length() > max_substr.length())
                        {
                            max_substr = word_part;
                        }
                    }  
                }
        }

    return max_substr;
}

int main()
{
    char myString[] = "stem cob flower leaf shrub bulb root herb branch tree";
    char *ptrMyString = myString;
    string myStr;
    vector<string> strArr;

    cout << "Введите 10 слов: ";
    getline(cin, myStr);

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
    cout << "Самая длинная общая подстрока: " << find_longest_substr(myStr) << endl;

    return 0;
}