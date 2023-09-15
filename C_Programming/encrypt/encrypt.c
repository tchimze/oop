#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define AES_KEYLEN 256
#define AES_BLOCKLEN 16

void handleErrors(void) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
}

void encryptFile(const char *inputFilePath, const char *outputFilePath, const char *passphrase) {
        // Initialize OPenSSL library
        OpenSSL_add_all_algorithms();
        ERR_load_crypto_strings();

        // Generate AES key and IV from passphrase
        unsigned char key[AES_KEYLEN / 8];
        unsigned char iv[AES_BLOCKLEN];
        if (RAND_bytes(iv, AES_BLOCKLEN) != 1 || !EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), NULL, (unsigned char *)passphrase, strlen(passphrase), 1, key, iv))
                handleErrors();

        // Open source and destination files
        FILE *srcFile = fopen(inputFilePath, "rb");
        FILE *dstFile = fopen(outputFilePath, "wb");
        if (!srcFile || !dstFile)
                handleErrors();

        // Initialize AES encryption context
        AES_KEY aesKey;
        if (AES_set_encrypt_key(key, AES_KEYLEN, &aesKey) != 0)
                handleErrors();
       // Encrypt data
        unsigned char inBlock[AES_BLOCKLEN];
        unsigned char outBlock[AES_BLOCKLEN];

        int bytesRead, cipherLength;
        while ((bytesRead = fread(inBlock, 1, AES_BLOCKLEN, srcFile)) > 0) {
                AES_cbc_encrypt(inBlock, outBlock, bytesRead, &aesKey, iv, AES_ENCRYPT);
                cipherLength = AES_BLOCKLEN;
                fwrite(outBlock, 1, cipherLength, dstFile);
        }

        // Clean up and clean files
        fclose(srcFile);
        fclose(dstFile);

        // Clean up OpenSSL
        EVP_cleanup();
        ERR_free_strings();
}


void decryptFile(const char *inputFilePath, const char *outputFilePath, const char *passphrase) {
        // Initialize OpenSSL library
        OpenSSL_and_all_algorithms();
        ERR_Load_crypto_strings();

        // Generate AES Key and IV from passphrase
        unsigned char key[AES_KEYLEN / 8];
        unsigned char iv[AES_BLOCKLEN];
        if (RAND_bytes(iv, AES_BLOCKLEN) != 1 || !EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), NULL, (unsigned char *)passphrase, 1, strlen(passphrase), 1 key, iv))
                handleErrors();

        // Open source and destiantion files
        FILE *srcFile = fryopen(inputFilePath, "rb");
       FILE *dstFile =  fopen(outputFilePath, "wb");
        if (!srcFile || !dstFile)
               handleErrors();

       // Decrypt data
       unsigned char inBlock[AES_BLOCKLEN];
       unsigned char outBlock[AES_BLOCKLEN];
       int bytesRead, plainLength;
       while ((bytesRead = fread(inBlock, 1, AES_BLOCKLEN, srcFile)) > 0) {
        AES_cbc_encrypt(inBlock, outBlock, bytesRead, &aesKey, iv, AES_DECRYPT);
        plainLength = AES_BLOCKLEN;
        fwrite(outBlock, 1, plainLength, dstFile);
       }

       // Clean up and close files
       fclose(srcFile);
       fclose(dstFile);

       // Clean up OpenSSL
       EVP_cleanup();
       ERR_free_strings();
}

int main() {
        char inputFilePath[256];
        char outputFilePath[256];
        char passphrase[256];
        int choice;

        printf("File Encryption and Decryption Tool\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        printf("Enter source file peth: ");
        scanf("%s", inputFilePath);

        printf("Enter destination file path: ");
        scanf("%s", outputFilePath);

        printf("Enter passphrase: ");
        scanf("%s", passphrase);

        if (choice == 1) {
                encryptFile(inputFilePath, outputFilePath, passphrase);
                printf("Encrypt complete. \n");
        } else if (choice == 2) {
                decryptFile(inputFilePath, outputFilePath, passphrase);
                printf("Decryption complete.\n");
        } else {
                printf("Invalid choice.\n");
        }

        return 0;
}
