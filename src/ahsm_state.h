/*
 * =====================================================================================
 *
 *       Filename:  ahsm_state.h
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
#ifndef _AHSM_STATE_H
#define _AHSM_STATE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ahsm_state {
    
    /**
     * attribute 
     */

    /* state name */
    const char *p_name;

    /* statu */
    int         statu;

    /**
     * operation 
     */
    
    /* entry action */
    int (*pfn_action_entry) (struct ahsm_state *p_this, void *p_data);

    /* exit action */
    int (*pfn_action_exit) (struct ahsm_state *p_this, void *p_data);

    /* internal transition */
    int (*pfn_internal_transition) (struct ahsm_state *p_this, void *p_data);

};

typedef int ahsm_state_func_t (struct ahsm_state *p_this, void *p_data); 

int ahsm_state_action_entry (struct ahsm_state *p_this, void *p_data); 
	
int ahsm_state_action_exit (struct ahsm_state *p_this,void *p_data); 
	 
int ahsm_state_internal_transition (struct ahsm_state *p_this, void *p_data); 

int ahsm_state_ctor (struct ahsm_state  *p_this,
	             const char         *p_name,
		     ahsm_state_func_t  *p_entry,
		     ahsm_state_func_t  *p_exit, 
		     ahsm_state_func_t  *p_trans);

#ifdef __cplusplus
}
#endif


#endif /* _AHSM_STATE_H */

/* end of file */
