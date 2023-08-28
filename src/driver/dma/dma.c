#include "include.h"

void dma_init(DMA_Stream_TypeDef *dam_streamx)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;

    dam_streamx->CR = (dam_streamx->CR &= ~(DMA_SxCR_EN)) | (dam_streamx->CR &= ~(DMA_SxCR_CHSEL_Msk)) | (DMA_SxCR_CHSEL_0) | (DMA_SxCR_PFCTRL) | (dam_streamx->CR &= ~(DMA_SxCR_PL_Msk))\
    | (DMA_SxCR_PL_0) | (dam_streamx->CR &= ~(DMA_SxCR_MSIZE_Msk)) | (dam_streamx->CR &= ~(DMA_SxCR_PSIZE_Msk)) | (dam_streamx->CR &= ~(DMA_SxCR_DIR_Msk))\
    | (DMA_SxCR_MINC) | (dam_streamx->CR &= ~(DMA_SxCR_PINC));
    return;
}

void dma_config(DMA_Stream_TypeDef *dam_streamx, uint32_t m0adr, uint32_t padr, uint16_t ndtr)
{
    dam_streamx->CR &= ~(DMA_SxCR_EN);
    dam_streamx->FCR &= ~(DMA_SxFCR_DMDIS);
    dam_streamx->M0AR = m0adr;
    dam_streamx->PAR = padr;
    dam_streamx->NDTR = ndtr;

    dam_streamx->CR |= (DMA_SxCR_EN);
    return;
}
