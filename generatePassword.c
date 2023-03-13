#include "randomNumberGenerator.c"
#include <stdio.h>

typedef struct
{
    int from;
    int to;
} Range;

void generate_password(char **password)
{
    Range ranges[] = {{60, 90}, {97, 122}, {48, 57}, {33, 38}};
    Range selected_range;
    int length;
    int index;
    int i;

    printf("\nEnter the length of the password =>");
    scanf("%d", &length);

    (*password) = (char *)malloc(sizeof(char) * (length + 1));

    for (i = 0; length > 0; i++, length--)
    {
        index = generate_random_number(0, sizeof(ranges) / sizeof(Range));
        selected_range = ranges[index];

        (*password)[i] = generate_random_number(selected_range.from, selected_range.to);
    }

    (*password)[i] = '\0';
}