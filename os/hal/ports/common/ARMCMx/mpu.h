/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    common/ARMCMx/mpu.h
 * @brief   Cortex-Mx MPU support macros and structures.
 *
 * @addtogroup COMMON_ARMCMx_MPU
 * @{
 */

#ifndef _MPU_H_
#define _MPU_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    MPU registers definitions
 * @{
 */
#define MPU_CTRL_ENABLE                     (1U << 0U)
#define MPU_CTRL_HFNMIENA                   (1U << 1U)
#define MPU_CTRL_PRIVDEFENA                 (1U << 2U)

#define MPU_RNR_REGION_MASK                 (255U << 0U)
#define MPU_RNR_REGION(n)                   ((n) << 0U)

#define MPU_RBAR_REGION_MASK                (15U << 0U)
#define MPU_RBAR_REGION(n)                  ((n) << 0U)
#define MPU_RBAR_VALID                      (1U << 4U)
#define MPU_RBAR_ADDR_MASK                  0xFFFFFFE0U
#define MPU_RBAR_ADDR(n)                    ((n) << 5U)

#define MPU_RASR_ENABLE                     (1U << 0U)
#define MPU_RASR_SIZE_MASK                  (31U << 1U)
#define MPU_RASR_SIZE(n)                    ((n) << 1U)
#define MPU_RASR_SIZE_32                    MPU_RASR_SIZE(4U)
#define MPU_RASR_SIZE_64                    MPU_RASR_SIZE(5U)
#define MPU_RASR_SIZE_128                   MPU_RASR_SIZE(6U)
#define MPU_RASR_SIZE_256                   MPU_RASR_SIZE(7U)
#define MPU_RASR_SIZE_512                   MPU_RASR_SIZE(8U)
#define MPU_RASR_SIZE_1K                    MPU_RASR_SIZE(9U)
#define MPU_RASR_SIZE_2K                    MPU_RASR_SIZE(10U)
#define MPU_RASR_SIZE_4K                    MPU_RASR_SIZE(11U)
#define MPU_RASR_SIZE_8K                    MPU_RASR_SIZE(12U)
#define MPU_RASR_SIZE_16K                   MPU_RASR_SIZE(13U)
#define MPU_RASR_SIZE_32K                   MPU_RASR_SIZE(14U)
#define MPU_RASR_SIZE_64K                   MPU_RASR_SIZE(15U)
#define MPU_RASR_SIZE_128K                  MPU_RASR_SIZE(16U)
#define MPU_RASR_SIZE_256K                  MPU_RASR_SIZE(17U)
#define MPU_RASR_SIZE_512K                  MPU_RASR_SIZE(18U)
#define MPU_RASR_SIZE_1M                    MPU_RASR_SIZE(19U)
#define MPU_RASR_SIZE_2M                    MPU_RASR_SIZE(20U)
#define MPU_RASR_SIZE_4M                    MPU_RASR_SIZE(21U)
#define MPU_RASR_SIZE_8M                    MPU_RASR_SIZE(22U)
#define MPU_RASR_SIZE_16M                   MPU_RASR_SIZE(23U)
#define MPU_RASR_SIZE_32M                   MPU_RASR_SIZE(24U)
#define MPU_RASR_SIZE_64M                   MPU_RASR_SIZE(25U)
#define MPU_RASR_SIZE_128M                  MPU_RASR_SIZE(26U)
#define MPU_RASR_SIZE_256M                  MPU_RASR_SIZE(27U)
#define MPU_RASR_SIZE_512M                  MPU_RASR_SIZE(28U)
#define MPU_RASR_SIZE_1G                    MPU_RASR_SIZE(29U)
#define MPU_RASR_SIZE_2G                    MPU_RASR_SIZE(30U)
#define MPU_RASR_SIZE_4G                    MPU_RASR_SIZE(31U)
#define MPU_RASR_SRD_MASK                   (255U << 8U)
#define MPU_RASR_SRD(n)                     ((n) << 8U)
#define MPU_RASR_SRD_ALL                    (0U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB1           (1U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB2           (2U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB3           (4U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB4           (8U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB5           (16U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB6           (32U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB7           (64U << 8U)
#define MPU_RASR_SRD_DISABLE_SUB8           (128U << 8U)
#define MPU_RASR_ATTR_B                     (1U << 16U)
#define MPU_RASR_ATTR_C                     (1U << 17U)
#define MPU_RASR_ATTR_S                     (1U << 18U)
#define MPU_RASR_ATTR_TEX_MASK              (7U << 19U)
#define MPU_RASR_ATTR_TEX(n)                ((n) << 19U)
#define MPU_RASR_ATTR_AP_MASK               (7U << 24U)
#define MPU_RASR_ATTR_AP(n)                 ((n) << 24U)
#define MPU_RASR_ATTR_AP_NA_NA              (0U << 24U)
#define MPU_RASR_ATTR_AP_RW_NA              (1U << 24U)
#define MPU_RASR_ATTR_AP_RW_RO              (2U << 24U)
#define MPU_RASR_ATTR_AP_RW_RW              (3U << 24U)
#define MPU_RASR_ATTR_AP_RO_NA              (5U << 24U)
#define MPU_RASR_ATTR_AP_RO_RO              (6U << 24U)
#define MPU_RASR_ATTR_XN                    (1U << 28U)
/** @} */

/**
 * @name    Region attributes
 * @{
 */
#define MPU_RASR_ATTR_STRONGLY_ORDERED      (MPU_RASR_ATTR_TEX(0))
#define MPU_RASR_ATTR_SHARED_DEVICE         (MPU_RASR_ATTR_TEX(0) | MPU_RASR_ATTR_B)
#define MPU_RASR_ATTR_CACHEABLE_WT_NWA      (MPU_RASR_ATTR_TEX(0) | MPU_RASR_ATTR_C)
#define MPU_RASR_ATTR_CACHEABLE_WB_NWA      (MPU_RASR_ATTR_TEX(0) | MPU_RASR_ATTR_B | MPU_RASR_ATTR_C)
#define MPU_RASR_ATTR_NON_CACHEABLE         (MPU_RASR_ATTR_TEX(1))
#define MPU_RASR_ATTR_CACHEABLE_WB_WA       (MPU_RASR_ATTR_TEX(1) | MPU_RASR_ATTR_B | MPU_RASR_ATTR_C)
#define MPU_RASR_ATTR_NON_SHARED_DEVICE     (MPU_RASR_ATTR_TEX(2))
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif /* _MPU_H_ */

/** @} */