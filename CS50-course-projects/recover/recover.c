#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("File could not be opened\n");
        return 2;
    }

    unsigned char *temp = malloc(BLOCK_SIZE);
    int n = 0;
    char jpgfilename[8];
    FILE *filename;

    size_t bytes_read = fread(temp, sizeof(char), BLOCK_SIZE, card);
    printf("bytes read are %zu\n", bytes_read);
    int x = 1;
    while (bytes_read > 0)
    {
        int i;
        for (i = 0; i < BLOCK_SIZE; i++)
        {
            if (temp[i] == 0xFF && temp[i + 1] == 0xD8 && temp[i + 2] == 0xFF && temp[i + 3] >= 0xE0 && temp[i + 3] <= 0xEF)
            {
                printf("x is %d\n", x);
                fseek(card, (BLOCK_SIZE * (x - 1)) + 1, SEEK_SET);
                fseek(card, i - 1, SEEK_CUR);

                printf("i is %d\n", i);
                printf("%02X, %02X, %02X, %02X\n", temp[i], temp[i + 1], temp[i + 2], temp[i + 3]);

                break;
            }
        }
        if (i == BLOCK_SIZE)
        {
            bytes_read = fread(temp, sizeof(char), BLOCK_SIZE, card);
            x++;
        }
        else
            break;
    }

    bytes_read = fread(temp, sizeof(char), BLOCK_SIZE, card);
    printf("bytes read are %zu\n", bytes_read);
    printf("1st set is %02X, %02X, %02X, %02X\n", temp[0], temp[1], temp[2], temp[3]);
    int count = 0;
    while (bytes_read == BLOCK_SIZE)
    {
        // printf("%02X, %02X, %02X, %02X\n",temp[0],temp[1],temp[2],temp[3]);
        if (temp[0] == 0xFF && temp[1] == 0xD8 && temp[2] == 0xFF && temp[3] >= 0xE0 && temp[3] <= 0xEF)
        {
            if (n > 0)
            {
                fclose(filename);
            }
            sprintf(jpgfilename, "%03d.jpg", n);
            printf("created file %s\n", jpgfilename);
            filename = fopen(jpgfilename, "a");
            if (filename == NULL)
            {
                printf("File could not be created\n");
                fclose(card);
                return 3;
            }
            n++;
        }

        fwrite(temp, 1, BLOCK_SIZE, filename);
        bytes_read = fread(temp, sizeof(char), BLOCK_SIZE, card);
        count++;
    }
    printf("count is %d \n", count);
    fclose(filename);
    fclose(card);
    free(temp);
}