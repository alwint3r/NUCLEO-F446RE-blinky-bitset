#include <stm32f4xx_hal.h>
#include <bitset>

using Reg = std::bitset<32>;

void LED_Init();

int main()
{
    HAL_Init();
    LED_Init();

    while (1)
    {
        GPIOA->BSRR = Reg(0).set(5).to_ulong();

        HAL_Delay(1000);

        GPIOA->BSRR = Reg(0).set(5 + 16).to_ullong();

        HAL_Delay(1000);
    }
}

void LED_Init()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIOA->MODER = Reg(GPIOA->MODER).set(10).reset(11).to_ulong();
    GPIOA->OTYPER = Reg(GPIOA->OTYPER).reset(5).to_ulong();
    GPIOA->OSPEEDR = Reg(GPIOA->OSPEEDR).set(10).reset(11).to_ulong();
    GPIOA->PUPDR = Reg(GPIOA->PUPDR).reset(10).reset(11).to_ulong();
}

extern "C" void SysTick_Handler()
{
    HAL_IncTick();
}