/*
 * =====================================================================================
 *
 *       Filename:  ahsm_state.c
 *
 *    Description:  Andy Hierarchy State Machine
 *
 *        Version:  1.0
 *        Created:  04/21/2015 04:46:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy.S.Y.Chen <andysychen@gmail.com> 
 *   Organization:  Individual
 *
 * =====================================================================================
 */

#include "ahsm_state.h"

int ahsm_state_action_entry (struct ahsm_state *p_this, void *p_data) {
	
    return p_this->pfn_action_entry (p_this, p_data);
}

int ahsm_state_action_exit (struct ahsm_state *p_this,void *p_data) {
	 
    return p_this->pfn_action_exit (p_this, p_data);
}

int ahsm_state_internal_transition (struct ahsm_state *p_this, void *p_data) {

    return p_this->pfn_internal_transition (p_this, p_data);
}

int ahsm_state_ctor (struct ahsm_state  *p_this,
	             const char         *p_name,
		     ahsm_state_func_t  *p_entry,
		     ahsm_state_func_t  *p_exit, 
		     ahsm_state_func_t  *p_trans)
{

    p_this->p_name                  = p_name;

    p_this->pfn_action_entry        = p_entry;
    p_this->pfn_action_exit         = p_exit;
    p_this->pfn_internal_transition = p_trans;
}
