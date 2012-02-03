/*
Copyright (c) 2012, Logan J. Drews

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<inttypes.h>

#define DELTA 0x9E3779B9

void code(uint32_t*, int32_t, uint32_t*, uint32_t*);
void decode(uint32_t*, int32_t, uint32_t*, uint32_t*);
void swap_endian(uint32_t*,uint32_t);

void main(int argc, char** argv) {
	uint32_t *v, *k, *o, *o1, *o2;
	v = calloc(4, sizeof(uint32_t));
	k = calloc(4, sizeof(uint32_t));
	o = calloc(2, sizeof(uint32_t));
	o1 = calloc(4, sizeof(uint32_t));
	o2 = calloc(4, sizeof(uint32_t));

	printf("BEGIN 64BIT BLOCKS\n");
	printf("------------------\n");

	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00000000 00000000
	*/
	code(v,  2, k, o1);
	decode(o1, 2, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1]);
	printf("\n");

	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x01020304 05060708
	*/
	v[0] = 0x01020304;
	v[1] = 0x05060708;
	code(v,  2, k, o1);
	decode(o1, 2, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1]);
	printf("\n");

	/*
	   Key       = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01020304 05060708
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899aabb;
	k[3] = 0xccddeeff;
	code(v,  2, k, o1);
	decode(o1, 2, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1]);
	printf("\n");

	/*
	   Key = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01234567 89abcdef
	*/
	v[0] = 0x01234567;
	v[1] = 0x89abcdef;
	code(v,  2, k, o1);
	decode(o1, 2, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", v[0], v[1]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1]);
	printf("\n");

	printf("BEGIN 96BIT BLOCKS\n");
	printf("------------------\n");
	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00000000 00000000 00000000
	*/
	k[0] = 0x00000000;
	k[1] = 0x00000000;
	k[2] = 0x00000000;
	k[3] = 0x00000000;
	v[0] = 0x00000000;
	v[1] = 0x00000000;
	v[2] = 0x00000000;
	code(v,  3, k, o1);
	decode(o1, 3, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", v[0], v[1], v[2]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2]);
	printf("\n");

	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00010203 04050607 08090A0B
	*/
	k[0] = 0x00000000;
	k[1] = 0x00000000;
	k[2] = 0x00000000;
	k[3] = 0x00000000;
	v[0] = 0x00010203;
	v[1] = 0x04050607;
	v[2] = 0x08090A0B;
	code(v,  3, k, o1);
	decode(o1, 3, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", v[0], v[1], v[2]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2]);
	printf("\n");

	/*
	   Key       = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x00010203 04050607 08090A0B
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899AABB;
	k[3] = 0xCCDDEEFF;
	v[0] = 0x00010203;
	v[1] = 0x04050607;
	v[2] = 0x08090A0B;
	code(v,  3, k, o1);
	decode(o1, 3, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", v[0], v[1], v[2]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2]);
	printf("\n");

	/*
	   Key       = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01234567 89ABCDEF 01234567
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899AABB;
	k[3] = 0xCCDDEEFF;
	v[0] = 0x01234567;
	v[1] = 0x89ABCDEF;
	v[2] = 0x01234567;
	code(v,  3, k, o1);
	decode(o1, 3, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", v[0], v[1], v[2]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2]);
	printf("\n");

	printf("BEGIN 128BIT BLOCKS\n");
	printf("------------------\n");
	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00000000 00000000 00000000
	*/
	k[0] = 0x00000000;
	k[1] = 0x00000000;
	k[2] = 0x00000000;
	k[3] = 0x00000000;
	v[0] = 0x00000000;
	v[1] = 0x00000000;
	v[2] = 0x00000000;
	v[3] = 0x00000000;
	code(v,  4, k, o1);
	decode(o1, 4, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n",  v[0],  v[1],  v[2],  v[3]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2], o1[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2], o2[3]);
	printf("\n");

	/*
	   Key       = 0x00000000 00000000 00000000 00000000
	   Plaintext = 0x00010203 04050607 08090A0B
	*/
	k[0] = 0x00000000;
	k[1] = 0x00000000;
	k[2] = 0x00000000;
	k[3] = 0x00000000;
	v[0] = 0x00010203;
	v[1] = 0x04050607;
	v[2] = 0x08090A0B;
	v[3] = 0x0C0D0E0F;
	code(v,  4, k, o1);
	decode(o1, 4, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n",  v[0],  v[1],  v[2],  v[3]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2], o1[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2], o2[3]);
	printf("\n");

	/*
	   Key       = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x00010203 04050607 08090A0B
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899AABB;
	k[3] = 0xCCDDEEFF;
	v[0] = 0x00010203;
	v[1] = 0x04050607;
	v[2] = 0x08090A0B;
	v[3] = 0x0C0D0E0F;
	code(v,  4, k, o1);
	decode(o1, 4, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n",  v[0],  v[1],  v[2],  v[3]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2], o1[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2], o2[3]);
	printf("\n");

	/*
	   Key       = 0x00112233 44556677 8899aabb ccddeeff
	   Plaintext = 0x01234567 89ABCDEF 01234567
	*/
	k[0] = 0x00112233;
	k[1] = 0x44556677;
	k[2] = 0x8899AABB;
	k[3] = 0xCCDDEEFF;
	v[0] = 0x01234567;
	v[1] = 0x89ABCDEF;
	v[2] = 0x01234567;
	v[3] = 0x89ABCDEF;
	code(v,  4, k, o1);
	decode(o1, 4, k, o2);
	printf("Key:        %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", k[0], k[1], k[2], k[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n",  v[0],  v[1],  v[2],  v[3]);
	printf("Ciphertext: %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o1[0], o1[1], o1[2], o1[3]);
	printf("Plaintext:  %08" PRIX32 "%08" PRIX32 "%08" PRIX32 "%08" PRIX32 "\n", o2[0], o2[1], o2[2], o2[3]);
	printf("\n");
}
/*
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (k[(p&3)^e] ^ z)))
void code(uint32_t *v, int32_t n, uint32_t *k, uint32_t *o) {
	uint32_t y, z, sum, i, an;
	unsigned p, rounds, e;

	an = n > 0 ? n : -n;
	for(i = 0; i < an; i++) {
		o[i] = v[i];
	}

	if (n > 1) {          // Coding Part
		rounds = 6 + 52/n;
		sum = 0;
		z = o[n-1];
		do {
			sum += DELTA;
			//printf("Sum Intermediate:  %08" PRIX32 "\n", sum);
			e = (sum >> 2) & 3;
			for (p=0; p<n-1; p++) {
				y = o[p+1]; 
				z = o[p] += MX;
			}
			y = o[0];
			z = o[n-1] += MX;

			//printf("Encode Intermediate:  %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
		} while (--rounds);
	} else if (n < -1) {  // Decoding Part
		n = -n;
		rounds = 6 + 52/n;
		sum = rounds*DELTA;
		y = o[0];
		do {
			//printf("Sum Intermediate:  %08" PRIX32 "\n", sum);
			e = (sum >> 2) & 3;
			for (p = n - 1; p > 0; p--) {
				z = o[p - 1];
				y = o[p] -= MX;
			}
			z = o[n - 1];
			y = o[0] -= MX;

			//printf("Decode Intermediate:  %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
		} while ((sum -= DELTA) != 0);
	}


}

void decode(uint32_t *v, int32_t n, uint32_t *k, uint32_t *o) {
	// Call code with a negative n.
	code(v, -n, k, o);
}
/**/
//*
#define MX ((((v1 >> 5) ^ (v0 << 2)) + ((v0 >> 3) ^ (v1 << 4))) ^ ((sum ^ v0) + (k[(p & 3) ^ e] ^ v1)))
void code(uint32_t *v, int32_t n, uint32_t *k, uint32_t *o) {
	uint32_t v0 = v[0],
		 v1 = v[n - 1],
		 delta = 0x9E3779B9,
		 sum = 0,
		 i,
		 e;
	unsigned m, p, q;

	// The algorithm modifies the value of v.
	// So, copy it into the output and do the operation directly on the output values.
	for(i = 0; i < n; i++) {
		o[i] = v[i];
	}

	q = 6 + 52 / n;

	for(i = 0; i < q; i++) {
		sum += delta;
		e = (sum >> 2) & 3;
		for(p = 0; p < n - 1; p++) {
			v0 = o[p + 1];
			v1 = o[p] += MX;
		}
		v0 = o[0];
		v1 = o[n-1] += MX;

		//printf("Encode Intermediate:  %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
	}
}

void decode(uint32_t *v, int32_t n, uint32_t *k, uint32_t *o) {
	uint32_t v0 = v[0],
		 v1 = v[n - 1],
		 delta = 0x9E3779B9,
		 sum = 0,
		 i,
		 e;
	unsigned m, p, q;

	// The algorithm modifies the value of v.
	// So, copy it into the output and do the operation directly on the output values.
	for(i = 0; i < n; i++) {
		o[i] = v[i];
	}

	q = 6 + 52 / n;
	sum = q * delta;

	for(i = 0; i < q; i++) {
		e = (sum >> 2) & 3;
		for(p = n - 1; p > 0; p--) {
			v1 = o[p - 1];
			v0 = o[p] -= MX;
		}
		v1 = o[n - 1];
		v0 = o[0] -= MX;
		sum -= delta;

		//printf("Decode Intermediate:  %08" PRIX32 "%08" PRIX32 "\n", o[0], o[1]);
	}
}
/**/
