/*
 * =====================================================================================
 *
 *       Filename:  ahsm_trans.h
 *
 *    Description:  Andy Hierarchy State Machine
 *
 *        Version:  1.0
 *        Created:  04/21/2015 04:50:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy.S.Y.Chen <andysychen@gmail.com>
 *   Organization:  Individual
 *
 * =====================================================================================
 */
#ifndef _AHSM_TRANS_H
#define _AHSM_TRANS_H

#include "ahsm_state.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ahsm_trans
{	
    /**
     * attribute 
     */

    /* source state */
    struct ahsm_state *p_src;

    /* target state */
    struct ahsm_state *p_target;

    /**
     * Operation 
     */

    /* state transition trigger */
    int (*pfn_evt_trigger) (struct ahsm_trans *p_this, void *p_src_data, void *p_target_data);

};

typedef int ahsm_trans_func_t (struct ahsm_trans *p_this, void *p_src_data, void *p_target_data); 

int ahsm_trans_evt_trigger (struct ahsm_trans *p_this, void *p_src_data, void *p_target_data); 

void ahsm_action_trans (struct ahsm_trans *p_this, void	*p_src_data, void *p_target_data); 
 
void ahsm_trans_ctor (struct ahsm_trans *p_this, 
	              struct ahsm_state *p_src, 
		      struct ahsm_state *p_target,
		      ahsm_trans_func_t *p_trigger); 

#ifdef __cplusplus
}
#endif


#endif /* __AHSM_TRANS_H */

/* end of file */
