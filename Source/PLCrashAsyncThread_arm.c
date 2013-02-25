/*
 * Author: Landon Fuller <landonf@plausiblelabs.com>
 *
 * Copyright (c) 2008-2013 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import "PLCrashAsyncThread.h"
#import "PLCrashAsync.h"

#import <signal.h>
#import <stdlib.h>
#import <assert.h>

#ifdef __arm__

#define RETGEN(name, type, ts) {\
    return (ts->arm_state. type . __ ## name); \
}

#define SETGEN(name, type, ts, value) {\
    (ts->arm_state. type . __ ## name) = value; \
    break; \
}

// PLCrashAsyncThread API
plcrash_greg_t plcrash_async_thread_state_get_reg (plcrash_async_thread_state_t *ts, plcrash_regnum_t regnum) {
    switch (regnum) {
        case PLCRASH_ARM_R0:
            RETGEN(r[0], thread, ts);
            
        case PLCRASH_ARM_R1:
            RETGEN(r[1], thread, ts);
            
        case PLCRASH_ARM_R2:
            RETGEN(r[2], thread, ts);
            
        case PLCRASH_ARM_R3:
            RETGEN(r[3], thread, ts);
            
        case PLCRASH_ARM_R4:
            RETGEN(r[4], thread, ts);
            
        case PLCRASH_ARM_R5:
            RETGEN(r[5], thread, ts);
            
        case PLCRASH_ARM_R6:
            RETGEN(r[6], thread, ts);
            
        case PLCRASH_ARM_R7:
            RETGEN(r[7], thread, ts);
            
        case PLCRASH_ARM_R8:
            RETGEN(r[8], thread, ts);
            
        case PLCRASH_ARM_R9:
            RETGEN(r[9], thread, ts);
            
        case PLCRASH_ARM_R10:
            RETGEN(r[10], thread, ts);
            
        case PLCRASH_ARM_R11:
            RETGEN(r[11], thread, ts);
            
        case PLCRASH_ARM_R12:
            RETGEN(r[12], thread, ts);
            
        case PLCRASH_ARM_SP:
            RETGEN(sp, thread, ts);
            
        case PLCRASH_ARM_LR:
            RETGEN(lr, thread, ts);
            
        case PLCRASH_ARM_PC:
            RETGEN(pc, thread, ts);
            
        case PLCRASH_ARM_CPSR:
            RETGEN(cpsr, thread, ts);
            
        default:
            __builtin_trap();
    }

    /* Should not be reachable */
    return 0;
}

// PLCrashAsyncThread API
void plcrash_async_thread_state_set_reg (plcrash_async_thread_state_t *thread_state, plcrash_regnum_t regnum, plcrash_greg_t reg) {
    plcrash_async_thread_state_t *ts = thread_state;

    switch (regnum) {
        case PLCRASH_ARM_R0:
            SETGEN(r[0], thread, ts, reg);
            
        case PLCRASH_ARM_R1:
            SETGEN(r[1], thread, ts, reg);
            
        case PLCRASH_ARM_R2:
            SETGEN(r[2], thread, ts, reg);
            
        case PLCRASH_ARM_R3:
            SETGEN(r[3], thread, ts, reg);
            
        case PLCRASH_ARM_R4:
            SETGEN(r[4], thread, ts, reg);
            
        case PLCRASH_ARM_R5:
            SETGEN(r[5], thread, ts, reg);
            
        case PLCRASH_ARM_R6:
            SETGEN(r[6], thread, ts, reg);
            
        case PLCRASH_ARM_R7:
            SETGEN(r[7], thread, ts, reg);
            
        case PLCRASH_ARM_R8:
            SETGEN(r[8], thread, ts, reg);
            
        case PLCRASH_ARM_R9:
            SETGEN(r[9], thread, ts, reg);
            
        case PLCRASH_ARM_R10:
            SETGEN(r[10], thread, ts, reg);
            
        case PLCRASH_ARM_R11:
            SETGEN(r[11], thread, ts, reg);
            
        case PLCRASH_ARM_R12:
            SETGEN(r[12], thread, ts, reg);
            
        case PLCRASH_ARM_SP:
            SETGEN(sp, thread, ts, reg);
            
        case PLCRASH_ARM_LR:
            SETGEN(lr, thread, ts, reg);
            
        case PLCRASH_ARM_PC:
            SETGEN(pc, thread, ts, reg);
            
        case PLCRASH_ARM_CPSR:
            SETGEN(cpsr, thread, ts, reg);
            
        default:
            // Unsupported register
            __builtin_trap();
    }
}

// PLCrashAsyncThread API
size_t plcrash_async_thread_state_get_reg_count (plcrash_async_thread_state_t *thread_state) {
    /* Last is an index value, so increment to get the count */
    return PLCRASH_ARM_LAST_REG+1;
}

// PLCrashAsyncThread API
char const *plcrash_async_thread_state_get_reg_name (plcrash_async_thread_state_t *thread_state, plcrash_regnum_t regnum) {
    switch (regnum) {
        case PLCRASH_ARM_R0:
            return "r0";
        case PLCRASH_ARM_R1:
            return "r1";
        case PLCRASH_ARM_R2:
            return "r2";
        case PLCRASH_ARM_R3:
            return "r3";
        case PLCRASH_ARM_R4:
            return "r4";
        case PLCRASH_ARM_R5:
            return "r5";
        case PLCRASH_ARM_R6:
            return "r6";
        case PLCRASH_ARM_R7:
            return "r7";
        case PLCRASH_ARM_R8:
            return "r8";
        case PLCRASH_ARM_R9:
            return "r9";
        case PLCRASH_ARM_R10:
            return "r10";
        case PLCRASH_ARM_R11:
            return "r11";
        case PLCRASH_ARM_R12:
            return "r12";
            
        case PLCRASH_ARM_SP:
            return "sp";
            
        case PLCRASH_ARM_LR:
            return "lr";
            
        case PLCRASH_ARM_PC:
            return "pc";
            
        case PLCRASH_ARM_CPSR:
            return "cpsr";
            
        default:
            // Unsupported register
            break;
    }
    
    /* Unsupported register is an implementation error (checked in unit tests) */
    PLCF_DEBUG("Missing register name for register id: %d", regnum);
    abort();
}

#endif /* __arm__ */
