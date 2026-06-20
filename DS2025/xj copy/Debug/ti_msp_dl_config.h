/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA1
#define PWM_0_INST_IRQHandler                                   TIMA1_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA1_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_2
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM15)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM15_PF_TIMA1_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOB
#define GPIO_PWM_0_C1_PIN                                          DL_GPIO_PIN_3
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM16)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM16_PF_TIMA1_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1249U)




/* Defines for PIN_1: GPIOA.0 with pinCMx 1 on package pin 33 */
#define GPIO_GRP_XJ_PIN_1_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_1_PIN                                    (DL_GPIO_PIN_0)
#define GPIO_GRP_XJ_PIN_1_IOMUX                                   (IOMUX_PINCM1)
/* Defines for PIN_2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_GRP_XJ_PIN_2_PORT                                           (GPIOB)
#define GPIO_GRP_XJ_PIN_2_PIN                                   (DL_GPIO_PIN_17)
#define GPIO_GRP_XJ_PIN_2_IOMUX                                  (IOMUX_PINCM43)
/* Defines for PIN_3: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_GRP_XJ_PIN_3_PORT                                           (GPIOB)
#define GPIO_GRP_XJ_PIN_3_PIN                                   (DL_GPIO_PIN_16)
#define GPIO_GRP_XJ_PIN_3_IOMUX                                  (IOMUX_PINCM33)
/* Defines for PIN_4: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_GRP_XJ_PIN_4_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_4_PIN                                   (DL_GPIO_PIN_12)
#define GPIO_GRP_XJ_PIN_4_IOMUX                                  (IOMUX_PINCM34)
/* Defines for PIN_5: GPIOA.8 with pinCMx 19 on package pin 54 */
#define GPIO_GRP_XJ_PIN_5_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_5_PIN                                    (DL_GPIO_PIN_8)
#define GPIO_GRP_XJ_PIN_5_IOMUX                                  (IOMUX_PINCM19)
/* Defines for PIN_6: GPIOA.9 with pinCMx 20 on package pin 55 */
#define GPIO_GRP_XJ_PIN_6_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_6_PIN                                    (DL_GPIO_PIN_9)
#define GPIO_GRP_XJ_PIN_6_IOMUX                                  (IOMUX_PINCM20)
/* Defines for PIN_7: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GPIO_GRP_XJ_PIN_7_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_7_PIN                                   (DL_GPIO_PIN_27)
#define GPIO_GRP_XJ_PIN_7_IOMUX                                  (IOMUX_PINCM60)
/* Defines for PIN_8: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_GRP_XJ_PIN_8_PORT                                           (GPIOA)
#define GPIO_GRP_XJ_PIN_8_PIN                                   (DL_GPIO_PIN_15)
#define GPIO_GRP_XJ_PIN_8_IOMUX                                  (IOMUX_PINCM37)
/* Port definition for Pin Group GPIO_Motor */
#define GPIO_Motor_PORT                                                  (GPIOA)

/* Defines for PIN_MR_AIN1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GPIO_Motor_PIN_MR_AIN1_PIN                              (DL_GPIO_PIN_14)
#define GPIO_Motor_PIN_MR_AIN1_IOMUX                             (IOMUX_PINCM36)
/* Defines for PIN_MR_AIN2: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_Motor_PIN_MR_AIN2_PIN                              (DL_GPIO_PIN_13)
#define GPIO_Motor_PIN_MR_AIN2_IOMUX                             (IOMUX_PINCM35)
/* Defines for PIN_MR_BIN1: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_Motor_PIN_MR_BIN1_PIN                              (DL_GPIO_PIN_16)
#define GPIO_Motor_PIN_MR_BIN1_IOMUX                             (IOMUX_PINCM38)
/* Defines for PIN_MR_BIN2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_Motor_PIN_MR_BIN2_PIN                              (DL_GPIO_PIN_17)
#define GPIO_Motor_PIN_MR_BIN2_IOMUX                             (IOMUX_PINCM39)
/* Defines for PIN_Counter: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_GRP_Switch_PIN_Counter_PORT                                 (GPIOB)
// groups represented: ["ENCODERB","GPIO_GRP_Switch"]
// pins affected: ["E2A","E2B","PIN_Counter"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_GRP_Switch_PIN_Counter_IIDX                     (DL_GPIO_IIDX_DIO8)
#define GPIO_GRP_Switch_PIN_Counter_PIN                          (DL_GPIO_PIN_8)
#define GPIO_GRP_Switch_PIN_Counter_IOMUX                        (IOMUX_PINCM25)
/* Defines for PIN_confirm: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_GRP_Switch_PIN_confirm_PORT                                 (GPIOA)
// groups represented: ["ENCODERA","GPIO_GRP_Switch"]
// pins affected: ["E1A","E1B","PIN_confirm"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_GRP_Switch_PIN_confirm_IIDX                     (DL_GPIO_IIDX_DIO7)
#define GPIO_GRP_Switch_PIN_confirm_PIN                          (DL_GPIO_PIN_7)
#define GPIO_GRP_Switch_PIN_confirm_IOMUX                        (IOMUX_PINCM14)
/* Defines for PIN_LED1: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_GRP_LED_PIN_LED1_PORT                                       (GPIOA)
#define GPIO_GRP_LED_PIN_LED1_PIN                               (DL_GPIO_PIN_22)
#define GPIO_GRP_LED_PIN_LED1_IOMUX                              (IOMUX_PINCM47)
/* Defines for PIN_LED2: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_GRP_LED_PIN_LED2_PORT                                       (GPIOB)
#define GPIO_GRP_LED_PIN_LED2_PIN                                (DL_GPIO_PIN_6)
#define GPIO_GRP_LED_PIN_LED2_IOMUX                              (IOMUX_PINCM23)
/* Defines for PIN_LED3: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_GRP_LED_PIN_LED3_PORT                                       (GPIOB)
#define GPIO_GRP_LED_PIN_LED3_PIN                                (DL_GPIO_PIN_9)
#define GPIO_GRP_LED_PIN_LED3_IOMUX                              (IOMUX_PINCM26)
/* Port definition for Pin Group ENCODERA */
#define ENCODERA_PORT                                                    (GPIOA)

/* Defines for E1A: GPIOA.25 with pinCMx 55 on package pin 26 */
#define ENCODERA_E1A_IIDX                                   (DL_GPIO_IIDX_DIO25)
#define ENCODERA_E1A_PIN                                        (DL_GPIO_PIN_25)
#define ENCODERA_E1A_IOMUX                                       (IOMUX_PINCM55)
/* Defines for E1B: GPIOA.26 with pinCMx 59 on package pin 30 */
#define ENCODERA_E1B_IIDX                                   (DL_GPIO_IIDX_DIO26)
#define ENCODERA_E1B_PIN                                        (DL_GPIO_PIN_26)
#define ENCODERA_E1B_IOMUX                                       (IOMUX_PINCM59)
/* Port definition for Pin Group ENCODERB */
#define ENCODERB_PORT                                                    (GPIOB)

/* Defines for E2A: GPIOB.20 with pinCMx 48 on package pin 19 */
#define ENCODERB_E2A_IIDX                                   (DL_GPIO_IIDX_DIO20)
#define ENCODERB_E2A_PIN                                        (DL_GPIO_PIN_20)
#define ENCODERB_E2A_IOMUX                                       (IOMUX_PINCM48)
/* Defines for E2B: GPIOB.24 with pinCMx 52 on package pin 23 */
#define ENCODERB_E2B_IIDX                                   (DL_GPIO_IIDX_DIO24)
#define ENCODERB_E2B_PIN                                        (DL_GPIO_PIN_24)
#define ENCODERB_E2B_IOMUX                                       (IOMUX_PINCM52)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
