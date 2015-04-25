/*
 * =====================================================================================
 *
 *       Filename:  ahsm_switch.h
 *
 *    Description:  Andy Hierarchy State Machine
 *
 *                  state switcher
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

#ifndef _AHSM_SWITCH_H
#define _AHSM_SWITCH_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int ahsm_switch_cb_func_t (void *p_arg, void *p_data);

/**
 * switcher callback handler 
 */
struct ahsm_switch_hdlr {

    ahsm_switch_cb_func_t    *p_hdlr_cb;
};

struct ahsm_switch
{	
    /**
     * attribute 
     */

    /* switcher name */
    const char *p_name;

    /* current switch index */
    int        switch_idx;

    /** switch cnt max */
    int        switch_cnt_max;

    /* hdlr table */
    struct ahsm_switch_hdlr *p_hdlr_tbl;
};

int ahsm_switch_in_order (struct ahsm_switch *p_this, void *p_arg, void *p_data);

int ahsm_switch_casual (struct ahsm_switch *p_this, int dst_idx, void *p_arg, void *p_data);

void ahsm_switch_ctor (struct ahsm_switch      *p_this,
	               const char              *p_name,
		       struct ahsm_switch_hdlr *p_hdlr_tbl, 
		       int                      content_num_max);


#ifdef __cplusplus
}
#endif

#endif /* _AHSM_SWITCH_H */

/* end of file */
