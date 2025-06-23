/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Google, Inc.
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM hmbird

#if !defined(_TRACE_HMBIRD_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HMBIRD_H

#include <linux/tracepoint.h>

#define MAX_FATAL_INFO (64)

TRACE_EVENT(scx_fatal_info,

	TP_PROTO(unsigned int type, int pe, int lnr, int bnr, char *info),

	TP_ARGS(type, pe, lnr, bnr, info),

	TP_STRUCT__entry(
		__field(unsigned int, type)
		__field(int, pe)
		__field(int, lnr)
		__field(int, bnr)
		__array(char, info, MAX_FATAL_INFO)
	),

	TP_fast_assign(
		__entry->type = type;
		__entry->pe = pe;
		__entry->lnr = lnr;
		__entry->bnr = bnr;
		memcpy(__entry->info, info, MAX_FATAL_INFO);
	),

	TP_printk("scx fatal error type=%u pe=%d lnr=%d bnr=%d info=%s",
		__entry->type, __entry->pe, __entry->lnr, __entry->bnr,
		__entry->info)
);

#endif /* _TRACE_HMBIRD_H */

/* This part must be outside protection */
#include <trace/define_trace.h>