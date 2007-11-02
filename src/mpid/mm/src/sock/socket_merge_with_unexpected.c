/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
#include "socketimpl.h"

#ifdef WITH_METHOD_SOCKET

int socket_merge_with_unexpected(MM_Car *posted_car_ptr, MM_Car *unex_car_ptr)
{
    int num_left, num_updated;
    char *unex_data_ptr;
    int bMoreData = FALSE;
    MPIDI_STATE_DECL(MPID_STATE_SOCKET_MERGE_WITH_UNEXPECTED);

    MPIDI_FUNC_ENTER(MPID_STATE_SOCKET_MERGE_WITH_UNEXPECTED);

    /* copy the unexpected packet into the posted packet */
    posted_car_ptr->msg_header.pkt = unex_car_ptr->msg_header.pkt;

    /* move to the data car */
    unex_car_ptr = unex_car_ptr->next_ptr;
    /* get the tmp buffer and number of bytes read */
    num_left = unex_car_ptr->buf_ptr->tmp.num_read;
    unex_data_ptr = unex_car_ptr->buf_ptr->tmp.buf;

    if (unex_car_ptr->buf_ptr->tmp.num_read != unex_car_ptr->buf_ptr->tmp.len)
    {
	/* if the message is still being read then change to the reading_data state */
	/*posted_car_ptr->vc_ptr->data.socket.read = socket_read_data;*/
	bMoreData = TRUE;
    }

    /* mark the head car as completed */
    /*printf("dec cc: read eager head car\n");fflush(stdout);*/
    mm_dec_cc_atomic(posted_car_ptr->request_ptr);
    posted_car_ptr = posted_car_ptr->next_ptr;
    while (num_left)
    {
	num_updated = posted_car_ptr->vc_ptr->fn.merge_unexpected_data(posted_car_ptr->vc_ptr, posted_car_ptr, unex_data_ptr, num_left);
	num_left -= num_updated;
	unex_data_ptr += num_updated;
	if (num_left == 0 && bMoreData)
	{
	    /* post a read of the remaining data */
	    socket_read_data(posted_car_ptr->vc_ptr);
	}
	posted_car_ptr = posted_car_ptr->next_ptr;
    }

    /* free the temporary buffer and request */
    mm_request_free(unex_car_ptr->request_ptr);

    MPIDI_FUNC_EXIT(MPID_STATE_SOCKET_MERGE_WITH_UNEXPECTED);
    return MPI_SUCCESS;
}

#endif
