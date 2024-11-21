#include <stdio.h>

/*
    ���������� � ������ ������� �� ALPR
    Klymenchuk Yevhenii - 21.11.2024

    ������ � ����� ����� ���������� �������� ������ ��� ����
    ���� �� ������� ����� ������:
    1)������������� ������ � �������� (���������� �������������)
    2)����� �������� ������ �������� ��� ����� ����������� ���������� (���������� �����)
    3)�������� �����-�� ������� ������� (� ������)
    4)������� ����� � ����� � ������
    5)�������� ������ � ��������� ���� �������� ������ � ����
    6)������� �������� (6 ��������)
    7)������ � ������������� �������� (�������� ���� � �����)

*/


// ---- 1 ----
// ������������� ��������
int inizializate_array(){
     /*
      -- �������� ������������� �������� --
    */

    // ������������� �������� ���������� ����������:
    int array_1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // ������ �� 10 ���������
    int array_2[10] = {1, 2, 3}; // �� ��������� ������ ����� ���� 1 2 3 0 0 0 0 0 0 0
    int array_3[10] = {0}; // ������������� ���� �������� ������� ������
    int array_4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //  !!! ������ ��� ������������� ���������� ���� ������� ���-�� �������� ���� ������!
    int array_5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // ������ ������� ����� ����� ���������� ��������� ��������
    int array_6[10] = {1, [2] = 3, 4, [9] = 5}; // ������������� � ��������� �������. ���������: 1 0 3 4 0 0 0 0 0 5

     // ������ ���������� �� �������
    int* arrays[] = {array_1, array_2, array_3, array_4, array_5, array_6}; // ����������� ��������� ������
    // ������ � ���������� ��������
    char* array_names[] = {"array_1", "array_2", "array_3", "array_4", "array_5", "array_6"};
    /*
    ���������� ���������� �������� ������� � ������� sizeof()
    sizeof() - ���������� ����� ���� ������� �������� ��������� ��� ��� ������ � ������
    size_t - ������������ ��� ��� ����� - unsigned long long
    */

    size_t bytes_marks = sizeof(array_1); // ����� �����: 10 * 4 = 40 10-���-�� ��������� ������� 4-������ ������� �������� � ������
    size_t size_marks =  sizeof(array_1) / sizeof(array_1[0]); // ���������� �������� � �������: 40 / 4 = 10
    size_t size_marks_point =  sizeof(array_1) / sizeof(*array_1); // ����� ������� ������ ��������� �������. ��������� ������ ���������� �� ������ ������� �������
    printf("bytes_marks = %zu\t size_marks = %zu\t size_marks = %zu\n", bytes_marks, size_marks, size_marks_point);  // %zu - ������������ ��� ������ ���������� ���� size_t



     // ���� ��� ������ ���� ��������
    for (int i = 0; i < 6; i++) {
        printf("%s:\n", array_names[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d ", arrays[i][j]);
        }
        printf("\n");
    }
}

/*
   ������ � ������������ ������� �� ������������� ��������

   1) ������� ���������� ������������� ������� ����� ����� � �������� 5
     a) int a[] = {2, 3, 1, 3, 2};
     b) int n=5, a[n]; --- ������ ������� �� ����� ���� ����������. �� ������ ���� ����������
     c) a[5] int; --- ��� ������ ���� � ������
     d) int a[5] = {1, 2, 3};


     �����: a � d



     2) ������� ���������� ������������� ������� ���������� ����� � �������� 5
     a) float n = 5.0, a[n];
     b) a[5] float;
     c) float a[] = {1, 3.0, 1.0, 1, 3};
     d) float a[5] = {1.0, 2.0, 3};

     �����: c � d
*/
//-----------------------------------------------------------------------------------------------------------------

// ---- 2 ----
// ������ � ������������ ������� �� "��� ����� ����������� ������" (������)

//1)
int func_str_1() {
    char s[] = "ABCDEFG";
    for (int i=0; i<7; i++){
        if(s[i] == 'C') s[i] = '*';
        else s[i]++;
    }
    printf("%s", s);
}
/*
   �������� ������:
   a)BCD*FGH
   b)AB*DEFG
   c)BCD*
   d)BC*EFGH

   �����: d) ��� ��� �� ������ ����������� ��� ASCII �� ����.
*/
//-----------------------------------------------------------------------------------------------------------------

// ---- 3 ----
// ������ � ������������ ������� �� "�������� �������" (������)
/*
   1)�������� ������� ������� � ������ ������� ��� ��������� ����� �� * � ������ ���������� ���������� ������ �������� ������
   !!! ������������ strlen() ����������
*/
// ��� �������
int male_pismena(char *str){
    int i = 0;
    int pocet_znakov = 0;

    // ��������� ������ ������
    while (str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = '*';
            pocet_znakov++;
        }
        i++;
    }
    printf("%s\n", str);
    printf("pocet_znakov: %d\n", pocet_znakov);

    return pocet_znakov;

}

// ---- 4 ----
// ������ � ������������ ������� �� "�������� �������" (������� ����� � ����� � ������)
/*
   1)�������� ������� ������� ������� ����� ����� �� ����� � ������� �� � ������ ����� �����
   � ������ ������� ������ ������������� ����� ������� ������ � ������ ���������� ��������� �����.
*/
// ��� ������� ---
int kladne_parne(int pole[], FILE *fr){
    int num = 0;
    int i = 0;
    while(fscanf(fr, "%d", &num) != EOF){
        if(num > 0 && !(num % 2)){
            pole[i] = num;
            i++;
        }
    }

    for (int j = 0; j < i; j++){
        printf("%d ", pole[j]);
    }
    printf("\n pocet_cisel: %d", i);

    return i;
}

// ----------------------------
// ���� ���� ������ � ������ � �������� ������ ����� �������
// � ������� ������� � ���������� �������� ���������� ������� ����� ��� � ��������� ������� ����� ���� ����� ����������



// ���������� ����� �� �������� � ��������
void sort_numbers(int numbers[], int size){
    int buf = 0; // ��������� ���������� ��� ������ ��������

    // ������� ����: ���������� �������� �� �������
    // ����� ������� ������� ����� ������� ������� ����������� � �����
    for (int pass = 0; pass < size - 1; pass++) {
        // ���������� ����: ��������� �������� ���������
        // �� ������ ������� ����������� ���������� ����������� ���������
        for (int j = 0; j < size - pass - 1; j++) {
            // ���� ������� ������� ������ ����������, ������ �� �������
            if (numbers[j] > numbers[j + 1]) {
                buf = numbers[j];          // ��������� �������� numbers[j] �� ��������� ����������
                numbers[j] = numbers[j + 1]; // ���������� numbers[j + 1] � numbers[j]
                numbers[j + 1] = buf;       // ���������� ������ �������� numbers[j] � numbers[j + 1]
            }
        }
    }

    // ����� �����
    for (int j = 0; j < size; j++){
        printf("%d ", numbers[j]);
    }
}

// ������ ����� �������
void revers_numbers(const char *str, int numbers[], int size){
    puts(str);

    for(int j = size - 1; j >= 0; j--){
        printf("%d ", numbers[j]);
    }
    printf("\n");
}


int file_to_array(){
     int all_numbers[100]; // ������ ���� �����
     int even_numbers[100]; // ������ ������ �����
     int odd_numbers[100]; // ������ �������� �����
     int a_i = 0, e_i = 0, o_i = 0; // ��������� ��������

     FILE *fr = fopen("cisla.txt", "r"); // ������������� �����

     // �������� �� ������� �����
     if(fr == NULL){
        printf("Error, file open!\n");
        return 1;
     }

     // ���������� ����� � ����� � ������ � ������ ������������� �������
     while(fscanf(fr, "%d", &all_numbers[a_i]) != EOF){
         // ������� �� ��������
         if(!(all_numbers[a_i] % 2)){
            even_numbers[e_i] = all_numbers[a_i];
            e_i++;
         }
         // �������� �����
         else {
            odd_numbers[o_i] = all_numbers[a_i];
            o_i++;
         }

         a_i++;
     }
     fclose(fr); // �������� �����


     // ������� ����� � �������� �������
     revers_numbers("revers even numbers", even_numbers, e_i); // ����� ������ ����� � �������� �������
     revers_numbers("revers odd numbers", odd_numbers, o_i); // ����� �������� ����� � �������� �������


     printf("Sorted numbers in ascending order: ");
     sort_numbers(all_numbers, a_i);


     printf("\n");
}

int main() {
    // ��� �������
    // inizializate_array();


    // ��� ����� 3 �������
    /*
    char str[] = "AbRaKaDaBrA!";
    male_pismena(str);
    */


    // ��� ��� ����� 4 �������
    /*
    int pole[100];
    FILE *fr = fopen("cisla.txt", "r");

    if (fr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    kladne_parne(pole, fr);
    fclose(fr);
    */

    // ������������� ---
    // file_to_array();

}
