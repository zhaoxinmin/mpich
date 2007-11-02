/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
#include "via_rdmaimpl.h"

#ifdef WITH_METHOD_VIA_RDMA

int via_rdma_post_connect(MPIDI_VC *vc_ptr, char *business_card)
{
    MPIDI_STATE_DECL(MPID_STATE_VIA_RDMA_POST_CONNECT);
    MPIDI_FUNC_ENTER(MPID_STATE_VIA_RDMA_POST_CONNECT);
    MPIDI_FUNC_EXIT(MPID_STATE_VIA_RDMA_POST_CONNECT);
    return MPI_SUCCESS;
}

#endif
