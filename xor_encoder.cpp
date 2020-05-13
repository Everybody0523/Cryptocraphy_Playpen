/* Implements an XOR Ciper on the contents of a file. 
 * This is not a particularly secure ciper but I guess 
 * if security is only an afterthought then go for it.
 * Or if you're just bored.
 */

#include "xor_encoder.h"

uint8_t gen_key()
{
    return static_cast<uint8_t>(std::rand() % 256);
}

void encrypt_decrypt_file(const char * iFileName, const char * oFileName, uint8_t key)
{
    std::ifstream inputFile(iFileName, std::ifstream::binary);
    std::ofstream outputFile(oFileName, std::ios::app | std::ios::binary);
     
    if (inputFile)
    {
        // Determine length of file
        inputFile.seekg(0, inputFile.end);
        size_t len = inputFile.tellg();
        inputFile.seekg(0, inputFile.beg);
        
        //Read it 1 KB at a time
        uint64_t iters = (len / 1024) + 1;
         
        for (int i = 0; i < iters; ++i)
        {
            int num_bytes = 1024;
            if (i == iters-1)
            {
                num_bytes = len % 1024;
            }

            char * buf = new char[num_bytes];
            inputFile.read(buf, num_bytes);

            for (int j = 0; j < num_bytes; ++j)
            {
                buf[j] = buf[j] ^ key;
            }

            if (outputFile.is_open())
            {
                if (!(outputFile << buf)) { std::cerr << "Doom!\n"; }
                
            }
            delete buf;
        }
    }
}

int main()
{
    uint8_t key = gen_key();
    encrypt_decrypt_file("ugh.txt", "test1.txt", key);
    encrypt_decrypt_file("test1.txt", "test2.txt", key);
}