Bob key generation

1. Pick prime numbers p and q.
	p = 7
	q = 11
2. n = p * q
	n = 77
3. (p-1)(q-1) = 6 * 10 = 60
	chose e; 1 < e < 60; e should be coprime with 60. 
	e = 13
4. Find d; d*e = 1 mod 60
	d * 13 = 1 mod 60
	d = 37
----------------------------

Alice key generation

1. Pick prime numbers p and q
	p = 3
	q = 11
2. n = p * q
	n = 33
3. (p-q)(q-1) = 2 * 10 = 20
	chose e; 1 < e < 20; e should be coprime with 33
	e = 7
4. Find d; d*e = 1 mod 20
	d*5 = 1 mod 20
	d = 3

------------------------------
 
Encrypting Message. Bob->Alice

Encrypted message = M, let M = 2
	C = M^eA mod nA
	C = 2^7 mod 33
	C = 29

Bobs signature = S
	S = M^dB mod nB
	S = 2^37 mod 77
	S = 51

Encrypted Bobs Signature = eS
	eS = S^eA mod nA (encrypt same way we encrypt the message)
	eS = 51^7 mod 33
	eS = 6

Bob sends to Alice
(C, eS)

------------------------------

Decrypting Message from Bob.

Alice receives
(C, eS)
(23,6)

Decrypted Message = M
	M = C^dA mod nA
	M = (29^3) mod 33
	M = 2
	= Original M

Decrypt Signature
	eS^dA mod nA
	6^3 mod 33
	= 18

Verify Signature	
	eS^eB mod nB
	6^13 mod 77
	= 18
	
18 = 18, Signature is verified..
