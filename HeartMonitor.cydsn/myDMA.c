/* ========================================

 * ========================================
*/
#include "myDMA.h"
#include "testSpeak.h"

//void DMA_Config(void)
//{
//    /* Variable declarations for DMA_1 */
//    uint8 DMA_1_Chan;
//    uint8 DMA_1_TD[1];
//}


//! @brief DMA Configuration for Transfer 
//!   and flash array and DAC
void DMA_Config(void)
{	
    // set addresses of array and DAC
    // must increment src
    // repeat DMA continuously
    // enable DMA
    
    #define DMA_1_BYTES_PER_BURST (1u)
	#define DMA_1_REQUEST_PER_BURST (1u)
	//#define UPPER_SRC_ADDRESS        CYDEV_FLASH_BASE //CYDEV_SRAM_BASE //CYDEV_FLASH_BASE
	#define UPPER_DEST_ADDRESS       CYDEV_PERIPH_BASE

	uint8 dma_audioOut;
	uint8 dma_audioOut_channel;

	
	/* DMA_OUT_B -- DFB to DAC*/
    dma_audioOut = CyDmaTdAllocate();
    
    dma_audioOut_channel = 
		DMA_1_DmaInitialize(DMA_1_REQUEST_PER_BURST, 
								DMA_1_BYTES_PER_BURST, 
								//HI16((uint32)UPPER_SRC_ADDRESS), // does not work
                                HI16((uint32)sin100),
								HI16((uint32)VDAC8_Data_PTR));	
        
    CyDmaTdSetConfiguration(dma_audioOut, 
							sin100Size, 
							DMA_INVALID_TD, 
							DMA_1__TD_TERMOUT_EN | CY_DMA_TD_INC_SRC_ADR ); 

        
    CyDmaTdSetAddress(dma_audioOut, 
		LO16((uint32)sin100), LO16((uint32)VDAC8_Data_PTR));
	CyDmaChSetInitialTd(dma_audioOut_channel, dma_audioOut);
	CyDmaChEnable(dma_audioOut_channel, 1u);
	
	#undef UPPER_SRC_ADDRESS 
	#undef UPPER_DEST_ADDRESS 
    #undef DMA_1_BYTES_PER_BURST  
	#undef DMA_1_REQUEST_PER_BURST 
}












/* [] END OF FILE */
