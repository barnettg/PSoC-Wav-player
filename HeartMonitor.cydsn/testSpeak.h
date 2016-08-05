/* ========================================
 *
        Test speaking
http://itk.ilstu.edu/faculty/javila/DataTypes/soundWav.htm
Byte Number 	Size 	Description 	    Value
0-3 	        4 	    Chunk ID 	        "RIFF" (0x52494646)
4-7 	        4 	    Chunk Data Size 	(file size) - 8
8-11 	        4 	    RIFF Type 	        "WAVE" (0x57415645)
  	  	  	 

Byte Number 	Size 	Description 	    Value
0-3 	        4 	    Chunk ID 	        "fmt " (0x666D7420)
4-7 	        4 	    Chunk Data Size 	Length Of format Chunk (always 0x10)
8-9 	        2 	    Compression code 	Always 0x01
10 - 11 	    2 	    Channel Numbers 	0x01=Mono, 0x02=Stereo
12 - 15 	    4 	    Sample Rate 	    Binary, in Hz
16 - 19 	    4 	    Bytes Per Second 	 
20 - 21 	    2 	    Bytes Per Sample 	1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
22 - 23 	    2 	    Bits Per Sample 	             

Byte Number 	Size 	Description 	    Value
0-3 	        4 	    Chunk ID 	        "data" (0x64617461)
4-7 	        4 	    Chunk Data Size 	length of data to follow
8-end 	  	            Data 	            sound samples        

        
 *
 * ========================================
*/

#include <project.h>

extern uint16 sin100Size;
extern volatile const uint8 sin100[ ];

extern uint16 sin1000Size;
extern volatile const uint8 sin1000[ ];






/* [] END OF FILE */
