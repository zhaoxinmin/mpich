/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "mpidimpl.h"

int MPID_Accumulate(void *origin_addr, int origin_count, MPI_Datatype
                    origin_datatype, int target_rank, MPI_Aint target_disp,
                    int target_count, MPI_Datatype target_datatype, MPI_Op op,
                    MPID_Win *win_ptr)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_STATE_DECL(MPID_STATE_MPI_ACCUMULATE);

    MPIDI_RMA_FUNC_ENTER(MPID_STATE_MPI_ACCUMULATE);

    MPIDI_RMA_FUNC_EXIT(MPID_STATE_MPI_ACCUMULATE);

    return mpi_errno;
}
