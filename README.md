# Vigen-re-Cipher
A simple C++ implementation of the Vigenère Cipher for encrypting and decrypting text. This program includes functionality for generating repeating keywords, modular arithmetic for encryption/decryption, and a user-friendly menu interface for input and output. Perfect for learning basic cryptography concepts.

Programming Approaches

Key Generation: The keyword is repeated cyclically to match the length of the plaintext or ciphertext.
Encryption: Each plaintext character is encoded by shifting it based on the corresponding keyword character, using modular arithmetic.
Decryption: The ciphertext is decoded by reversing the process, finding the original plaintext character using the modular difference.
User Interaction: A menu-driven system guides the user through encryption, decryption, or exiting the program.
Error Handling: Input is validated to ensure only uppercase alphabetical characters are processed.

Authors: Ali Sajjad

Date Published: 12/04/24

Basic Instructions:

1. Compile the Program
Use any C++ compiler (e.g., GCC or an IDE like Code::Blocks) to compile the code.

2. Run the Program
Execute the compiled program.

3. Use the Menu
Select 1 to encrypt a message.
Select 2 to decrypt a message.
Enter text and keyword as prompted (uppercase letters only).


4. Exit the Program
Choose 3 to terminate the program.

Program Requirements
The program supports uppercase English letters only (A-Z).
Keywords must also be uppercase.
