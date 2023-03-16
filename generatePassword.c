#include "randomNumberGenerator.c"
#include <stdio.h>

typedef struct
{
    int from;
    int to;
} Range;

void generate_password(char **password)
{
    Range ranges[] = {{64, 90}, {97, 122}, {48, 57}, {33, 38}};
    Range selected_range;
    int index;
    int i;
    int ranges_length = sizeof(ranges) / sizeof(Range);

    printf("\nEnter the length of the password => ");
    int password_length = get_int();

    (*password) = (char *)malloc(sizeof(char) * (password_length + 1));

    for (i = 0; password_length > 0; i++, password_length--)
    {
        index = generate_random_number(0, ranges_length - 1);
        selected_range = ranges[index];

        (*password)[i] = generate_random_number(selected_range.from, selected_range.to);
    }

    (*password)[i] = '\0';
}
