#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1])!=26 )
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

        for (int i=0; i<26; i++)
        {
            if (isalpha(argv[1][i])==0)
            {
                 printf("one or more letters are NOT alphabets\n");
                    return 1;
            }
            for (int j=i+1; j<26; j++)
            {
                if(argv[1][i]==argv[1][j])
                {
                    printf("one or more letters are duplicate\n");
                    return 1;
                }

            }
        }

    string pt=get_string("plaintext: ");
    for (int i=0; pt[i]!='\0'; i++)
    {
        if (isupper(pt[i]))
        pt[i]=toupper(argv[1][pt[i]-'A']);
        else if (islower(pt[i]))
        pt[i]=tolower(argv[1][pt[i]-'a']);
    }
    printf("ciphertext: %s\n", pt);

}