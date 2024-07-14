#include <stdio.h>
#include <string.h>

// Arrays for storing words corresponding to digits and tens multiples
char *single_digits[] = {"zero", "one", "two", "three", "four",
                         "five", "six", "seven", "eight", "nine"};

char *two_digits[] = {"ten", "eleven", "twelve", "thirteen",
                      "fourteen", "fifteen", "sixteen", "seventeen",
                      "eighteen", "nineteen"};

char *tens_multiple[] = {"", "", "twenty", "thirty", "forty",
                         "fifty", "sixty", "seventy", "eighty", "ninety"};

char *place_values[] = {"", "thousand", "lakh", "crore"};

// Function to convert two-digit number to words
void convert_two_digits(int num, char *out)
{
    if (num < 10)
    {
        strcat(out, single_digits[num]);
    }
    else if (num >= 10 && num < 20)
    {
        strcat(out, two_digits[num - 10]);
    }
    else
    {
        strcat(out, tens_multiple[num / 10]);
        if (num % 10 != 0)
        {
            strcat(out, " ");
            strcat(out, single_digits[num % 10]);
        }
    }
    strcat(out, " ");
}

// Function to convert three-digit number to words
void convert_three_digits(int num, char *out)
{
    if (num >= 100)
    {
        strcat(out, single_digits[num / 100]);
        strcat(out, " hundred ");
        num %= 100;
    }
    if (num != 0)
    {
        convert_two_digits(num, out);
    }
}

// Function to convert number to words
void convert_to_words(char *num)
{
    int len = strlen(num);

    if (len == 0)
    {
        printf("Empty string\n");
        return;
    }
    if (len > 9)
    {
        printf("Length more than 9 is not supported\n");
        return;
    }

    char out[1000] = "";        // Output string initialized
    int segment_value[4] = {0}; // Array to hold crore, lakh, thousand, hundreds
    int segment_index = 0;

    // Process the number from the end and store segments
    while (len > 0)
    {
        if (segment_index == 0)
        { // Handle last 3 digits
            if (len >= 3)
            {
                segment_value[segment_index] = (num[len - 3] - '0') * 100 + (num[len - 2] - '0') * 10 + (num[len - 1] - '0');
                len -= 3;
            }
            else if (len == 2)
            {
                segment_value[segment_index] = (num[len - 2] - '0') * 10 + (num[len - 1] - '0');
                len -= 2;
            }
            else if (len == 1)
            {
                segment_value[segment_index] = num[len - 1] - '0';
                len -= 1;
            }
        }
        else
        { // Handle 2-digit segments (thousands, lakhs, crores)
            if (len >= 2)
            {
                segment_value[segment_index] = (num[len - 2] - '0') * 10 + (num[len - 1] - '0');
                len -= 2;
            }
            else if (len == 1)
            {
                segment_value[segment_index] = num[len - 1] - '0';
                len -= 1;
            }
        }
        segment_index++;
    }

    // Convert stored segments to words and concatenate
    for (int i = segment_index - 1; i >= 0; i--)
    {
        if (segment_value[i] != 0)
        {
            if (i == 0)
            {
                convert_three_digits(segment_value[i], out);
            }
            else
            {
                convert_two_digits(segment_value[i], out);
                strcat(out, place_values[i]);
                strcat(out, " ");
            }
        }
    }

    printf("%s\n", out);
}

void menu()
{
    printf("Menu:\n");
    printf("1. Convert number to words\n");
    printf("2. Exit\n");
}

int main(void)
{
    char num[10]; // Array to hold the input number as a string
    int choice;

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number (up to 9 digits): ");
            scanf("%9s", num);
            convert_to_words(num);
            break;
        case 2:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
