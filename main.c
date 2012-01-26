#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<inttypes.h>

void code(uint32_t*, uint32_t*, uint32_t*);
void decode(uint32_t*, uint32_t*, uint32_t*);

void main(int argc, char** argv) {
	uint32_t *v, *k, *o;
	v = calloc(2, sizeof(uint32_t));
	k = calloc(4, sizeof(uint32_t));
	o = calloc(2, sizeof(uint32_t));

	/*
	   Key = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00000000 00000000
	*/
	code(v, k, o);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
	printf("\n");

	/*
	   Key = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x01020304 05060708
	*/
	v[0] = 0x01020304;
	v[1] = 0x05060708;
	code(v, k, o);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
	printf("\n");

	/*
	   Key = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01020304 05060708
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899aabb;
	k[3] = 0xccddeeff;
	code(v, k, o);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
	printf("\n");

	/*
	   Key = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01234567 89abcdef
	*/
	v[0] = 0x01234567;
	v[1] = 0x89abcdef;
	code(v, k, o);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
}


void code(uint32_t *v, uint32_t *k, uint32_t *o) {
	uint32_t v0 = v[0],
	         v1 = v[1],
		 delta = 0x9E3779B9,
	         sum = 0,
		 i;

	for(i = 0; i < 32; i++) {
		sum += delta;
		v0 += (v1 << 4)+k[0] ^ v1+sum ^ (v1 >> 5)+k[1];
		v1 += (v0 << 4)+k[2] ^ v0+sum ^ (v0 >> 5)+k[3];
	}

	o[0] = v0;
	o[1] = v1;
}

void decode(uint32_t *v, uint32_t *k, uint32_t *o) {
	uint32_t v0 = v[0],
	         v1 = v[1],
		 delta = 0x9E3779B9,
	         sum = delta << 5,
		 i;

	for(i = 0; i < 32; i++) {
		v1 -= (v0 << 4)+k[2] ^ v0+sum ^ (v0 >> 5)+k[3];
		v0 -= (v1 << 4)+k[0] ^ v1+sum ^ (v1 >> 5)+k[1];
		sum -= delta;
	}

	o[0] = v0;
	o[1] = v1;
}
