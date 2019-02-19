/*
***********************************************************************
* COPYRIGHT AND WARRANTY INFORMATION
*
* Copyright 2001, International Telecommunications Union, Geneva
*
* DISCLAIMER OF WARRANTY
*
* These software programs are available to the user without any
* license fee or royalty on an "as is" basis. The ITU disclaims
* any and all warranties, whether express, implied, or
* statutory, including any implied warranties of merchantability
* or of fitness for a particular purpose.  In no event shall the
* contributor or the ITU be liable for any incidental, punitive, or
* consequential damages of any kind whatsoever arising from the
* use of these programs.
*
* This disclaimer of warranty extends to the user of these programs
* and user's customers, employees, agents, transferees, successors,
* and assigns.
*
* The ITU does not represent or warrant that the programs furnished
* hereunder are free of infringement of any third-party patents.
* Commercial implementations of ITU-T Recommendations, including
* shareware, may be subject to royalty fees to patent holders.
* Information regarding the ITU-T patent policy is available from
* the ITU Web site at http://www.itu.int.
*
* THIS IS NOT A GRANT OF PATENT RIGHTS - SEE THE ITU-T PATENT POLICY.
************************************************************************
*/


/*!
 *************************************************************************************
 *
 * \file me_umhexsmp.h
 *
 * \brief
 *   Fast integer pixel and sub pixel motion estimation
 *   Improved and simplified from the original UMHexagonS algorithms
 *   See JVT-P021 for details
 *
 * \author
 *    Main contributors: (see contributors.h for copyright, address and affiliation details)
 *    - Zhibo Chen                      <chenzhibo@tsinghua.org.cn>
 *    - JianFeng Xu                     <fenax@video.mdc.tsinghua.edu.cn>
 *    - Wenfang Fu                      <fwf@video.mdc.tsinghua.edu.cn>
 *
 *    - Xiaoquan Yi                     <xyi@engr.scu.edu>
 *    - Jun Zhang                       <jzhang2@engr.scu.edu>
 *
 * \date
 *    6. Nov. 2006
 *************************************************************************************
 */

#ifndef _ME_UMHEXSMP_H_
#define _ME_UMHEXSMP_H_

#include "mbuffer.h"

struct umhex_smp_struct
{
    distblk  SymmetricalCrossSearchThreshold1;
    distblk  SymmetricalCrossSearchThreshold2;
    distblk  ConvergeThreshold;
    distblk  SubPelThreshold1;
    distblk  SubPelThreshold3;
    byte  **SearchState;          //state for fractional pel search
    distblk  ***l0_cost;       //store SAD information needed for forward median and uplayer prediction
    distblk  ***l1_cost;       //store SAD information needed for backward median and uplayer prediction
    distblk   pred_SAD_uplayer;     // Up layer SAD prediction
    byte   *flag_intra;
    int     flag_intra_SAD;

    short   pred_MV_uplayer_X;    // Up layer MV predictor X-component
    short   pred_MV_uplayer_Y;    // Up layer MV predictor Y-component
};

typedef struct umhex_smp_struct UMHexSMPStruct;

extern void    smpUMHEX_init(VideoParameters *p_Vid);
extern int     smpUMHEX_get_mem(VideoParameters *p_Vid);
extern void    smpUMHEX_free_mem(VideoParameters *p_Vid);
extern void    smpUMHEX_decide_intrabk_SAD(Macroblock *currMB);
extern void    smpUMHEX_skip_intrabk_SAD(Macroblock *currMB);
extern void    smpUMHEX_setup(Macroblock *currMB, short, int, int, int, int, MotionVector *****);
extern distblk smpUMHEXBipredIntegerPelBlockMotionSearch(Macroblock *, int, MotionVector *, MotionVector *, MotionVector *, MotionVector *, MEBlock *, int, distblk, int);
extern distblk smpUMHEXIntegerPelBlockMotionSearch(Macroblock *currMB, MotionVector *pred_mv, MEBlock *mv_block, distblk min_mcost, int lambda_factor);
extern distblk smpUMHEXSubPelBlockMotionSearch(Macroblock *currMB, MotionVector *pred_mv, MEBlock *mv_block, distblk min_mcost, int lambda_factor);
extern distblk smpUMHEXFullSubPelBlockMotionSearch(Macroblock *currMB, MotionVector *pred_mv, MEBlock *mv_block, distblk min_mcost, int lambda_factor);
extern distblk smpUMHEXSubPelBlockME(Macroblock *currMB, MotionVector *pred_mv, MEBlock *mv_block, distblk min_mcost, int *lambda);
#endif
