
//---------------------- shiftArrayRight -----------------------//
// Purpose: the bit-bang synchronous slowSPI, causes each read byte to be off by 1
//   Therefore, this function is used to shift each byte by the appropriate amount
// data  = a byte array of data 
// size  = size of data
// shift = # of bits by which to shift the entire array
void shiftArrayRight(uint8_t *data, uint16_t size, uint16_t shift)
{
    uint8_t carryBit = 0x00;  	 // clear the initial carry bit
	uint8_t nextBit  = 0x00;	 // the "next" carry bit
	int16_t i        = size - 1; // data array index

	// loop through the # of bits to shift
    while (shift--) 
	{                           
        for ( ; i >= 0; --i ) 
		{   
			// determine the carryBit for the next array element
            nextBit = (data[i] & 0x01) ? 0x80 : 0x00;  
			// shift the current array element and add the carryBit
            data[i] = carryBit | (data[i] >> 1);  
			// update the carry bit			
            carryBit = nextBit;                    
        }   
    }
}   