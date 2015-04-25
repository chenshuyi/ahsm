/*
 * =====================================================================================
 *
 *       Filename:  ahsm_switch.c
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
#include "ahsm_switch.h"

int ahsm_switch_in_order (struct ahsm_switch *p_this, void *p_arg, void *p_data) 
{

    if (p_this->switch_idx >= p_this->switch_cnt_max - 1) {

        p_this->switch_idx = -1;
    }

    return p_this->p_hdlr_tbl[p_this->switch_idx++].p_hdlr_cb (p_arg, p_data);
}

int ahsm_switch_casual (struct ahsm_switch *p_this, int dst_idx, void *p_arg, void *p_data)
{

    if (dst_idx < 0 || dst_idx > p_this->switch_cnt_max) {

        printf ("The switcher %s : dst idx is out of range. \n", p_this->p_name);
    
	return -1;	
    }

    p_this->switch_idx = dst_idx;
    
    return p_this->p_hdlr_tbl[p_this->switch_idx].p_hdlr_cb (p_arg, p_data);
}

void switcher_ctor (struct ahsm_switch      *p_this, 
	            const char              *p_name,
                    struct ahsm_switch_hdlr *p_hdlr_tbl, 
                    int                      content_num_max)
{

    p_this->switch_idx     = 0;
    p_this->p_name         = p_name;
    p_this->switch_cnt_max = content_num_max;
    p_this->p_hdlr_tbl     = p_hdlr_tbl;
}

