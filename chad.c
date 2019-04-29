#include <string.h>
#include <stdio.h>
void rotEncrypt(rotKey, text);
void rotDecrypt(rotKey, text);
void subEncrypt(subKey, text);
void subDecrypt(subKey, text);
int main()
{
    int p;
    printf("1) Encrypt with rotation cipher and key\n2) Decrypt rotation cipher with key\n3) Encrypt with substitution cipher and key\n4) Decrypt substitution cipher with key\nEnter procedure: ");
    scanf("%d", &p);
    char text[500];
    int rotKey;
    char subKey[26];
    int c;
    /* discard all characters up to and including newline */
    while ((c = getchar()) != '\n' && c != EOF); 
    switch(p) {
        case 1: 
            printf("Enter the message you would like to encrypt: ");
            fgets(text,sizeof(text),stdin);
            printf("Enter your key: ");
            scanf("%d", &rotKey);
            rotEncrypt(rotKey, text);
            break;
        case 2:
            printf("Enter the message you would like to decrypt: ");
            fgets(text,sizeof(text),stdin);
            printf("Enter your key: ");
            scanf("%d", &rotKey);
            rotDecrypt(rotKey, text);
            break;
        case 3:
            printf("Enter the message you would like to encrypt: ");
            fgets(text,sizeof(text),stdin);
            printf("Enter your key: ");
            scanf("%s", subKey);
            subEncrypt(subKey,text);
            break;
        case 4:
            printf("Enter the message you would like to decrypt (all lowercase): ");
            fgets(text,sizeof(text),stdin);
            printf("Enter your key: ");
            scanf("%s", subKey);
            subDecrypt(subKey,text);
            break;
        default: printf("This prodedure does not exist");
    }
    return 0;
}
void rotEncrypt (int rotKey, char text[]) 
{
   char character = 0;
   char output[sizeof(text)];
   for(int x = 0; x < sizeof(text); x++)
      {
        character = text[x];
        if (character >= 65 && character <= 90)
	        {
	            character = character - 65;
	            character = (character + rotKey) % 26;
	            character = character + 65;
	        }
	    else if (character >= 97 && character <= 122)
	        {
	            character = character - 97;
	            character = (character + rotKey) % 26;
	            character = character + 97;
            }
        output[x] = character;
        }
    printf("Encrypted message: %s", output);
}
  
  void rotDecrypt (int rotKey, char text[]) {
   char character = 0;
   char output[sizeof(text)];
   for(int x = 0; x < sizeof(text); x++)
      {
        character = text[x];
	if (character >= 65 && character <= 90)
	  {
	    character = character - 65;
	    character = (character - rotKey); 
	    if(character < 0)
	    {
	        character = character + 26;
	    }
	    character = character % 26;
	    character = character + 65;
	  }
	else if (character >= 97 && character <= 122)
	  {
	    character = character - 97;
	    character = (character - rotKey);
	     if(character < 0)
	    {
	        character = character + 26;
	    }
	    character = character % 26;
	    character = character + 97;
	  }
        output[x] = character;
    }
    printf("Decrypted message: %s", output);
  }
  
  void subEncrypt (char subKey[], char text[]){
/*/    input[strlen(text) - 1] = 0;                       
    int count = strlen(text);                         

    char output[count];                                 
    for(int i = 0; i < count; i++) {                    
        int index = ((int) input[i]) - 97;              
        if(index < 0) {
            output[i] = ' ';                            
        }
        else {
            output[i] = subKey[index];             
        }
    }
    output[count] = 0;                                 

    printf("output: %s\n", output);    /*/               
} 
  
  void subDecrypt (char subKey[], char text[]) {
    int index = 0;
    char character = 0;
    char output[sizeof(text)];
    for(int x = 0; x < 256; x++)
    {
    character = text[x];
    if(character >= 65 && character <= 90)
    {
      for(int i = 0; i < 26; i++)
      {
        if(subKey[i] == character)
          index = i;
      }
    character = index + 65;
    }
    if(character >= 97 && character <= 122)
    {
      for(int i = 0; i < 26; i++)
      {
        if(subKey[i] == character)
          index = i;
      }
    character = index + 97;
    }
    output[x] = character;
    }
    printf("Decrypted message: %s\n", output);
}
