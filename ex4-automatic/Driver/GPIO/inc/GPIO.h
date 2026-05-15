#ifndef	_GPIO_H
#define	_GPIO_H

typedef unsigned int 				uint32_t;
typedef unsigned char				uint8_t;
#define LED_GREEN	5

/*!< Peripheral memory map */
#define PERIPH_BASE           0x40000000UL 		/*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define NVIC_BASE          	  0xE000E100UL    	/*!< NVIC Base Address */

/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)

/* GPIO Offset config */
typedef struct
{
  volatile uint32_t MODE;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t TYPE;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t SPEED;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PU;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IN;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t OUT;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
} GPIO_OFF;

#define PA               ((GPIO_OFF *) GPIOA_BASE)
#define PC               ((GPIO_OFF *) GPIOC_BASE)

/* CLock Register Offset */
typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  uint32_t RV1[11];
  volatile uint32_t AHB1;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  uint32_t RV2[2];
  volatile uint32_t APB1;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
} RCC_OFF;

#define RCC                ((RCC_OFF *) RCC_BASE)

typedef struct
{
  volatile uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  volatile uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  volatile uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  volatile uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
} SYSCFG_TypeDef;

typedef struct
{
  volatile uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  volatile uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  volatile uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  volatile uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  volatile uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  volatile uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;

typedef struct
{
  volatile uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;

#define NVIC         ((NVIC_Type*) NVIC_BASE)   /*!< NVIC configuration struct */
#define SYSCFG       ((SYSCFG_TypeDef*) SYSCFG_BASE)
#define EXTI         ((EXTI_TypeDef*) EXTI_BASE)


/* function led prototype */
void GPIO_Init(void);
void myDelay(uint32_t);
void Clock_Init(void);

#endif	/* !GPIO.H */

