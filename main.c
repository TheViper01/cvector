#include "cvector.h"

#define MB 1048576      // 1 megabyte in bytes = 2^20




void test_base64()
{
    char str3[] = "Ciao mi chiamo louis";
    int gg = 1;
    cstring temp_str, temp_str2;
    cstring_init(&temp_str, 0, 1);
    cstring_init(&temp_str2, 0, 1);


    //for (size_t i = 0; i < 256; i++)
    //{
    //    printf("original int:    {%d}\n", i);
    //    cstring_Base64encode(&temp_str, &i, sizeof(i));
    //    printf("encoded:    {%s}\n", cstring_cstr(&temp_str));
    //    cstring_Base64decode(&temp_str2, cstring_data(&temp_str), cstring_size(&temp_str));
    //    printf("decoded int:    {%d}\n", *((int*)(temp_str2.data)));
    //    if (i != *((size_t*)(temp_str2.data))) break;
    //    printf("\n\n");
    //}
    printf("original:   {%s}\n", str3);
    cstring_Base64encode_s(&temp_str, str3, strlen(str3));
    printf("encoded:    {%s}\n", cstring_cstr(&temp_str));
    cstring_Base64decode_s(&temp_str2, cstring_data(&temp_str), cstring_size(&temp_str));
    printf("decoded:    {%s}\n", cstring_cstr(&temp_str2));
    cvector_free(&temp_str2);
    cvector_free(&temp_str);
}

int test_cvector()
{
    char str3[] = "Ciao mi chiamo louis! ";
    //Base64encode_left(str3, strlen(str3));
    printf("\n\n");
    char str[] = "Ciao mi chiamo louis! ";
    cvector str_vector;
    cstring temp_str;
    cvector_init(&str_vector, 0, sizeof(cstring));
    temp_str = cstring_create("mi");
    cvector_push_back(&str_vector, &temp_str);
    temp_str = cstring_create("mi ");
    cvector_push_back(&str_vector, &temp_str);
    temp_str = cstring_create("mi ch");
    cvector_push_back(&str_vector, &temp_str);
    temp_str = cstring_create("Ciao mi chiamo louis! 12");
    cvector_push_back(&str_vector, &temp_str);


    cstring str1, str2;
    str1 = cstring_create(str);
    str2 = cstring_create(str3);


    printf("%s\n", cstring_cstr(&str1));
    printf("%s\n", cstring_cstr(&str2));
    printf("%d\n", cstring_compare(&str1, &str2));

    cvector_free(&str1);
    cvector_free(&str2);
    cvector_free_array(&str_vector);
    cvector_free(&str_vector);

    return 0;
}

void test_cvector_shift_left() {
    char str[] = "ciao sono louis";
    cstring str1, str2;
    str1 = cstring_create(str);
    
    cvector_shift_left(&str1, 0, 2);

    printf("%s", cstring_cstr(&str1));

    cstring_free(&str1);
}

int main() {
    test_cvector_shift_left();
    return 0;
}