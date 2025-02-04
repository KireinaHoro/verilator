// -*- mode: C++; c-file-style: "cc-mode" -*-
//*************************************************************************
// DESCRIPTION: Verilator: Break always into sensitivity inst domains
//
// Code available from: https://verilator.org
//
//*************************************************************************
//
// Copyright 2003-2023 by Wilson Snyder. This program is free software; you
// can redistribute it and/or modify it under the terms of either the GNU
// Lesser General Public License Version 3 or the Perl Artistic License
// Version 2.0.
// SPDX-License-Identifier: LGPL-3.0-only OR Artistic-2.0
//
//*************************************************************************

#ifndef VERILATOR_V3INST_H_
#define VERILATOR_V3INST_H_

#include "config_build.h"
#include "verilatedos.h"

#include "V3ThreadSafety.h"

class AstAssignW;
class AstCell;
class AstNetlist;
class AstPin;

//============================================================================

class V3Inst final {
public:
    static void instAll(AstNetlist* nodep) VL_MT_DISABLED;
    static void dearrayAll(AstNetlist* nodep) VL_MT_DISABLED;
    static AstAssignW* pinReconnectSimple(AstPin* pinp, AstCell* cellp, bool forTristate,
                                          bool alwaysCvt = false) VL_MT_DISABLED;
    static void checkOutputShort(AstPin* nodep) VL_MT_DISABLED;
};

#endif  // Guard
