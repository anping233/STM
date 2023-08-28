#pragma once

void dma_init(DMA_Stream_TypeDef *dam_streamx);
void dma_config(DMA_Stream_TypeDef *dam_streamx, uint32_t m0adr, uint32_t padr, uint16_t ndtr);