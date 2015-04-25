/*
 * =====================================================================================
 *
 *       Filename:  ahsm_trans.c
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

#include "ahsm_trans.h"

int ahsm_trans_evt_trigger (struct ahsm_trans *p_this, void *p_src_data, void *p_target_data) {

    return p_this->pfn_evt_trigger(p_this, p_src_data, p_target_data);
}

void ahsm_action_trans (struct ahsm_trans *p_this, void	*p_src_data, void *p_target_data) {

    /* Source State Exit */
    ahsm_state_action_exit(p_this->p_src, p_src_data);
	
    /* Target State Entry */
    ahsm_state_action_entry(p_this->p_target, p_target_data);
}

void ahsm_trans_ctor (struct ahsm_trans *p_this, 
	              struct ahsm_state *p_src, 
		      struct ahsm_state *p_target,
		      ahsm_trans_func_t *p_trigger)
{
    p_this->p_src    = p_src;
    p_this->p_target = p_target;

    p_this->pfn_evt_trigger = p_trigger;
}
