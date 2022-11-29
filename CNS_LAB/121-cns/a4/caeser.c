#include <gmp.h>
#include <stdio.h>
int main(){
	mpz_t shift, pos, new_pos;
	mpz_inits(shift, pos, new_pos, NULL);
	char msg[100];
	gmp_printf("Enter the string to encrypt: ");
	scanf("%s", msg);
	gmp_printf("Enter the shift of position: ");
	gmp_scanf("%Zd", &shift);
	
	// starting the encryption
	for(int i = 0; msg[i] != '\0'; i++){
		mpz_set_ui(pos, msg[i]-'a');
		mpz_add(new_pos, pos, shift);
		mpz_mod_ui(new_pos, new_pos, 26);
		int new_char = mpz_get_ui(new_pos);
		msg[i] = new_char + 'a';
	}
	printf("\nEncrypted message using Caeser Cipher: ");
	printf("%s\n", msg);

	// decrypting the encrypted message
	for(int i = 0; msg[i] != '\0'; i++){
                mpz_set_ui(pos, msg[i]-'a');
                mpz_sub(new_pos, pos, shift);
                mpz_mod_ui(new_pos, new_pos, 26);
                int new_char = mpz_get_ui(new_pos);
                msg[i] = new_char + 'a';
        }
	printf("\nDecrypting the Encrypted message using Caeser Cipher: ");
        printf("%s\n", msg);

	return 0;

}
