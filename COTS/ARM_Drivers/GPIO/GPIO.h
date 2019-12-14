/*
 * GPIO.h
 *
 *  Created on: Dec 14, 2019
 *      Author: admin
 */

#ifndef GPIO_H_
#define GPIO_H_



#define GPIOA_BASE                      0x40004000UL
#define GPIOB_BASE                      0x40005000UL
#define GPIOC_BASE                      0x40006000UL
#define GPIOD_BASE                      0x40007000UL
#define GPIOE_BASE                      0x40024000UL
#define GPIOF_BASE                      0x40025000UL


typedef enum
{
    INPUT,
    OUTPUT

}PinDirection_t;

typedef enum
{
    LOW,
    HIGH

}PinState_t;


typedef enum
{
    PULL_UP,
    PULL_DOWN,
    NONE

}PinPullUpAndDown_t;


typedef struct {                               /*!< GPIOA Structure                                                       */
  uint32_t  RESERVED0[255];
  uint32_t  DATA;                              /*!< GPIO Data                                                             */
  uint32_t  DIR;                               /*!< GPIO Direction                                                        */
  uint32_t  IS;                                /*!< GPIO Interrupt Sense                                                  */
  uint32_t  IBE;                               /*!< GPIO Interrupt Both Edges                                             */
  uint32_t  IEV;                               /*!< GPIO Interrupt Event                                                  */
  uint32_t  IM;                                /*!< GPIO Interrupt Mask                                                   */
  uint32_t  RIS;                               /*!< GPIO Raw Interrupt Status                                             */
  uint32_t  MIS;                               /*!< GPIO Masked Interrupt Status                                          */
  uint32_t  ICR;                               /*!< GPIO Interrupt Clear                                                  */
  uint32_t  AFSEL;                             /*!< GPIO Alternate Function Select                                        */
  uint32_t  RESERVED1[55];
  uint32_t  DR2R;                              /*!< GPIO 2-mA Drive Select                                                */
  uint32_t  DR4R;                              /*!< GPIO 4-mA Drive Select                                                */
  uint32_t  DR8R;                              /*!< GPIO 8-mA Drive Select                                                */
  uint32_t  ODR;                               /*!< GPIO Open Drain Select                                                */
  uint32_t  PUR;                               /*!< GPIO Pull-Up Select                                                   */
  uint32_t  PDR;                               /*!< GPIO Pull-Down Select                                                 */
  uint32_t  SLR;                               /*!< GPIO Slew Rate Control Select                                         */
  uint32_t  DEN;                               /*!< GPIO Digital Enable                                                   */
  uint32_t  LOCK;                              /*!< GPIO Lock                                                             */
  uint32_t  CR;                                /*!< GPIO Commit                                                           */
  uint32_t  AMSEL;                             /*!< GPIO Analog Mode Select                                               */
  uint32_t  PCTL;                              /*!< GPIO Port Control                                                     */
  uint32_t  ADCCTL;                            /*!< GPIO ADC Control                                                      */
  uint32_t  DMACTL;                            /*!< GPIO DMA Control                                                      */
} GPIO_Type;


extern void GPIO_init(GPIO_Type * PORT, uint8_t pinNumber,PinDirection_t direction,PinPullUpAndDown_t pullUpDown);
extern void GPIO_write(GPIO_Type * PORT, uint8_t pinNumber,PinState_t state);
extern PinState_t GPIO_read(GPIO_Type * PORT, uint8_t pinNumber);

#endif /* GPIO_H_ */
