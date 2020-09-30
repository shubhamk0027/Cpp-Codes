The well-known algorithm for conversion from Gray to binary is a linear sequence of XORs that makes it seem each bit must be dealt with separately. Fortunately, that is equivalent to a parallel prefix XOR that can be computed using SWAR techniques in log time. For 32-bit Gray code values produced as described above, the conversion from Gray code back to unsigned binary is:



unsigned int
g2b(unsigned int gray)
{
        gray ^= (gray >> 16);
        gray ^= (gray >> 8);
        gray ^= (gray >> 4);
        gray ^= (gray >> 2);
        gray ^= (gray >> 1);
        return(gray);
}