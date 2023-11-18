#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize = get_int("Start size: ");

    while ( startSize < 9) {
        startSize = get_int("Start size: ");
    };

    int endSize;

    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    int count = 0;

    while (startSize < endSize) {

        startSize = startSize + (startSize/3) - (startSize/4);
        count++;
    };

    printf("Years: %i\n", count);
}
